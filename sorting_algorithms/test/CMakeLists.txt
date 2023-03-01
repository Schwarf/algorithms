project(test_sorting)

#add_subdirectory(google_test_lib)
#include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})


add_executable(sorting_tests
        test_heap_sort.cpp
        test_setup.h test_quick_sort.cpp test_counting_sort.cpp)
#target_link_libraries(sorting_tests gtest gtest_main)
target_link_libraries(sorting_tests ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES} pthread)
