cmake_minimum_required(VERSION 3.21)
project(algorithms)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
include(CheckCXXCompilerFlag)

function(enable_cxx_compiler_flag_if_supported flag)
    string(FIND "${CMAKE_CXX_FLAGS}" "${flag}" flag_already_set)
    if (flag_already_set EQUAL -1)
        check_cxx_compiler_flag("${flag}" flag_supported)
        if (flag_supported)
            set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${flag}" PARENT_SCOPE)
        endif ()
    endif ()
endfunction()


# Add common compiler flags
enable_cxx_compiler_flag_if_supported("-Wall")
enable_cxx_compiler_flag_if_supported("-Wextra")
enable_cxx_compiler_flag_if_supported("-pedantic")
enable_cxx_compiler_flag_if_supported("-std=c++20")
enable_cxx_compiler_flag_if_supported("-O0")
enable_cxx_compiler_flag_if_supported("-Werror")
enable_cxx_compiler_flag_if_supported("-Wno-sign-compare")

# Enable testing
include(CTest)
enable_testing()

add_subdirectory(backtracking)
add_subdirectory(binary_search)
add_subdirectory(bit_manipulation)
#add_subdirectory(CTCI)
add_subdirectory(data_structures/source)
add_subdirectory(dynamic_programming)
add_subdirectory(fun_with_algos)
add_subdirectory(fun_with_arrays)
add_subdirectory(fun_with_strings)
add_subdirectory(prefix_sums)
#add_subdirectory(probabilistic_algorithms)
add_subdirectory(sliding_window)
add_subdirectory(sorting_algorithms)
#add_subdirectory(template_reminders)





