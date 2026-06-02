#define IMPLEMENT_KIWI_H
#define IMPLEMENT_SCHEMA_H
#include "../../kiwi-master/kiwi.h"
#include "../../pixso.h"
#include "zstd.h"
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <algorithm>

static std::vector<uint8_t> readFile(const char *p) {
    FILE *f = fopen(p, "rb"); if (!f) return {};
    fseek(f, 0, SEEK_END); long s = ftell(f); fseek(f, 0, SEEK_SET);
    std::vector<uint8_t> b(s); fread(b.data(), 1, s, f); fclose(f);
    return b;
}

struct GK {
    uint32_t s=0,l=0;
    bool operator<(const GK&o)const{return s!=o.s?s<o.s:l<o.l;}
    bool isNull()const{return s==0&&l==0;}
};
static GK gk(const GUID*g){if(!g)return{};return{g->sessionID()?*g->sessionID():0,g->localID()?*g->localID():0};}
static std::string ss(const kiwi::String*s){return s?s->c_str():"";}

static std::vector<uint8_t> decompressPix(const std::vector<uint8_t>&raw){
    if(raw.size()<12||memcmp(raw.data(),"pixso-kw",8)!=0)return{};
    size_t pos=8+2; uint8_t ml=raw[pos++]; pos+=ml;
    auto cs=ZSTD_getFrameContentSize(raw.data()+pos,raw.size()-pos);
    if(cs==ZSTD_CONTENTSIZE_ERROR)return{};
    if(cs==ZSTD_CONTENTSIZE_UNKNOWN)cs=raw.size()*8;
    std::vector<uint8_t>out(cs);
    size_t r=ZSTD_decompress(out.data(),cs,raw.data()+pos,raw.size()-pos);
    if(ZSTD_isError(r))return{};
    out.resize(r); return out;
}

struct NR { GK guid,parent; uint32_t type=0; std::string name; bool isStateGroup=false; const PixsoNode*raw=nullptr; };

int main(int argc,char**argv){
    if(argc<2){fprintf(stderr,"Usage: diagnose <file.pix>\n");return 1;}
    auto raw=readFile(argv[1]);
    auto dec=decompressPix(raw);
    kiwi::MemoryPool pool; PixsoMsg msg;
    kiwi::ByteBuffer bb(dec.data(),dec.size());
    msg.decode(bb,pool);
    auto*nodes=msg.pixsoNodes(); if(!nodes)return 1;

    std::map<GK,NR> byGuid;
    std::map<GK,std::vector<GK>> children;

    for(uint32_t i=0;i<nodes->size();i++){
        const PixsoNode&n=(*nodes)[i];
        NR r;
        r.guid=gk(n.guid());
        r.parent=gk(n.parentIndex()?n.parentIndex()->guid():nullptr);
        r.type=n.type()?(uint32_t)*n.type():0;
        r.name=ss(n.name());
        r.isStateGroup=(n.isStateGroup()&&*n.isStateGroup());
        r.raw=&n;
        if(!r.guid.isNull()){byGuid[r.guid]=r;children[r.parent].push_back(r.guid);}
    }

    printf("=== 总节点数: %zu ===\n\n",byGuid.size());

    // 类型统计
    std::map<uint32_t,int> typeCnt;
    for(auto&[g,n]:byGuid) typeCnt[n.type]++;
    printf("=== 节点类型分布 ===\n");
    for(auto&[t,c]:typeCnt){
        const char*tn="?";
        switch(t){case 2:tn="DOCUMENT";break;case 3:tn="CANVAS";break;case 4:tn="GROUP";break;
                  case 5:tn="FRAME";break;case 14:tn="TEXT";break;case 11:tn="RECTANGLE";break;
                  case 7:tn="VECTOR";break;case 16:tn="SYMBOL";break;case 17:tn="INSTANCE";break;
                  case 104:tn="SECTION";break;}
        printf("  type=%-3u %-12s : %d\n",t,tn,c);
    }

    // CANVAS 列表及其直接子节点类型
    printf("\n=== CANVAS 页面列表 ===\n");
    for(auto&[g,n]:byGuid){
        if(n.type!=3)continue;
        bool hidden=(n.raw&&n.raw->internalOnly()&&*n.raw->internalOnly());
        auto&ch=children[g];
        std::map<uint32_t,int> childTypes;
        int sym=0,frame_sg=0,frame_ns=0,section=0,group=0,other=0;
        for(auto&cg:ch){
            auto&cn=byGuid[cg];
            if(cn.type==16)sym++;
            else if(cn.type==5&&cn.isStateGroup)frame_sg++;
            else if(cn.type==5)frame_ns++;
            else if(cn.type==104)section++;
            else if(cn.type==4)group++;
            else other++;
        }
        printf("  [%s] \"%s\"  直接子节点=%zu  (SYMBOL=%d FRAME_SG=%d FRAME=%d SECTION=%d GROUP=%d other=%d)\n",
               hidden?"hidden":"shown",n.name.c_str(),ch.size(),sym,frame_sg,frame_ns,section,group,other);
    }

    // SECTION 直接子节点分析（前10个）
    printf("\n=== SECTION 节点下的直接子类型（前10个SECTION）===\n");
    int secCnt=0;
    for(auto&[g,n]:byGuid){
        if(n.type!=104)continue;
        if(secCnt++>=10)break;
        auto&ch=children[g];
        int sym=0,frame_sg=0,frame_ns=0,other=0;
        for(auto&cg:ch){auto&cn=byGuid[cg];if(cn.type==16)sym++;else if(cn.type==5&&cn.isStateGroup)frame_sg++;else if(cn.type==5)frame_ns++;else other++;}
        printf("  SECTION \"%s\"  子节点=%zu  (SYMBOL=%d FRAME_SG=%d FRAME=%d other=%d)\n",
               n.name.c_str(),ch.size(),sym,frame_sg,frame_ns,other);
    }

    return 0;
}
