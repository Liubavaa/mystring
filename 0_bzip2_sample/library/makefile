C = gcc
CFLAGS = -O3
LIB_EX = .dll
LIB_DIR = lib
OBJ_DIR = obj
SOURCES = bzlib.c blocksort.c compress.c crctable.c decompress.c huffman.c randtable.c
OBJS = $(patsubst %.c,$(OBJ_DIR)/%.o,$(SOURCES))

all: dir $(LIB_DIR)/libfunctions.a $(LIB_DIR)/libfunctions$(LIB_EX)

dir:
	mkdir -p lib
	mkdir -p obj

-include $(OBJS:.o=.d)

$(LIB_DIR)/libfunctions.a: $(OBJS)
	ar rcs $@ $^

$(LIB_DIR)/libfunctions$(LIB_EX): $(OBJS)
	$(C) -shared -fPIC -o $@ $^

$(OBJ_DIR)/%.o: %.c
	$(C) -c $(CFLAGS) $< -o $@ -fPIC
	$(C) -MM -MP -MT $@ -MF $(OBJ_DIR)/$*.d $(CFLAGS) $<

.PHONY : clean
clean:
	rm -rf $(OBJ_DIR)/*.o $(OBJ_DIR)/*.d
