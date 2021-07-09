SHELL:=/bin/bash -O globstar
PYTHON = python3
#OBJS = $(shell echo ../obj/src/CMakeFiles/libg3.dir/**/*.cpp.o)
#OBJS = $(shell echo ../obj/src/**/*.o)
OBJS = $(shell echo ../build/src/**/*.o)
#OBJS = $(shell echo ~/OpenSees/build/CMakeFiles/libg3.dir/SRC/**/*.o)
#OBJS  = libg3.a
#OBJS  = $(shell echo ~/OpenSees/build/SRC/tagged/CMakeFiles/tagged.dir/**/*.o)
#OBJS += $(shell echo ~/OpenSees/build/SRC/analysis/CMakeFiles/analysis.dir/**/*.o)
#OBJS += $(shell echo ~/OpenSees/build/SRC/convergenceTest/CMakeFiles/convergenceTest.dir/**/*.o)
#OBJS += $(shell echo ~/OpenSees/build/SRC/graph/CMakeFiles/graph.dir/**/*.o)
#OBJS += $(shell echo ~/OpenSees/build/SRC/actor/CMakeFiles/actor.dir/**/*.o)
#OBJS += ZeroLength.cpp.o

#OBJS += -Wl,--whole-archive libg3.a -Wl,--no-whole-archive
CXX_FLAGS := -fPIC -g -Wall
#CXX_FLAGS += -fvisibility=hidden
CXX_FLAGS += -flto
LD_FLAGS = -Wl,-undefined,dynamic_lookup 
#LD_FLAGS = -Wl,-undefined,dynamic_lookup -Wl,--warn-unresolved-symbols

all:
	#strip liblibg3.a -w -N 'ops_*' -o libg3.a
	c++ -shared -std=c++11  $(CXX_FLAGS) \
	    -o _pyg3.so \
	    $(LD_FLAGS) \
	    $(OBJS) \
	    -I../src/ \
	    -I../include \
	    $$($(PYTHON) -m pybind11 --includes) \
	    -llapack \
	    -larpack \
	    -lmetis \
	    ~/lib/libSuperLU.a \
	    ~/lib/libUmfpack.a \
	    -lamd \
	    _quakeio.cpp \
	    _pyg3.cpp 
	$(PYTHON) -c 'import _pyg3'

%.so: %.cpp
	c++ -shared -std=c++11 -fPIC \
	    -Wl,-undefined,dynamic_lookup \
	    -o $@ \
	    -I../src/ \
	    -I../include \
	    $$(python3 -m pybind11 --includes) \
	    $(OBJS) \
	    -llapack \
	    -larpack \
	    -lmetis \
	    ~/lib/libSuperLU.a \
	    ~/lib/libUmfpack.a \
	    -lamd \
	    $<
	#$(PYTHON) -c 'import analysis'

%.o: %.cpp
	c++ -shared -std=c++11 -fPIC \
	    -o $@ \
	    -I../src/ \
	    -I../include \
	    $$(python3 -m pybind11 --includes) \
	    $(OBJS) \
	    -llapack \
	    -larpack \
	    -lmetis \
	    ~/lib/libSuperLU.a \
	    ~/lib/libUmfpack.a \
	    -lamd \
	    $<
	    #-Wl,-undefined,dynamic_lookup \

