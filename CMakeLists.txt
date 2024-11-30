cmake_minimum_required(VERSION 3.21)
project(algorithms)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_subdirectory(backtracking)
add_subdirectory(binary_search)
add_subdirectory(bit_manipulation)
add_subdirectory(CTCI)
add_subdirectory(data_structures/source)
add_subdirectory(dynamic_programming)
add_subdirectory(fun_with_algos)
add_subdirectory(fun_with_arrays)
add_subdirectory(fun_with_strings)
add_subdirectory(prefix_sums)
add_subdirectory(probabilistic_algorithms)
add_subdirectory(sliding_window)
add_subdirectory(sorting_algorithms)
add_subdirectory(template_reminders)

#include(${ALGORITHM_DIR}/Definitions.cmake)



