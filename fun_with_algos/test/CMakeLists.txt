project(test_fun_with_algos)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})


add_executable(test_fun_with_algos
        test_get_majority_element.cpp)

include_directories(./../)
target_link_libraries(test_fun_with_algos ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES} pthread)
