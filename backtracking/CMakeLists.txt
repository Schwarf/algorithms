cmake_minimum_required(VERSION 3.21)
project(backtracking)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(test)

add_executable(backtracking main.cpp queens_problem.h search_word_in_character_grid.h path_sum_binary_tree.h generate_all_subsets_of_size_k.h)
