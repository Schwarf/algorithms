find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
add_executable(fun_with_strings_test test_remove_duplicates.cpp)
target_link_libraries(fun_with_strings_test ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES} pthread)
