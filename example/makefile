CXX = clang
CXXFLAGS = -O3
PROG_NAME = test
LIB_DIR = ../library/lib
LDLAGS = -L$(LIB_DIR) -lfunctions -Wl,-rpath,$(LIB_DIR)
BIN_DIR = bin
OBJ_DIR = obj

all: dir $(BIN_DIR)/$(PROG_NAME)

dir:
	mkdir -p bin
	mkdir -p obj

$(BIN_DIR)/$(PROG_NAME): $(OBJ_DIR)/main.o
	$(CXX) $^ $(LDLAGS) -o $@

$(OBJ_DIR)/%.o: %.cpp
	$(CXX) -c $(CXXFLAGS) $< -o $@

.PHONY : clean
clean:
	rm -rf $(OBJ_DIR)/*.o

