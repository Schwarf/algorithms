project(test_sorting)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})


add_executable(sorting_tests
        test_heap_sort.cpp
        test_setup.h test_quick_sort.cpp test_counting_sort.cpp test_merge_sort.cpp test_insertion_sort.cpp test_selection_sort.cpp)

include_directories(./../)
target_link_libraries(sorting_tests ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES} pthread)
