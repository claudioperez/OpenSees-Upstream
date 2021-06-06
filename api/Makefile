SHELL:=/bin/bash -O globstar

#OBJS = $(shell echo ../obj/src/CMakeFiles/libg3.dir/**/*.cpp.o)
OBJS = $(shell echo ../obj/src/**/*.o)
all:
	#ar c liba.a **/*.o
	c++ -shared -std=c++11 -fPIC \
	    -Wl,-undefined,dynamic_lookup \
	    -o domain.so \
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
	    domain.cpp
	ipython -c 'import domain'
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
	ipython -c 'import analysis'

