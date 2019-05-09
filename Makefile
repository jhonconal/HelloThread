CC		:=gcc
CXX		:=g++
AR		:=ar
#CC :=aarch64-linux-gnu-gcc
#CXX:=aarch64-linux-gnu-g++
#AR :=aarch64-linux-gnu-ar

PWD_PATH =`pwd`
ROOT_PATH =$(PWD_PATH)
BACK_STEP =./../../../..

C_FLAGS := -std=c++11 -pthread -Wextra

OBJ		=obj
SRC		= UserClientThread.cpp	UserServerThread.cpp  main.cpp
BIN		=bin
LIB		=lib
DEP		=dep
EXTENSION = cpp
SHARE   = -fPIC -shared -o

BIN_OUT = $(BIN)/hellothread
LIB_A  = $(LIB)/hellothread.a
LIB_SO = $(LIB)/hellothread.so
LIB_OBJ = $(OBJ)/UserClientThread.o $(OBJ)/UserServerThread.o  $(OBJ)/main.o

OBJECTS= $(OBJ)/main.o $(OBJ)/UserClientThread.o $(OBJ)/UserServerThread.o

$(OBJ)/%.o:%.$(EXTENSION)
	$(CXX) $(C_FLAGS) -c $< -o $@


#$(LIB_A):$(LIB_OBJ)
#	$(AR) crv $(LIB_A) $@ $(LIB_OBJ)

$(BIN_OUT):$(OBJECTS)
	$(CXX) $(C_FLAGS) -o $@ $(OBJECTS)

$(LIB_SO):$(LIB_OBJ)
	$(CXX) $(CXXFLAGS) $(SHARE) $@ $(LIB_OBJ)

$(DEP)/%.d:%.$(EXTENSION)
	$(CXX) $(CXXFLAGS) -MM $< | sed -e 1's,^,$(OBJ)/,' > $@
	
.PHONY:clean
clean:
	rm -f $(OBJ)/*.o $(DEP)/* $(LIB)/* $(BIN)/*
