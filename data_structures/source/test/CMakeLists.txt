cmake_minimum_required(VERSION 3.20)
project(test_data_structures)

find_package(GTest REQUIRED)

include_directories(${CMAKE_SOURCE_DIR})

# Function to create test executables for each subdirectory
function(create_test_executable_for_subdir subdir)
    file(GLOB_RECURSE TEST_SOURCES "${subdir}/test_*.cpp")

    if (TEST_SOURCES)
        get_filename_component(TEST_NAME ${subdir} NAME)
        add_executable(${TEST_NAME}_tests ${TEST_SOURCES})

        # Link against all found libraries
        foreach (LIB_DIR ${LIBRARY_DIRECTORIES})
            get_filename_component(LIB_NAME ${LIB_DIR} NAME)
            set(TARGET_LIB "${LIB_NAME}_lib")
            target_link_libraries(${TEST_NAME}_tests ${TARGET_LIB})
        endforeach ()

        # Link Google Test and pthread
        target_link_libraries(${TEST_NAME}_tests ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES} pthread)

        # Register the test executable with CTest
        add_test(NAME ${TEST_NAME}_tests COMMAND ${TEST_NAME}_tests)
    endif ()
endfunction()

# Get all subdirectories in the test folder
file(GLOB TEST_SUBDIRS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/*)

# Create a test executable for each subdirectory
foreach (SUBDIR ${TEST_SUBDIRS})
    if (IS_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/${SUBDIR})
        create_test_executable_for_subdir(${CMAKE_CURRENT_SOURCE_DIR}/${SUBDIR})
    endif ()
endforeach ()
