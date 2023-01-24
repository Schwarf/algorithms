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

int rabin_karp(const std::string & pattern, const std::string & input)
{
    size_t pattern_hash = hash(pattern);
    size_t search_hash{};
    size_t power{1};

    for(int i{}; i < pattern.size(); ++i)
        power = power*BASE % MOD;

    for(int i{}; i < input.size(); ++i)
    {
        search_hash = search_hash*BASE + input[i];
        search_hash %= MOD;
    }
}

#endif //DATA_STRUCTURES_RABIN_KARP_SAMPLE_H
