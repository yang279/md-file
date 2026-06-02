#define IMPLEMENT_KIWI_H
#define IMPLEMENT_SCHEMA_H
#include "kiwi.h"
#include "pixso.h"
#include "zstd.h"
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <string>

static std::vector<uint8_t> readFile(const char *p){
    FILE*f=fopen(p,"rb");if(!f)return{};
    fseek(f,0,SEEK_END);long s=ftell(f);fseek(f,0,SEEK_SET);
    std::vector<uint8_t>b(s);fread(b.data(),1,s,f);fclose(f);return b;
}
struct GK{
    uint32_t s=0,l=0;
    bool operator<(const GK&o)const{return s!=o.s?s<o.s:l<o.l;}
    std::string str()const{char b[32];snprintf(b,32,"{%u,%u}",s,l);return b;}
};
static GK gk(const GUID*g){
    if(!g)return{};
    return{g->sessionID()?*g->sessionID():0,g->localID()?*g->localID():0};
}
struct NI{
    GK guid,parent;
    std::string name,typeName;
    uint32_t typeVal=0;
    float w=0,h=0,tx=0,ty=0;
    GK symbolID;
    bool internalOnly=false;
};

static std::string typeName(uint32_t t){
    switch(t){
        case 2: return "DOCUMENT";
        case 3: return "CANVAS";
        case 5: return "FRAME";
        case 4: return "GROUP";
        case 16:return "SYMBOL";
        case 17:return "INSTANCE";
        case 14:return "TEXT";
        case 11:return "RECTANGLE";
        case 7: return "VECTOR";
        default:return "type("+std::to_string(t)+")";
    }
}

int main(int argc,char**argv){
    const char*path = argc>1 ? argv[1] : "instance_out.pix";
    auto raw=readFile(path);
    if(raw.empty()){fprintf(stderr,"cannot open %s\n",path);return 1;}

    size_t pos=8+2; uint8_t ml=raw[pos++]; pos+=ml;
    auto cs=ZSTD_getFrameContentSize(raw.data()+pos,raw.size()-pos);
    if(cs==ZSTD_CONTENTSIZE_UNKNOWN||cs==ZSTD_CONTENTSIZE_ERROR)cs=raw.size()*8;
    std::vector<uint8_t>dec(cs);
    dec.resize(ZSTD_decompress(dec.data(),cs,raw.data()+pos,raw.size()-pos));

    kiwi::ByteBuffer bb(dec.data(),dec.size());
    kiwi::MemoryPool pool; PixsoMsg msg; msg.decode(bb,pool);
    auto*nodes=msg.pixsoNodes();
    if(!nodes){printf("no nodes\n");return 0;}

    int msgType = msg.type()?(int)*msg.type():-1;
    printf("PixsoMsg.type = %d  (%s)\n", msgType,
        msgType==2?"NODE_CHANGES":msgType==16?"PIX_DOCUMENT":"?");
    printf("pixsoNodes 数量: %u\n\n", nodes->size());

    // 收集所有节点
    std::map<GK,NI> idx;
    for(uint32_t i=0;i<nodes->size();i++){
        const PixsoNode&n=(*nodes)[i];
        NI ni;
        ni.guid=gk(n.guid());
        ni.parent=gk(n.parentIndex()?n.parentIndex()->guid():nullptr);
        ni.name=n.name()?n.name()->c_str():"";
        ni.typeVal=n.type()?(uint32_t)*n.type():0;
        ni.typeName=typeName(ni.typeVal);
        if(n.size()){ni.w=n.size()->x()?*n.size()->x():0;ni.h=n.size()->y()?*n.size()->y():0;}
        if(n.transform()){ni.tx=n.transform()->m02()?*n.transform()->m02():0;
                          ni.ty=n.transform()->m12()?*n.transform()->m12():0;}
        if(n.symbolData()&&n.symbolData()->symbolID())
            ni.symbolID=gk(n.symbolData()->symbolID());
        if(n.internalOnly()&&*n.internalOnly())ni.internalOnly=true;
        idx[ni.guid]=ni;
    }

    // 建父→子映射
    std::map<GK,std::vector<GK>> children;
    std::vector<GK> roots; // 父节点不在本消息里的
    for(auto&[g,ni]:idx){
        children[ni.parent].push_back(g);
        if(!idx.count(ni.parent)) roots.push_back(g);
    }

    // 打印平铺列表
    printf("=== 所有节点（平铺）===\n");
    printf("%-8s %-22s %-22s %-10s %-8s %-5s %-5s  %s\n",
        "index","guid","parent","type","size","x","y","name");
    printf("%s\n",std::string(100,'-').c_str());
    for(uint32_t i=0;i<nodes->size();i++){
        const NI&ni=idx[gk((*nodes)[i].guid())];
        printf("%-8u %-22s %-22s %-10s %-8s %-5.0f %-5.0f  %s",
            i, ni.guid.str().c_str(), ni.parent.str().c_str(),
            ni.typeName.c_str(),
            (std::to_string((int)ni.w)+"x"+std::to_string((int)ni.h)).c_str(),
            ni.tx, ni.ty, ni.name.c_str());
        if(ni.symbolID.s||ni.symbolID.l)
            printf("  → symbolID=%s",ni.symbolID.str().c_str());
        if(ni.internalOnly) printf("  [internalOnly]");
        printf("\n");
    }

    // 打印树形（以各 root 的 parent 为虚拟根节点）
    printf("\n=== 树形结构 ===\n");

    std::function<void(GK,int)> printTree=[&](GK g,int d){
        auto it=idx.find(g);
        if(it==idx.end())return;
        const NI&ni=it->second;
        std::string indent(d*2,' ');
        printf("%s├─ [%-10s] %s  \"%s\"",
            indent.c_str(),ni.typeName.c_str(),ni.guid.str().c_str(),ni.name.c_str());
        if(ni.w>0||ni.h>0) printf("  size=%.0fx%.0f",ni.w,ni.h);
        if(ni.tx!=0||ni.ty!=0) printf("  pos=(%.0f,%.0f)",ni.tx,ni.ty);
        if(ni.symbolID.s||ni.symbolID.l) printf("  → symbolID=%s",ni.symbolID.str().c_str());
        if(ni.internalOnly) printf("  [internalOnly]");
        printf("\n");
        auto ci=children.find(g);
        if(ci!=children.end())
            for(auto&c:ci->second) printTree(c,d+1);
    };

    // 按 parent 分组打印（parent 不在消息里，作为虚拟容器）
    std::map<GK,std::vector<GK>> byParent;
    for(auto&g:roots) byParent[idx[g].parent].push_back(g);

    for(auto&[pg,gs]:byParent){
        printf("\n挂在父节点 %s 下的子树：\n", pg.str().c_str());
        for(auto&g:gs) printTree(g,0);
    }

    // 统计可见页 {0,1} 的直接子节点
    printf("\n=== 可见页 {0,1} 的直接子节点 ===\n");
    GK visPage={0,1};
    auto it=children.find(visPage);
    if(it!=children.end()){
        printf("共 %zu 个直接子节点：\n",(size_t)it->second.size());
        for(auto&c:it->second){
            const NI&ni=idx[c];
            printf("  [%-10s] %s  \"%s\"",ni.typeName.c_str(),c.str().c_str(),ni.name.c_str());
            if(ni.symbolID.s||ni.symbolID.l) printf("  → symbolID=%s",ni.symbolID.str().c_str());
            printf("\n");
        }
    } else {
        printf("（本消息里没有父节点为 {0,1} 的节点）\n");
    }

    printf("\n=== 隐藏页 {0,2} 的直接子节点 ===\n");
    GK hidPage={0,2};
    auto it2=children.find(hidPage);
    if(it2!=children.end()){
        printf("共 %zu 个直接子节点：\n",(size_t)it2->second.size());
        for(auto&c:it2->second){
            const NI&ni=idx[c];
            printf("  [%-10s] %s  \"%s\"\n",ni.typeName.c_str(),c.str().c_str(),ni.name.c_str());
        }
    } else {
        printf("（本消息里没有父节点为 {0,2} 的节点）\n");
    }

    return 0;
}
