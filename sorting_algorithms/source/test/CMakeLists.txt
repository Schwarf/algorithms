# 'Google_test' is the subproject name
project(Google_tests)

# 'lib' is the folder with Google Test sources
add_subdirectory(google_test_lib)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

# 'Google_Tests_run' is the target name
# 'test1.cpp tests2.cpp' are source files with tests
add_executable(sorting_tests test_insertion_sort.cpp sorting_setup.h test_selection_sort.cpp test_merge_sort.cpp test_main.cpp test_shell_sort.cpp test_quick_sort.cpp)
target_link_libraries(sorting_tests gtest gtest_main)
target_link_libraries(sorting_tests sorting_lib)