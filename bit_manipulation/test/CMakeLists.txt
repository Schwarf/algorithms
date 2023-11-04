project(test_bit_manipulation)

# 'lib' is the folder with Google Test sources
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

include_directories(./../)
enable_testing()
add_executable(test_bit_manipulation
        test_basic_bit_operations.cpp
        test_insert_bit_sequence_into_bitstring.cpp
        test_find_unique_numbers_in_arrays.cpp test_counting_bits.cpp test_sort_according_to_hamming_weight.cpp)


target_link_libraries(test_bit_manipulation ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES} pthread)