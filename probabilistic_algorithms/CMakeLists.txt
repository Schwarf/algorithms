project(probabilistic_algorithms)

add_subdirectory(test)

add_executable(probabilistic_algorithms
                main.cpp
                reservoir_sampling.h
                held_karp_algorithm.h
                simulated_annealing.h
                used_concepts.h
                simulated_annealing_full_templated.h
                traveling_salesman_functors.h
                bloom_filter.h)
#add_executable(sample templating_with_functions.cpp)
