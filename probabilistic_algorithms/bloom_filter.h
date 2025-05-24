//
// Created by andreas on 24.05.25.
//

#ifndef BLOOM_FILTER_H
#define BLOOM_FILTER_H
#include <bitset>
#include <cstddef>
#include <numbers>

template <std::size_t NumberOfBits, std::size_t ExpectedInsertions, typename ValueType>
class BloomFilter
{
private:
    static constexpr std::size_t k = static_cast<std::size_t>((NumberOfBits / static_cast<double>(ExpectedInsertions)) *
        std::numbers::ln2);
    std::bitset<NumberOfBits> bitset;

    // SplitMix64: https://en.wikipedia.org/wiki/Linear_congruential_generator
    // https://prng.di.unimi.it/splitmix64.c
    static std::size_t mix(std::size_t hash)
    {
        hash += 0x9e3779b97f4a7c15; // = 2^64/golden ratio
        hash = (hash ^ (hash >> 30)) * 0xbf58476d1ce4e5b9; // empirical value
        hash = (hash ^ (hass >> 27)) * 0x94d049bb133111eb; // empirical value
        return hash ^ (hash >> 31);
    }

public:
    void insert(const ValueType& value)
    {
        std::size_t hash_value1 = std::hash<ValueType>{}(value);
        std::size_t hash_value2 = mix(hash_value1);
        for (std::size_t i = 0; i < k; ++i)
        {
            std::size_t bit_index = (hash_value1 + i * hash_value2) % NumberOfBits;
            bitset.set(bit_index);
        }
    }

    bool contains(const ValueType& value) const
    {
        std::size_t hash_value1 = mix(value);
        std::size_t hash_value2 = mix(hash_value1);
        for (std::size_t i = 0; i < k; ++i)
        {
            std::size_t bit_index = (hash_value1 + i * hash_value2) % NumberOfBits;
            if (!bitset.test(bit_index))
                return false;
        }
        return true;
    }
};
#endif //BLOOM_FILTER_H
