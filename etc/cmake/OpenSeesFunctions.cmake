function (opensees_load lib_name)
    cmake_parse_arguments(
        PARSE_ARGV 1
        OPS_LOAD_ARG # prefix of output variables
	"SEARCH;BUILD;FIND" # list of names of the boolean arguments (only defined ones will be true)
        "" # list of names of mono-valued arguments
        "PATHS" # list of names of multi-valued arguments (output variables are lists)
        #${ARGN} # arguments of the function to parse, here we take the all original ones
    )
    set(OPS_PKG_FOUND_VAR "FOUND_${lib_name}" PARENT_SCOPE) 
    set(${OPS_PKG_FOUND_VAR} FALSE PARENT_SCOPE)
    if(OPS_LOAD_ARG_BUILD)
        message("Using OpenSees provided ${lib_name}")
	set(${OPS_PKG_FOUND_VAR} TRUE PARENT_SCOPE)
        return()
    elseif(OPS_LOAD_ARG_PATHS)
        message("Provided ${lib_name} paths are:")
        foreach(src ${OPS_LOAD_ARG_PATHS})
            message("- ${src}")
        endforeach(src)
        find_package(${lib_name} PATHS ${OPS_LOAD_ARG_PATHS})
    else()
        find_package(${lib_name})
    endif()
    if(OPS_LOAD_ARG_SEARCH)
	if(NOT ${OPS_PKG_FOUND_VAR})
	    set(${OPS_PKG_FOUND_VAR} TRUE PARENT_SCOPE)
	    message("CMake failed to find ${lib_name}; building OpenSees version")
	    opensees_build(${lib_name})
	endif()
    endif()
endfunction()

function (opensees_build lib_name)
    message("(OpenSees build not yet implemented)")
endfunction()

