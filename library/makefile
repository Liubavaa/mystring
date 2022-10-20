CXX = g++ -std=c++17
CXXFLAGS = -O3
LIB_EX = .dll
LIB_DIR = lib
OBJ_DIR = obj
SOURCES = mystring.cpp
OBJS = $(patsubst %.cpp,$(OBJ_DIR)/%.o,$(SOURCES))

all: dir $(LIB_DIR)/libfunctions.a $(LIB_DIR)/libfunctions$(LIB_EX)

dir:
	mkdir -p lib
	mkdir -p obj

-include $(OBJS:.o=.d)

$(LIB_DIR)/libfunctions.a: $(OBJS)
	ar rcs $@ $^

$(LIB_DIR)/libfunctions$(LIB_EX): $(OBJS)
	$(CXX) -shared -fPIC -o $@ $^

$(OBJ_DIR)/%.o: %.cpp
	$(CXX) -c $(CXXFLAGS) $< -o $@ -fPIC
	$(CXX) -MM -MP -MT $@ -MF $(OBJ_DIR)/$*.d $(CXXFLAGS) $<

.PHONY : clean
clean:
	rm -rf $(OBJ_DIR)/*.o $(OBJ_DIR)/*.d

