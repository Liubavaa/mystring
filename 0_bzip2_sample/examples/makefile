C = clang
CFLAGS = -O3
LIB_DIR = ../library/lib
LDLAGS = -L$(LIB_DIR) -lfunctions -Wl,-rpath,$(LIB_DIR)
BIN_DIR = bin
OBJ_DIR = obj

all: dir $(BIN_DIR)/bzip2 $(BIN_DIR)/bzip2recover

dir:
	mkdir -p bin
	mkdir -p obj

$(BIN_DIR)/bzip2: $(OBJ_DIR)/bzip2.o
	$(C) $^ $(LDLAGS) -o $@

$(BIN_DIR)/bzip2recover: $(OBJ_DIR)/bzip2recover.o
	$(C) $^ $(LDLAGS) -o $@

$(OBJ_DIR)/%.o: %.c
	$(C) -c $(CFLAGS) $< -o $@

.PHONY : clean
clean:
	rm -rf $(OBJ_DIR)/*.o
