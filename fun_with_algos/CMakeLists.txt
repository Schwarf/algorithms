cmake_minimum_required(VERSION 3.22)
project(fun_with_algos)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_C_STANDARD 99)
add_subdirectory(test)
include(CheckCXXCompilerFlag)

function(enable_cxx_compiler_flag_if_supported flag)
    string(FIND "${CMAKE_CXX_FLAGS}" "${flag}" flag_already_set)
    if (flag_already_set EQUAL -1)
        check_cxx_compiler_flag("${flag}" flag_supported)
        if (flag_supported)
            set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${flag}" PARENT_SCOPE)
        endif ()
        unset(flag_supported CACHE)
    endif ()
endfunction()

enable_cxx_compiler_flag_if_supported("-Wall")
enable_cxx_compiler_flag_if_supported("-Wextra")
enable_cxx_compiler_flag_if_supported("-pedantic")
enable_cxx_compiler_flag_if_supported("-std=c++17")
enable_cxx_compiler_flag_if_supported("-O0")
enable_cxx_compiler_flag_if_supported("-Werror")
enable_cxx_compiler_flag_if_supported("-Wno-sign-compare") # Disable specific warning

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
        find_first_missing_positive.h
        island_perimeter.h
        largest_integer_with_its_negative.h
        score_after_flipping_matrix.h
        can_attend_all_meetings.h
        logger_rate_limiter.h
        maximum_distance_in_arrays.h
        "largest_extremum_index_gap .h"
        maximum_matrix_sum.h
        flip_columns_to_maximize_equal_rows.h)
