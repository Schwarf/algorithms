project(test_sliding_windows)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
include_directories(./../)
add_executable(test_sliding_windows
        test_number_of_substrings.cpp
        test_longest_substring_without_repeating_characters.cpp
        test_get_equal_substring_with_budget.cpp
        test_count_subarrays_with_target.cpp
        test_find_longest_subarray_with_at_most_k_frequency.cpp
        test_count_subarrays_where_max_appears_k_times.cpp
        test_count_subarrays_find_k_different_elements.h.cpp
        test_minimum_swaps_to_group_ones.cpp
        test_shortest_subarray_with_sum.cpp
        test_max_sum_of_distinct_subarrays_with_given_length.cpp
        test_max_beauty_after_equalize_elements_in_array.cpp
        test_score_after_marking_elements.cpp)

target_link_libraries(test_sliding_windows GTest::GTest GTest::Main pthread)
add_test(NAME SlidingWindowsTests COMMAND test_sliding_windows)
