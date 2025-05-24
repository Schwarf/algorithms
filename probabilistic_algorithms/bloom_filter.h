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
    static constexpr std::size_t k = static_cast<std::size_t>((NumberOfBits / static_cast<double>(ExpectedInsertions)) * std::numbers::ln2);
    std::bitset<NumberOfBits> bitset;

}
#endif //BLOOM_FILTER_H
