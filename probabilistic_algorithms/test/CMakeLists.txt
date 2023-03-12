project(test_sorting)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})


add_executable(probabilistic_algorithm_tests
        test_reservoir_sampling.cpp
        test_held_karp_algorithm.cpp test_simulated_annealing.cpp)

include_directories(./../)
target_link_libraries(probabilistic_algorithm_tests ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES} pthread)

