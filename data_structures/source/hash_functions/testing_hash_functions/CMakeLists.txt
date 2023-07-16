project(hash_function_tests)

# 'lib' is the folder with Google Test sources
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

include_directories(./../)

add_executable(test_hash_functions test_hash_function_for_pairs.cpp)
enable_testing()

target_link_libraries(test_hash_functions ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES} pthread)