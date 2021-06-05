
#add_library(pyg3 SHARED)
find_package(pybind11 REQUIRED)

pybind11_add_module(pyg3
	pyg3.cpp
)

target_sources(pyg3
    PRIVATE
        pyg3.cpp
)

target_link_libraries(pyg3 PUBLIC libg3)

#target_include_directories(domain PUBLIC $(CMAKE_CURRENT_LIST_DIR))

