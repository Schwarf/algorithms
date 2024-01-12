cmake_minimum_required(VERSION 3.25)
project(sliding_window)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(test)
add_executable(sliding_window main.cpp number_of_substrings.h longest_substring_without_repeating_characters.h)


