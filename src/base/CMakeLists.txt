add_library(base "")

target_include_directories(base PUBLIC $(CMAKE_CURRENT_LIST_DIR))

target_sources(base
    PRIVATE
        Information.h
    PUBLIC
        Information.cpp
)

