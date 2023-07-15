//
// Created by andreas on 15.07.23.
//

#ifndef HASH_FUNCTION_FOR_PAIRS_H
#define HASH_FUNCTION_FOR_PAIRS_H
#include <utility>
#include <functional>
// Weak pair hash that has is commutative
struct commutative_pair_hash
{
	template<class T1, class T2>
	std::size_t operator()(const std::pair<T1, T2> &pair) const
	{
		auto h1 = std::hash<T1>{}(pair.first);
		auto h2 = std::hash<T2>{}(pair.second);
		return h1 ^ h2;
	}
};

#endif //HASH_FUNCTION_FOR_PAIRS_H
