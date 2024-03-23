//
// Created by andreas on 15.07.23.
//

#ifndef HASH_FUNCTION_FOR_PAIRS_H
#define HASH_FUNCTION_FOR_PAIRS_H
#include <utility>
#include <functional>
// Weak pair hash that has is commutative
template<class T1, class T2>
struct dummy_plus_pair_hash
{
	std::size_t operator()(const std::pair<T1, T2> &pair) const
	{
		auto v1 = static_cast<T1>(pair.second);
		auto h1 = std::hash<T1>{}(pair.first + v1);
		return h1;
	}
};

// Weak pair hash that is commutative
template<class T1, class T2>
struct commutative_pair_hash
{
	std::size_t operator()(const std::pair<T1, T2> &pair) const
	{
		auto h1 = std::hash<T1>{}(pair.first);
		auto h2 = std::hash<T2>{}(pair.second);
		return h1 ^ h2;
	}
};

// Strong hash function that uses the fractional part of the golden ratio \phi = 1.61803398875
// The fractional part of the golden ratio is (sqrt(5)-1)/2 ~= 0.61803398875. If this number is
// multiplied with 2^32 and round down to integer you get 2654435769 which is '0x9e3779b9' in hexadecimal
// representation. Since the golden ratio is irrational and has a decimal part that goes on forever
// a multiplication with it (or the fractional) part spreads out values in 'random' way. In addition, \phi
// has 'poor rational approximation', that means it's hard to approximate with a simple fraction
// which makes it less likely that different inputs will, by coincidence, produce the same output,
// reducing the chance of hash collisions.
template<class T1, class T2>
struct non_commutative_pair_hash
{
	std::size_t operator()(const std::pair<T1, T2> &pair) const
	{
		std::size_t seed{};
		seed ^= std::hash<T1>{}(pair.first) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
		seed ^= std::hash<T2>{}(pair.second) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
		return seed;
	}
};

#endif //HASH_FUNCTION_FOR_PAIRS_H
