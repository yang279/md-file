CXX    = clang++
CC     = clang
CXXFLAGS = -std=c++17 -O2 -I.. -I../kiwi-master -I../zstd-1.5.6/lib
CFLAGS   = -O2 -I../zstd-1.5.6/lib

ZSTD_COMMON = \
	../zstd-1.5.6/lib/common/debug.c \
	../zstd-1.5.6/lib/common/entropy_common.c \
	../zstd-1.5.6/lib/common/error_private.c \
	../zstd-1.5.6/lib/common/fse_decompress.c \
	../zstd-1.5.6/lib/common/pool.c \
	../zstd-1.5.6/lib/common/threading.c \
	../zstd-1.5.6/lib/common/xxhash.c \
	../zstd-1.5.6/lib/common/zstd_common.c

ZSTD_DECOMP = \
	../zstd-1.5.6/lib/decompress/huf_decompress.c \
	../zstd-1.5.6/lib/decompress/zstd_ddict.c \
	../zstd-1.5.6/lib/decompress/zstd_decompress.c \
	../zstd-1.5.6/lib/decompress/zstd_decompress_block.c

ZSTD_COMP = \
	../zstd-1.5.6/lib/compress/fse_compress.c \
	../zstd-1.5.6/lib/compress/hist.c \
	../zstd-1.5.6/lib/compress/huf_compress.c \
	../zstd-1.5.6/lib/compress/zstd_compress.c \
	../zstd-1.5.6/lib/compress/zstd_compress_literals.c \
	../zstd-1.5.6/lib/compress/zstd_compress_sequences.c \
	../zstd-1.5.6/lib/compress/zstd_compress_superblock.c \
	../zstd-1.5.6/lib/compress/zstd_double_fast.c \
	../zstd-1.5.6/lib/compress/zstd_fast.c \
	../zstd-1.5.6/lib/compress/zstd_lazy.c \
	../zstd-1.5.6/lib/compress/zstd_ldm.c \
	../zstd-1.5.6/lib/compress/zstd_opt.c

ZSTD_SRCS = $(ZSTD_COMMON) $(ZSTD_DECOMP) $(ZSTD_COMP)
ZSTD_OBJS = $(ZSTD_SRCS:.c=.o)

GEN  = bin/gen_instance
TREE = bin/show_tree

all: bin $(GEN) $(TREE)

bin:
	mkdir -p bin

$(GEN): gen_instance.cpp $(ZSTD_OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(TREE): show_tree.cpp $(ZSTD_OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

# 示例：列出组件集变体
test: $(GEN)
	$(GEN) list "../pix-split/harmony_out/component/eb2f5b3bde54280c4c2a751341f30779e2f40833.txt"

clean:
	rm -f $(GEN) $(TREE) $(ZSTD_OBJS)

.PHONY: all bin test clean
