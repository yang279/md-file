#define IMPLEMENT_KIWI_H
#define IMPLEMENT_SCHEMA_H
#include "../../kiwi-master/kiwi.h"
#include "../../pixso.h"
#include "zstd.h"
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <string>

static std::vector<uint8_t> readFile(const char *p) {
    FILE *f = fopen(p,"rb"); if(!f)return{};
    fseek(f,0,SEEK_END);long s=ftell(f);fseek(f,0,SEEK_SET);
    std::vector<uint8_t>b(s);fread(b.data(),1,s,f);fclose(f);return b;
}
static std::string ss(const kiwi::String*s){return s?s->c_str():"";}

static std::vector<uint8_t> decompressPix(const std::vector<uint8_t>&raw){
    if(raw.size()<12||memcmp(raw.data(),"pixso-kw",8)!=0)return{};
    size_t pos=8+2;uint8_t ml=raw[pos++];pos+=ml;
    auto cs=ZSTD_getFrameContentSize(raw.data()+pos,raw.size()-pos);
    if(cs==ZSTD_CONTENTSIZE_UNKNOWN)cs=raw.size()*8;
    std::vector<uint8_t>out(cs);
    size_t r=ZSTD_decompress(out.data(),cs,raw.data()+pos,raw.size()-pos);
    if(ZSTD_isError(r))return{};
    out.resize(r);return out;
}

struct GK { uint32_t s=0,l=0; bool operator<(const GK&o)const{return s!=o.s?s<o.s:l<o.l;} };
static GK gk(const GUID*g){if(!g)return{};return{g->sessionID()?*g->sessionID():0,g->localID()?*g->localID():0};}

int main(int argc,char**argv){
    if(argc<2){fprintf(stderr,"Usage: dump_instances <file.pix>\n");return 1;}
    auto raw=readFile(argv[1]);
    auto dec=decompressPix(raw);
    kiwi::MemoryPool pool; PixsoMsg msg;
    kiwi::ByteBuffer bb(dec.data(),dec.size());
    msg.decode(bb,pool);
    auto*nodes=msg.pixsoNodes(); if(!nodes)return 1;

    // 先建立 GUID -> (name, componentKey) 的索引
    std::map<GK,std::string> guidName, guidCK;
    for(uint32_t i=0;i<nodes->size();i++){
        const PixsoNode&n=(*nodes)[i];
        GK g=gk(n.guid());
        guidName[g]=ss(n.name());
        guidCK[g]=ss(n.componentKey());
    }

    // 统计
    int total=0, withCK=0, withoutCK=0;
    std::map<std::string,int> ckFreq; // componentKey -> 引用次数

    printf("%-6s %-30s  symbolID        %-38s %s\n","idx","instance name","componentKey","publishFile");
    printf("%s\n",std::string(120,'-').c_str());

    for(uint32_t i=0;i<nodes->size();i++){
        const PixsoNode&n=(*nodes)[i];
        uint32_t t=n.type()?(uint32_t)*n.type():0;
        if(t!=17)continue; // 只看 INSTANCE
        total++;

        std::string iname=ss(n.name());
        GK sid={};
        std::string ck, pf;
        if(n.symbolData()&&n.symbolData()->symbolID()){
            sid=gk(n.symbolData()->symbolID());
            ck=guidCK.count(sid)?guidCK[sid]:"(not found)";
            // publishFile 从 instance 自身读
        }
        pf=ss(n.publishFile());
        if(!ck.empty()&&ck!="(not found)") { withCK++; ckFreq[ck]++; }
        else withoutCK++;

        if(iname.size()>28)iname=iname.substr(0,25)+"...";
        printf("%-6u %-30s  %5u:%-8u %-38s %s\n",
               i,iname.c_str(),sid.s,sid.l,
               ck.empty()?"(empty)":ck.c_str(),
               pf.empty()?"":pf.c_str());
    }

    printf("\n=== 统计 ===\n");
    printf("INSTANCE 总数: %d\n", total);
    printf("  引用有 componentKey 的 SYMBOL: %d\n", withCK);
    printf("  引用无 componentKey 的 SYMBOL: %d\n", withoutCK);
    printf("\n=== 出现的 componentKey（去重）===\n");
    for(auto&[ck,cnt]:ckFreq)
        printf("  %s  (引用 %d 次)\n",ck.c_str(),cnt);
    return 0;
}
