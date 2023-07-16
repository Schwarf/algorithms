add_subdirectory(testing_hash_functions)

add_library(hash_functions_lib INTERFACE
        good_primes.h
        division_hashing_for_strings.h
        i_hash_function_for_strings.h
        multiplication_hashing_for_strings.h
        rabin_karp_sample.h
        hash_function_for_pairs.h)

add_library(test_hash_function_lib INTERFACE
        testing_hash_functions/uniformity_of_hash_functions.h
        testing_hash_functions/uniformity_of_pair_hash_functions.h)