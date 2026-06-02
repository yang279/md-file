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

BIN = bin/split_compset

all: bin $(BIN)

bin:
	mkdir -p bin

$(BIN): split_compset.cpp $(ZSTD_OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

# 示例：拆解组件库并输出到 harmony_out/
test: $(BIN)
	$(BIN) build_index \
		"../HarmonyOS Component Library（来自社区）.pix" \
		harmony_out \
		--publish-file QcO-1WDViGmGQ4IFU_p4FQ

clean:
	rm -f $(BIN) $(ZSTD_OBJS)

.PHONY: all bin test clean
