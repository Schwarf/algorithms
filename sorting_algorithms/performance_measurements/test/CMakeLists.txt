project(test_performance_measurements)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})


add_executable(performance_measurement_tests
        test_performance_measurements.cpp
        )

include_directories(./../)
target_link_libraries(performance_measurement_tests ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES} pthread)
