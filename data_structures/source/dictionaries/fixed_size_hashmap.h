//
// Created by andreas on 24.03.24.
//

#ifndef FIXED_SIZE_HASHMAP_H
#define FIXED_SIZE_HASHMAP_H
#include "used_concepts.h"
#include <array>
#include <stdexcept>

template<typename KeyType, typename ValueType, size_t Capacity> requires is_hashable<KeyType>
class FixedSizeHashmap
{
public:

	void insert(const KeyType &key, const ValueType &value)
	{
		auto index = get_hash(key);

		map[index] = std::make_pair(key, value);
	}

	ValueType get(const KeyType &key)
	{
		auto index = get_hash(key);
		return map[index].second;
	}

private:
	std::array<std::optional<std::pair<KeyType, ValueType>>, Capacity> map;

	size_t get_hash(const KeyType &key) const
	{
		return std::hash<KeyType>{}(key) % Capacity; // Collision are still possible --> test it
	}

};
#endif //FIXED_SIZE_HASHMAP_H
