cmake_minimum_required(VERSION 3.24)
project(bit_manipulation)

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

add_executable(bit_manipulation main.cpp
        basic_bit_operations.h
        insert_bit_sequence_into_bitstring.h
        find_unique_number_in_arrays.h
        counting_bits.h
        sort_according_to_hamming_weight.h
        find_original_array_XOR.h
        integer_division.h
        bitwise_and_numbers_in_range.h
        count_operations_to_make_xor_of_array_equal_k.h
        sum_all_xor_subsets.h
        find_two_singular_elements.h
        find_longest_substring_with_even_vowl_count.h
        xor_queries_for_subarrays.h
        can_array_be_sorted.h
        longest_combination_with_bitwise_and.h)
