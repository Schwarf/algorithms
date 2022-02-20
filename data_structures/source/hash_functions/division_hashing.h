//
// Created by andreas on 18.02.22.
//

#ifndef DIVISION_METHOD_H
#define DIVISION_METHOD_H
#include "good_primes.h"
#include "i_hash_function.h"
#include <fstream>
#include <sstream>
#include <vector>

template<size_t expected_number_of_entries>
class DivisionHashing: public IHashFunction
{
public:
	DivisionHashing(size_t modulo_prime = 0)
	{
		if (modulo_prime) {
			modulo_prime_ = modulo_prime;
			return;
		}
		std::fstream prime_number_file;
		prime_number_file.open(prime_numbers_file_path_, std::ios::in);
		std::vector<size_t> last_10_primes(10, 0);
		size_t last_ten_primes_counter{};
		if (prime_number_file.is_open()) {
			std::string line;
			while (std::getline(prime_number_file, line)) {
				size_t prime = std::stol(line);
				if (prime > expected_number_of_entries) {
					break;
				}
				if (last_ten_primes_counter == 10)
					last_ten_primes_counter = 0;
				last_10_primes.at(last_ten_primes_counter) = prime;
				last_ten_primes_counter++;
			}
		}
		modulo_prime_ = last_10_primes.at(7);
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
	size_t modulo_prime_{};
	std::string prime_numbers_file_path_{"./../miscellaneous/prime_numbers.txt"};
};


#endif //DIVISION_METHOD_H
