//
// Created by andreas on 18.02.22.
//

#ifndef MULTIPLICATION_HASHING_FOR_STRINGS_H
#define MULTIPLICATION_HASHING_FOR_STRINGS_H
#include <cmath>
#include "i_hash_function_for_strings.h"

template <size_t base_number, size_t multiplication_constant>
class MultiplicationHashing : public IHashFunction
{
public:
    MultiplicationHashing() = default;

    size_t hash(const std::string& string) const final
    {
        double hash_value{};
        for (size_t index = string.size(); index--;)
        {
            hash_value =
                std::fmod(golden_ratio_minus_one_ * (base_number * hash_value + char_to_unsigned(string.at(index))),
                          1.0);
        }
        hash_value *= multiplication_constant;
        return static_cast<size_t>(hash_value);
    }

    size_t prime_number() const final
    {
        return 0;
    }

private:
    double golden_ratio_minus_one_{0.618033988749894};
};

#endif //MULTIPLICATION_HASHING_FOR_STRINGS_H
