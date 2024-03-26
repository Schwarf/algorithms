cmake_minimum_required(VERSION 3.22)
project(fun_with_algos)

set(CMAKE_CXX_STANDARD 20)
add_subdirectory(./test)

add_executable(fun_with_algos main.cpp
        get_majority_element.h
        three_sum.h
        interval_merging.h
        subarray_product_less_than.h
        used_concepts.h
        remove_occurences_of_value.h
        remove_duplicates_from_sorted_array.h
        minimum_intervals_to_cover_range.h
        minimum_deletions_for_unique_character_frequencies.h
        candy_for_children_grades.h
        minimum_operations_to_reduce_x_to_zero.h
        find_original_array_from_doubled_array.h
        spider_brainteaser.h
        sum_of_absolute_differences.h
        largest_submatrix_by_moving_columns.h
        interval_map.h
        interval_map2.h
        greatest_common_divisor.h
        find_pivot_integer.h
        insert_interval.h
        task_scheduler.h
        find_duplicate_in_array.h
        find_all_duplicates_in_array.h
        find_first_missing_positive.h)
