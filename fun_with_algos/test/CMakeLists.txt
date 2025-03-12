project(test_fun_with_algos)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
include_directories(./../)

add_executable(test_fun_with_algos
        test_get_majority_element.cpp
        test_remove_occurences_of_value.cpp
        test_remove_duplicates_from_sorted_array.cpp
        test_minimum_intervals_to_cover_range.cpp
        test_minimum_deletions_for_unique_character_frequencies.cpp
        test_interval_merging.cpp
        test_candy_for_children_grades.cpp
        test_minimum_operations_to_reduce_x_to_zero.cpp
        test_three_sum.cpp
        test_subarray_product_less_than.cpp
        test_spider_brainteaser.cpp
        test_find_original_array_from_doubled_array.cpp
        test_sum_of_absolute_differences.cpp
        test_largest_submatrix_by_moving_columns.cpp
        test_interval_map.cpp
        test_interval_map2.cpp
        test_greatest_common_divisor.cpp
        test_find_pivot_integer.cpp
        test_insert_interval.cpp
        test_task_scheduler.cpp
        test_find_duplicate_in_array.cpp
        test_find_all_duplicates_in_array.cpp
        test_find_first_missing_positive.cpp
        test_island_perimeter.cpp
        test_largest_integer_with_its_negative.cpp
        test_score_after_flipping_matrix.cpp
        test_can_attend_all_meetings.cpp
        test_logger_rate_limiter.cpp
        test_maximum_distance_in_arrays.cpp
        test_largest_min_max_index_gap.cpp
        test_maximum_matrix_sum.cpp
        test_flip_columns_to_maximize_equal_rows.cpp
        test_minimum_swaps.cpp
        test_is_dna_sequence_similar.cpp
        test_hiring_candidates.cpp
        test_min_swaps_for_palindrome.cpp)

target_link_libraries(test_fun_with_algos GTest::GTest GTest::Main pthread)
add_test(NAME FunWithAlgorithmsTests COMMAND test_fun_with_algos)

#target_link_libraries(test_fun_with_algos ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES} pthread)
