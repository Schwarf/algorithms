//
// Created by andreas on 23.05.23.
//

#ifndef LRU_CACHE_H
#define LRU_CACHE_H
#include <list>
#include <unordered_map>
#include <optional>

template <typename KeyType, typename ValueType>
class LRUCache
{
private:
    struct Node
    {
        KeyType key;
        ValueType value;
    };

public:
    explicit LRUCache(int capacity)
        : capacity(capacity)
    {
        if (capacity <= 0)
            throw std::invalid_argument("Capacity must be positive");
    }

    std::optional<ValueType> get(const KeyType & key)
    {
        if (auto it = key_to_iterator.find(key) ; it != key_to_iterator.end())
        {
            const auto& listIt = it->second;
            // Move it to the front
            cache.splice(cache.begin(), cache, listIt);
            return listIt->value;
        }
        return std::nullopt;
    }

    void put(const KeyType & key, ValueType value)
    {
        // No capacity issue, just update the value
        if (auto it = key_to_iterator.find(key); it != key_to_iterator.cend())
        {
            const auto& listIt = it->second;
            // Move it to the front
            cache.splice(begin(cache), cache, listIt);
            listIt->value = value;
            return;
        }

        // Check the capacity
        if (cache.size() == capacity)
        {
            auto& lastNode = cache.back();
            // We store key in node to erase it
            key_to_iterator.erase(lastNode.key);
            cache.pop_back();
        }

        cache.emplace_front(key, value);
        key_to_iterator[key] = cache.begin();
    }

    [[nodiscard]] size_t size() const
    {
        return cache.size();
    }

private:
    const int capacity;
    std::list<Node> cache;
    std::unordered_map<KeyType, typename std::list<Node>::iterator> key_to_iterator;
};


#endif //LRU_CACHE_H
