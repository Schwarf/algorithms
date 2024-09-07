cmake_minimum_required(VERSION 3.22)
project(fun_with_strings)

include(CheckCXXCompilerFlag)
set(CMAKE_CXX_STANDARD 20)

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
        knuth_morris_pratt_algo.h
        compare_version_numbers.h)
