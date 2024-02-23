//
// Created by andreas on 23.02.24.
//

#ifndef MFU_CACHE_H
#define MFU_CACHE_H
#include <list>
#include <unordered_map>
#include <optional>

template<typename KeyType, typename ValueType>
class MRUCache
{
private:
	struct Node
	{
		KeyType key;
		ValueType value;
	};

public:
	explicit MRUCache(int capacity)
		: capacity(capacity)
	{}

	std::optional<ValueType> get(KeyType key)
	{
		const auto it = key_to_iterator.find(key);
		if (it == key_to_iterator.cend())
			return std::nullopt;

		const auto &listIt = it->second;
		// Move it to the front
		cache.splice(cache.end(), cache, listIt);
		return listIt->value;
	}

	void put(KeyType key, ValueType value)
	{
		// No capacity issue, just update the value
		const auto it = key_to_iterator.find(key);
		if (it != key_to_iterator.cend()) {
			const auto &listIt = it->second;
			// Move it to the end, the most recently used position is the last
			cache.splice(end(cache), cache, listIt);
			listIt->value = value;
			return;
		}

		// Check the capacity
		if (cache.size() == capacity) {
			auto &firstNode = cache.front();
			// We store key in node to erase it
			key_to_iterator.erase(firstNode.key);
			cache.pop_front();
		}

		cache.emplace_back(key, value);
		key_to_iterator[key] = --cache.end();
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

#endif //MFU_CACHE_H
