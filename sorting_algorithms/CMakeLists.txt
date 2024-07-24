cmake_minimum_required(VERSION 3.20)
project(sort)

set(CMAKE_CXX_STANDARD 20)
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
enable_cxx_compiler_flag_if_supported("-Werror")
enable_cxx_compiler_flag_if_supported("-Wno-sign-compare") # Disable specific warning

add_subdirectory(test)
add_executable(sort main.cpp
        heap_sort.h
        quick_sort.h
        counting_sort.h
        used_concepts.h
        merge_sort.h
        insertion_sort.h
        selection_sort.h
        shell_sort.h
        bubble_sort.h
        bitonic_sort.h
        sort_characters_by_frequency.h
        sort_array_by_increasing_frequency.h
        sort_jumbled_numbers.h)


