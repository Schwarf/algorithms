cmake_minimum_required(VERSION 3.24)
project(probabilistic_algorithms)

set(CMAKE_CXX_STANDARD 20)

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
enable_cxx_compiler_flag_if_supported("-O3")
enable_cxx_compiler_flag_if_supported("-fconcepts-diagnostics-depth=2")
enable_cxx_compiler_flag_if_supported("-Werror")
enable_cxx_compiler_flag_if_supported("-Wno-sign-compare") # Disable specific warning

add_subdirectory(test)

add_executable(probabilistic_algorithms
                main.cpp
                reservoir_sampling.h
                held_karp_algorithm.h
                simulated_annealing.h
                used_concepts.h
                simulated_annealing_full_templated.h
                traveling_salesman_functors.h)
add_executable(sample templating_with_functions.cpp)
