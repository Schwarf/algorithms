cmake_minimum_required(VERSION 3.21)
project(fun_with_arrays CXX)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(test)
add_executable(sum_longest_subarray main.cpp count_words_that_are_subsequences_in_given_string.h find_longest_contiguous_subarray.h)
