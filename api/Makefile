SHELL:=/bin/bash -O globstar
PYTHON = python3
#OBJS = $(shell echo ../obj/src/CMakeFiles/libg3.dir/**/*.cpp.o)
#OBJS = $(shell echo ../obj/src/**/*.o)
OBJS = $(shell echo ../build/src/**/*.o)
OBJS += ZeroLength.cpp.o
#OBJS = libg3.a
CXX_FLAGS := -O3 -fPIC -g
CXX_FLAGS += -fvisibility=hidden
#CXX_FLAGS += -flto

all:
	#ar c liba.a **/*.o
	c++ -shared -std=c++11  $(CXX_FLAGS) \
	    -Wl,-undefined,dynamic_lookup \
	    -o _pyg3.so \
	    -I../src/ \
	    -I../include \
	    $$($(PYTHON) -m pybind11 --includes) \
	    $(OBJS) \
	    -llapack \
	    -larpack \
	    -lmetis \
	    ~/lib/libSuperLU.a \
	    ~/lib/libUmfpack.a \
	    -lamd \
	    _quakeio.cpp \
	    _pyg3.cpp #> /dev/null
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

