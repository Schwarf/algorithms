cmake_minimum_required(VERSION 3.21)
project(test_dynamic_programming_samples)


find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

enable_testing()

add_executable(dynamic_programming_samples_test
        test_min_costs_to_reach_end.cpp
        test_min_jumps_to_last_index.cpp
        test_count_ways_in_2D_grid.cpp
        test_longest_increasing_subsequence.cpp
        test_maximum_length_of_same_subarray_in_two_arrays.cpp
        test_perfect_squares.cpp
        test_main.cpp)

target_link_libraries(dynamic_programming_samples_test ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES} pthread)
