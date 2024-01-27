cmake_minimum_required(VERSION 3.22)
project(fun_with_strings)

set(CMAKE_CXX_STANDARD 17)
add_subdirectory(test)

add_executable(fun_with_strings main.cpp
        sort_string_by_character_frequency.h
        count_steps_to_make_strings_anagram.h
        levenshtein_distance.h
        create_ranges_from_sorted_array.h
        remove_duplicate_letters.h
        decode_string_at_index.h
        count_beautiful_substrings.h
        are_two_strings_close.h
        knuth_morris_pratt_algo.h)
