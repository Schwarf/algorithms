cmake_minimum_required(VERSION 3.20)
project(data_structures)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_C_STANDARD 99)
include(CheckCXXCompilerFlag)


function(enable_cxx_compiler_flag_if_supported flag)
    string(FIND "${CMAKE_CUDA_FLAGS}" "${flag}" flag_already_set)
    if (flag_already_set EQUAL -1)
        check_cxx_compiler_flag("${flag}" flag_supported)
        if (flag_supported)
            set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${flag}" PARENT_SCOPE)
        endif ()
        unset(flag_supported CACHE)
    endif ()
endfunction()

enable_cxx_compiler_flag_if_supported("-Wall")
enable_cxx_compiler_flag_if_supported("-Wextra")
enable_cxx_compiler_flag_if_supported("-pedantic")
enable_cxx_compiler_flag_if_supported("-std=c++17")
enable_cxx_compiler_flag_if_supported("-O0")


add_executable(data_structures main.cpp binary_search_tree/bst_node.h binary_search_tree/binary_search_tree.h)
