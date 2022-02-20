

add_library(hash_functions_lib INTERFACE
        good_primes.h
        division_hashing_for_strings.h
        i_hash_function_for_strings.h
        multiplication_hashing_for_strings.h
        )

add_library(test_hash_function_lib INTERFACE
        testing_hash_functions/test_hash_functions.h
        )