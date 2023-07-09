project(test_dynamic_programming_samples)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
include_directories(./../)
add_executable(dynamic_programming_samples_test
        test_min_costs_to_reach_end.cpp
        test_main.cpp
        test_jumps.cpp
        test_count_ways_in_2D_grid.cpp
        test_longest_increasing_subsequence.cpp
        test_maximum_length_of_same_subarray_in_two_arrays.cpp
        test_perfect_squares.cpp
        test_trapping_rain_water.cpp
        test_sum_subarray_minimums.cpp
        test_minimum_path_through_matrix.cpp
        test_maximum_sum_of_array_no_adjacent_elements.cpp
        test_length_of_longest_palindromic_subsequence.cpp
        test_maximum_number_of_uncrossing_lines.cpp
        test_maximum_points_solved_brain_power.cpp
        test_fibonacci.cpp
        test_pascal_triangle.cpp
        test_maximum_subarray_kadane_algorithm.cpp)

target_link_libraries(dynamic_programming_samples_test ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES} pthread)
