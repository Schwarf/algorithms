project(test_fun_with_algos)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})


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
        test_largest_submatrix_by_moving_columns.cpp test_interval_map.cpp test_interval_map2.cpp test_greatest_common_divisor.cpp test_find_pivot_integer.cpp)

include_directories(./../)
target_link_libraries(test_fun_with_algos ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES} pthread)
