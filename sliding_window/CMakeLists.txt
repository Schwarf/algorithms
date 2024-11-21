cmake_minimum_required(VERSION 3.25)
project(sliding_window)

set(CMAKE_CXX_STANDARD 20)
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

add_subdirectory(test)

add_executable(sliding_window main.cpp
        number_of_substrings.h
        longest_substring_without_repeating_characters.h
        get_equal_substrings_with_budget.h
        count_subarrays_with_target.h
        find_longest_subarray_with_at_most_k_frequency.h
        count_subarrays_where_max_appears_k_times.h
        count_subarrays_with_exactly_k_different_elements.h
        minimum_swaps_to_group_ones.h
        shortest_subarray_with_sum.h
        max_sum_of_distinct_subarrays_with_given_length.h)


