//
// Created by andreas on 24.03.24.
//

#ifndef FIXED_SIZE_HASHMAP_H
#define FIXED_SIZE_HASHMAP_H
#include "used_concepts.h"
#include <array>
#include <stdexcept>

template <typename KeyType, typename ValueType, size_t Capacity> requires is_hashable<KeyType>
class FixedSizeHashmap
{
public:
    void insert(const KeyType& key, const ValueType& value)
    {
        auto index = get_hash(key);
        // Use open addressing for collisions with linear probing
        for (size_t i{}; i < Capacity; ++i)
        {
            size_t try_index = (index + i) % Capacity;
            if (!map[try_index].has_value() || map[try_index]->first == key)
            {
                map[try_index] = std::make_pair(key, value);
                return;
            }
        }
        throw std::overflow_error("Hashmap is full!");
    }

    ValueType get(const KeyType& key)
    {
        auto index = get_hash(key);
        for (size_t i = 0; i < Capacity; ++i)
        {
            size_t tryIndex = (index + i) % Capacity;
            if (map[tryIndex].has_value() && map[tryIndex]->first == key)
            {
                return map[tryIndex]->second;
            }
            else if (!map[tryIndex].has_value())
            {
                // We hit an empty slot before finding our key, so it's not here.
                break;
            }
        }
        throw std::out_of_range("Key not found.");
    }

private:
    std::array<std::optional<std::pair<KeyType, ValueType>>, Capacity> map;

    size_t get_hash(const KeyType& key) const
    {
        return std::hash<KeyType>{}(key) % Capacity; // Collision are still possible --> test it
    }
};
#endif //FIXED_SIZE_HASHMAP_H
