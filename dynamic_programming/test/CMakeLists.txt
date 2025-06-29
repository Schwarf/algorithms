project(test_dynamic_programming)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
include_directories(./../)
add_executable(test_dynamic_programming
        test_min_costs_to_reach_end.cpp
        test_main.cpp
        test_can_reach_last_index.cpp
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
        test_maximum_subarray_kadane_algorithm.cpp
        test_longest_palindromic_substring.cpp
        test_coin_change.cpp
        test_minimal_jumps_to_last_index.cpp
        knapsack/test_knapsack_problem_0_1.cpp
        test_predict_the_winner.cpp
        test_coin_combinations.cpp
        test_unique_paths.cpp test_unique_paths_with_obstacles.cpp
        test_longest_string_chain.cpp
        test_longest_common_subsequence.cpp
        test_maximize_product_from_given_target.cpp
        test_number_of_dice_rolls_for_target.cpp
        test_number_of_string_decodings.cpp
        test_minimum_difficulty_job_schedule.cpp
        test_count_unique_binary_search_trees.cpp
        test_largest_divisible_subset.cpp test_count_palindromic_substrings.cpp
        test_longest_ideal_string_subsequence.cpp
        test_cutting_rod_problem.cpp
        test_matrix_chain_multiplication.cpp
        test_count_numbers_of_valid_triples.cpp
        test_minimal_operations_to_create_valid_string.cpp
        test_minimal_height_book_shelves.cpp
        test_maximum_number_of_points_with_costs.cpp
        test_nth_ugly_number.cpp
        test_minimum_copy_paste_operations.cpp
        test_maximize_index_value_pair.cpp
        test_word_break.cpp
        test_longest_common_substring.cpp
        knapsack/test_complete_knapsack.cpp
        knapsack/test_multiple_knapsack.cpp
        test_max_profit_in_job_scheduling.cpp)

target_link_libraries(test_dynamic_programming GTest::GTest GTest::Main pthread)
add_test(NAME DynamicProgrammingTests COMMAND test_dynamic_programming)

#target_link_libraries(dynamic_programming_samples_test ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES} pthread)
