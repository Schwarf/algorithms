project(test_fun_with_arrays)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})


add_executable(fun_with_arrays_tests
        test_contiguous_array.cpp)

include_directories(./../)
target_link_libraries(fun_with_arrays_tests ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES} pthread)

