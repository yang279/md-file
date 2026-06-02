CXX      = clang++
CC       = clang
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

BIN  = bin/dsl_to_hex
COMP = ../pix-split/harmony_out/component

all: bin $(BIN)

bin:
	mkdir -p bin

$(BIN): dsl_to_hex.cpp $(ZSTD_OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

# 无实例测试
test-simple: $(BIN)
	$(BIN) test_data/dsl-demo.json test_data/demo_out.txt

# 单实例测试（目录模式）
test-instance: $(BIN)
	$(BIN) test_data/dsl-one-instance.json \
		test_data/one_instance_out.txt \
		$(COMP)

# 多实例测试
test-multi: $(BIN)
	$(BIN) test_data/dsl-instance-demo.json \
		test_data/instance_out.txt \
		$(COMP)

test: test-simple test-instance test-multi

clean:
	rm -f $(BIN) $(ZSTD_OBJS)

.PHONY: all bin test test-simple test-instance test-multi clean
