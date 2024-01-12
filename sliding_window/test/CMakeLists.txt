
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
include_directories(./../)
add_executable(sliding_window_test
        test_number_of_substrings.cpp)


target_link_libraries(sliding_window_test ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES} pthread)