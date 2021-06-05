cmake_minimum_required(VERSION 3.13)

project(G3)

option(FMK "Special FMK Code" OFF)
option(HDF5 "HDF5 Dependent Code" OFF)
option(SEQUENTIAL "Build OpenSees" ON)
option(PARALLEL "Build OpenSeesSP" OFF)
option(PARALLEL_INTERPRETER "Build OpenSeesMP" OFF)
option(RELIABILITY "Include Reliability" OFF)

set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} -fPIC)

if(FMK)
   add_definitions(-D_HAVE_Damage2p	
   		-D_HAVE_PSUMAT
		-D_HAVE_PML
		-D_FILIP_LHNMYS)	
endif()

if(HDF5)
   find_package(HDF5)
    if(HDF5_FOUND)
        include_directories(${HDF5_INCLUDE_DIR})
        set(_hdf5_libs hdf5 hdf5_cpp)
	add_definitions(-D_H5DRM)
    else()
	 message(STATUS ">>> Could not find HDF5")
    endif()
endif()

if(SEQUENTIAL)

elseif(PARALLEL)
	add_definitions(-D_PARALLEL_PROCESSING)
else(PARALLEL_INTERPRETER)
	add_definitions(-D_PARALLEL_INTERPRETERS)
endif()



if(APPLE)
 message(STATUS ">>> MacOS")
endif()

if(UNIX AND NOT APPLE)
 message(STATUS ">>> LINUX")
endif()

if(WIN32)
 message(STATUS ">>> WIN32")
endif()

#
# include paths to main abstract classes
#

# NOTE BeamIntegration and MatrixUtil need to be removed from element/forceBEamColumn

include_directories(src
	src/base
	src/matrix
	src/handler
	#src/api
	src/database
	#src/element
	#src/element/forceBeamColumn
	#src/element/nonlinearBeamColumn/matrixutil
	src/coordTransformation
	src/tagged
	src/tagged/storage
	src/recorder
	src/renderer
	src/damage
	src/recorder/response
	src/material
	src/material/section
	src/material/uniaxial
	#src/material/nD
	src/graph/graph
	src/graph/numberer
	src/graph/partitioner
	src/domain/component
	src/domain/domain
	src/domain/subdomain
	src/domain/load
	src/domain/loadBalancer
	src/domain/pattern
	src/domain/groundMotion
	src/domain/node
	src/domain/constraints
	src/domain/region
	src/analysis/algorithm
	src/analysis/dof_grp
	src/analysis/fe_ele
	src/analysis/algorithm/equiSolnAlgo
	src/analysis/algorithm/eigenAlgo
	src/analysis/algorithm/domainDecompAlgo
	src/analysis/analysis
	src/analysis/integrator
	src/analysis/handler
	src/analysis/numberer
	src/analysis/model
	src/convergenceTest
	src/modelbuilder
	src/system_of_eqn
	src/system_of_eqn/linearSOE
	src/system_of_eqn/eigenSOE
	src/actor/actor
	src/actor/channel
	src/actor/objectBroker
	src/actor/message)

include_directories(ext/CSPARSE)
include_directories(ext/AMD)
include_directories(include/)

#
# build
#

add_subdirectory(src)
add_subdirectory(api)
#add_executable(OpenSees src/tcl/tclAppInit.cpp)


