find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
add_executable(fun_with_strings_test
        test_remove_duplicates.cpp
        test_decode_string_at_index.cpp
        test_count_beautiful_substrings.cpp
        test_create_ranges_from_sorted_array.cpp
        test_count_steps_to_make_strings_anagram.cpp
        test_levnsthein_distance.cpp
        test_sort_string_by_character_frequency.cpp
        test_are_strings_close.cpp
        test_knuth_morris_pratt_algo.cpp
        test_compare_version_number.cpp
        test_sentence_similarity.cpp
        test_permutation_include_in_string.cpp
        test_minimum_length_after_removing_substrings.cpp)
target_link_libraries(fun_with_strings_test ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES} pthread)
