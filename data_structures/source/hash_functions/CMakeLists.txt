

add_library(hash_functions_lib INTERFACE
        good_primes.h
        division_hashing.h
        i_hash_function.h
        multiplication_hashing.h
        )

add_library(test_hash_function_lib
        testing_hash_functions/test_hash_functions.h
        testing_hash_functions/test_hash_functions.cpp)