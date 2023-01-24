//
// Created by andreas on 24.01.23.
//

#ifndef DATA_STRUCTURES_RABIN_KARP_SAMPLE_H
#define DATA_STRUCTURES_RABIN_KARP_SAMPLE_H
#include <string>

constexpr size_t BASE = 257;
constexpr size_t MOD = 1000000007;

size_t hash(const std::string & input)
{
    size_t value{};
    for(int index{}; index < input.length(); ++index)
    {
        value = value*BASE + input[index];
        value %= MOD;
    }
    return value;
}



#endif //DATA_STRUCTURES_RABIN_KARP_SAMPLE_H
