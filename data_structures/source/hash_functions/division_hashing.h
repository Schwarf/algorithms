//
// Created by andreas on 18.02.22.
//

#ifndef DIVISION_METHOD_H
#define DIVISION_METHOD_H
#include "good_primes.h"
#include "i_hash_function.h"

template<size_t expected_number_of_entries>
class DivisionHashing: public IHashFunction
{
public:
	DivisionHashing(size_t modulo_prime = 0)
	{
		if (expected_number_of_entries > Primes::good_primes[Primes::number_of_good_primes - 1]) {
			throw std::out_of_range(
				"In DivisionHashing: The expected_number_of_entries is greater than the greatest prime number available!");
		}
		size_t prime_index{};

		if (modulo_prime) {
			modulo_prime_ = modulo_prime;
			return;
		}
		for (prime_index = 0; prime_index < Primes::number_of_good_primes; ++prime_index) {
			if (expected_number_of_entries < Primes::good_primes[prime_index])
				break;
		}
		modulo_prime_ = Primes::good_primes[prime_index];
	}
	size_t hash(size_t value) const override
	{
		return value % modulo_prime_;
	}

	size_t prime_number() const final
	{
		return modulo_prime_;
	}
private:
	size_t modulo_prime_;
};


#endif //DIVISION_METHOD_H
