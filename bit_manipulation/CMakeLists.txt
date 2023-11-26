cmake_minimum_required(VERSION 3.24)
project(bit_manipulation)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(test)

add_executable(bit_manipulation main.cpp
        basic_bit_operations.h
        insert_bit_sequence_into_bitstring.h
        find_unique_number_in_arrays.h counting_bits.h sort_according_to_hamming_weight.h find_original_array_XOR.h integer_division.h)
