cmake_minimum_required(VERSION 3.25)
project(sliding_window)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(test)
add_executable(sliding_window main.cpp
        number_of_substrings.h
        longest_substring_without_repeating_characters.h
        get_equal_substrings_with_budget.h
        count_subarrays_with_target.h
        find_longest_subarray_with_at_most_k_frequency.h
        count_subarrays_where_max_appears_k_times.h
        count_subarrays_with_exactly_k_different_elements.h)


