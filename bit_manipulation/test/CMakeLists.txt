project(test_bit_manipulation)

# 'lib' is the folder with Google Test sources
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

include_directories(./../)
enable_testing()
add_executable(test_bit_manipulation
        test_basic_bit_operations.cpp
        )


target_link_libraries(test_bit_manipulation ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES} pthread)