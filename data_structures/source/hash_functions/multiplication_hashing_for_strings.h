//
// Created by andreas on 18.02.22.
//

#ifndef MULTIPLICATION_HASHING_FOR_STRINGS_H
#define MULTIPLICATION_HASHING_FOR_STRINGS_H
#include <cmath>

template<size_t base_number>
class MultiplicationHashing: public IHashFunction
{
public:
	MultiplicationHashing() = default;
	size_t hash(const std::string & string) const final
	{
		size_t hash_value{};
		for (size_t index = string.size(); index--;) {
			 hash_value = std::fmod(golden_ratio_minus_one_ * (base_number * hash_value + string[index]),1.0);
		}
		return hash_value;

	}
	size_t prime_number() const final
	{
		return 0;
	}

private:
	double golden_ratio_minus_one_{0.618033988749894};
	size_t multiplication_constant_{};
	size_t word_size_factor_{};

};

#endif //MULTIPLICATION_HASHING_FOR_STRINGS_H
