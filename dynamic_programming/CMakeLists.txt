cmake_minimum_required(VERSION 3.21)
project(dynamic_programming_samples)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(test)


add_executable(dynamic_programming_samples main.cpp
        count_ways_2D_grid.h
        can_reach_last_index.h
        length_of_longest_palindromic_subsequence.h
        longest_common_subsequence.h
        longest_increasing_subsequence.h
        maximum_length_of_same_subarray_in_two_arrays.h
        maximum_sum_of_array_no_adjacent_elements.h
        min_costs_to_reach_end.h
        minimum_path_through_matrix.h
        perfect_square.h
        sum_subarray_minimums.h
        trapping_rain_water.h
        maximum_number_of_uncrossing_lines.h
        maximum_points_solved_with_brain_power.h
        pascal_triangle.h
        maximum_subarray_kadane_algorithm.h
        used_concepts.h
        minimize_number_of_coins.h
        main.cpp
        minimal_jumps_to_last_index.h
        knapsack_problem.h)
