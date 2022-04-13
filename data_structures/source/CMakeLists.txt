cmake_minimum_required(VERSION 3.20)
project(data_structures C CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_C_STANDARD 99)
include(CheckCXXCompilerFlag)

set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)
find_package(Boost 1.71.0 )

if(NOT Boost_FOUND)
    message(FATAL_ERROR "Could not find boost!")
endif()


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


add_executable(data_structures
        main.cpp
        binary_search_tree/bst_node.h
        binary_search_tree/binary_search_tree.h)

add_subdirectory(hash_functions)
add_subdirectory(linked_lists)
add_subdirectory(stacks_and_queues)
add_subdirectory(heaps)
add_subdirectory(trees)
add_subdirectory(graphs)
add_subdirectory(test)
add_subdirectory(miscellaneous)

include_directories(hash_functions)
include_directories(linked_lists)
include_directories(stacks_and_queues)
include_directories(heaps)
include_directories(trees)
include_directories(miscellaneous)
include_directories(${Boost_INCLUDE_DIRS})

target_link_libraries(data_structures linked_list_lib stacks_and_queues_lib heap_lib hash_functions_lib test_hash_function_lib misc_lib)