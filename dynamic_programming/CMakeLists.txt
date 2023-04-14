cmake_minimum_required(VERSION 3.22)
project(dynamic_programming_samples)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(test)


add_executable(dynamic_programming_samples main.cpp
        count_ways_2D_grid.h
        jumps.h
        length_of_longest_palindromic_subsequence.h
        longest_common_subsequence.h
        longest_increasing_subsequence.h
        maximum_length_of_same_subarray_in_two_arrays.h
        maximum_sum_of_array_no_adjacent_elements.h
        min_costs_to_reach_end.h
        minimum_path_through_matrix.h
        perfect_square.h
        sum_subarray_minimums.h
        trapping_rain_water.h)
