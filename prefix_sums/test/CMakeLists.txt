cmake_minimum_required(VERSION 3.20)
project(prefix_sums_tests)

cmake_policy(VERSION 3.20)

find_package(GTest REQUIRED)

include_directories(${CMAKE_SOURCE_DIR})


file(GLOB_RECURSE TEST_SOURCES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "test_*.cpp")

foreach (TEST_SOURCE ${TEST_SOURCES})
    # Get a filename without an extension for the target name
    get_filename_component(TEST_NAME ${TEST_SOURCE} NAME_WE)

    # Create an executable target for each test file
    add_executable(${TEST_NAME} ${TEST_SOURCE}
            test_number_of_subarrays.cpp)
    # Add libraries
    foreach (LIB_DIR ${LIBRARY_DIRECTORIES})
        get_filename_component(LIB_NAME ${LIB_DIR} NAME)
        set(TARGET_LIB "${LIB_NAME}_lib")
        target_link_libraries(${TEST_NAME} ${TARGET_LIB})
    endforeach ()
    # Link libraries or set properties for each target
    target_link_libraries(${TEST_NAME} ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES} pthread)
endforeach ()

