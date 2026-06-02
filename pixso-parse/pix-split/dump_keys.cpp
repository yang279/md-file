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

int main(int argc,char**argv){
    if(argc<2){fprintf(stderr,"Usage: dump_keys <file.pix>\n");return 1;}
    auto raw=readFile(argv[1]);
    auto dec=decompressPix(raw);
    kiwi::MemoryPool pool;PixsoMsg msg;
    kiwi::ByteBuffer bb(dec.data(),dec.size());
    msg.decode(bb,pool);
    auto*nodes=msg.pixsoNodes();if(!nodes)return 1;

    int cnt=0;
    printf("%-6s %-10s %-6s %-40s %-36s %-20s %-20s\n",
           "idx","type","isSG","name","componentKey","publishFile","publishID");
    printf("%s\n",std::string(140,'-').c_str());

    for(uint32_t i=0;i<nodes->size()&&cnt<60;i++){
        const PixsoNode&n=(*nodes)[i];
        uint32_t t=n.type()?(uint32_t)*n.type():0;
        bool isSG=(n.isStateGroup()&&*n.isStateGroup());
        if(t!=16&&!(t==5&&isSG))continue;
        cnt++;
        std::string ck=ss(n.componentKey());
        std::string pf=ss(n.publishFile());
        // publishID
        std::string pid;
        if(n.publishID()){
            uint32_t s=n.publishID()->sessionID()?*n.publishID()->sessionID():0;
            uint32_t l=n.publishID()->localID()?*n.publishID()->localID():0;
            char buf[32];snprintf(buf,32,"%u:%u",s,l);pid=buf;
        }
        std::string name=ss(n.name());
        if(name.size()>38)name=name.substr(0,35)+"...";
        printf("%-6u %-10s %-6s %-40s %-36s %-20s %-20s\n",
               i,(t==16?"SYMBOL":"FRAME_SG"),(isSG?"true":"false"),
               name.c_str(),ck.empty()?"(empty)":ck.c_str(),
               pf.empty()?"(empty)":pf.c_str(),
               pid.empty()?"(empty)":pid.c_str());
    }
    return 0;
}
