project(test_fun_with_strings)
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
include_directories(./../)
add_executable(test_fun_with_strings
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
        test_minimum_length_after_removing_substrings.cpp
        test_are_strings_equal_upto_rotation.cpp
        test_decode_string.cpp
        test_reorder_log_files.cpp
        test_design_in_memory_file_system.cpp
        test_has_only_unique_chars.cpp
        test_are_permutations.cpp
        test_urlify_string.cpp
        test_is_palindrom_permutation.cpp
        test_longest_palindrome_from_two_letter_words.cpp)

target_link_libraries(test_fun_with_strings GTest::GTest GTest::Main pthread)
add_test(NAME FunWithStringsTests COMMAND test_fun_with_strings)
