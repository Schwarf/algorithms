//
// Created by andreas on 20.02.22.
//

#ifndef GENERATE_PRIMES_IN_RANGE_H
#define GENERATE_PRIMES_IN_RANGE_H
#include <fstream>
#include <vector>

std::vector<bool> sieve_of_sundaram(size_t n)
{
    size_t k = (n - 1) / 2;
    auto is_prime_number_list = std::vector<bool>(k + 1, true);
    size_t index1{};
    size_t index2{};
    for (index1 = 1; index1 < k + 1; index1++)
    {
        index2 = index1;
        while (index1 + index2 + 2 * index1 * index2 <= k)
        {
            is_prime_number_list[index1 + index2 + 2 * index1 * index2] = false;
            index2++;
        }
    }
    return is_prime_number_list;
}


void generate_prime_numbers_up_to(size_t n)
{
    auto sieve = sieve_of_sundaram(n);
    std::fstream file;
    file.open("./../miscellaneous/prime_numbers.txt", std::ios::out);
    size_t index{};
    size_t k = (n - 1) / 2;
    if (file.is_open())
    {
        file << 2 << "\n";
        for (index = 1; index <= k; index++)
        {
            if (sieve[index])
            {
                file << 2 * index + 1 << "\n";
            }
        }
        file.close();
    }
}

#endif //GENERATE_PRIMES_IN_RANGE_H
