//
// Created by andreas on 23.05.23.
//

#ifndef LRU_CACHE_H
#define LRU_CACHE_H
#include <list>
#include <unordered_map>
#include <optional>
template<typename KeyType, typename ValueType>
struct Node
{
	KeyType key;
	ValueType value;
	Node(KeyType key, ValueType value)
		: key(key), value(value)
	{}
};

template<typename KeyType, typename ValueType>
class LRUCache
{
public:
	explicit LRUCache(int capacity)
		: capacity(capacity)
	{}

	std::optional<ValueType> get(KeyType key)
	{
		const auto it = keyToIterator.find(key);
		if (it == keyToIterator.cend())
			return std::nullopt;

		const auto &listIt = it->second;
		// Move it to the front
		cache.splice(cache.begin(), cache, listIt);
		return listIt->value;
	}

	void put(KeyType key, ValueType value)
	{
		// No capacity issue, just update the value
		const auto it = keyToIterator.find(key);
		if (it != keyToIterator.cend()) {
			const auto &listIt = it->second;
			// Move it to the front
			cache.splice(begin(cache), cache, listIt);
			listIt->value = value;
			return;
		}

		// Check the capacity
		if (cache.size() == capacity) {
			auto &lastNode = cache.back();
			// We store key in node to erase it
			keyToIterator.erase(lastNode.key);
			cache.pop_back();
		}

		cache.emplace_front(key, value);
		keyToIterator[key] = cache.begin();
	}

private:
	const int capacity;
	std::list<Node<KeyType, ValueType>> cache;
	std::unordered_map<KeyType, typename std::list<Node<KeyType, ValueType>>::iterator> keyToIterator;
};


#endif //LRU_CACHE_H
