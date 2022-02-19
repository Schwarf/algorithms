//
// Created by andreas on 18.02.22.
//

#ifndef MULTIPLICATION_HASHING_H
#define MULTIPLICATION_HASHING_H
#include <cmath>

template<size_t machine_word_size, size_t number_of_most_significant_bits>
class MultiplicationHashing: public IHashFunction
{
public:
	MultiplicationHashing()
	{
		// find an integer s in that way that the ratio s/2^word_size ~ one_minus_golden_ratio
		if(machine_word_size > 63)
		{
			throw std::out_of_range("The maximal machine_word_size is 63. Given is "+ std::to_string(machine_word_size));
		}
		word_size_factor_ = static_cast<size_t>(std::pow(2, machine_word_size));
		multiplication_constant_ = static_cast<size_t>( word_size_factor_ * golden_ratio_minus_one_);

	}
	size_t hash(size_t value) const override
	{
		auto word_size_factor_coefficient = static_cast<size_t> (multiplication_constant_ * value / word_size_factor_);
		size_t rest = multiplication_constant_ * value - word_size_factor_coefficient * word_size_factor_;
		size_t bit_shift = machine_word_size - number_of_most_significant_bits;
		return (rest >> bit_shift);
	}

private:
	double golden_ratio_minus_one_{0.618033988749894};
	size_t multiplication_constant_{};
	size_t word_size_factor_{};

};

#endif //MULTIPLICATION_HASHING_H
