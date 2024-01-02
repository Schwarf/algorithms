//
// Created by andreas on 02.01.24.
//

#ifndef LFU_CACHE_H
#define LFU_CACHE_H
// least frequently used cache
#include <unordered_map>
#include <list>
#include <optional>

template<typename KeyType, typename ValueType>
class LFUCache
{
private:
	struct Node
	{
		KeyType key;
		ValueType value;
		int frequency;
	};
	int capacity{};
	int minimal_frequency{};
	std::unordered_map<KeyType, typename std::list<Node>::iterator> key_to_list_iterator;
	std::unordered_map<int, std::list<Node>> frequency_lists;
public:
	explicit LFUCache(int capacity)
		: capacity(capacity), minimal_frequency{}
	{}

	std::optional<ValueType> get(KeyType key)
	{
		// return nullopt if key is not found
		if (key_to_list_iterator.find(key) == key_to_list_iterator.end()) {
			return std::nullopt;
		}
		// get the iterator of the list for the provided key
		auto node_it = key_to_list_iterator[key];
		int frequency = node_it->frequency;
		// Update the frequency, by deleting the old entry (for frequency before) and adding a new one
		// for the new/updated frequency.
		frequency_lists[frequency].erase(node_it);
		frequency++;
		frequency_lists[frequency].push_front(*node_it);
		key_to_list_iterator[key] = frequency_lists[frequency].begin();

		// If minimal frequency entry is empty set a new minimal_frequency
		if (frequency_lists[minimal_frequency].empty()) {
			minimal_frequency = frequency;
		}
		return node_it->value;
	}

	void put(KeyType key, ValueType value)
	{
		if (capacity <= 0)
			return;
		// replace existing value with new one, do not change frequency ?!?, probably dependent
		if (get(key) != std::nullopt) {
			key_to_list_iterator[key]->value = value;
			return;
		}
		// If we are at capacity evict the least frequently used item
		if (key_to_list_iterator.size() >= capacity) {
			auto item_to_evict = frequency_lists[minimal_frequency].back();
			key_to_list_iterator.erase(item_to_evict.key);
			frequency_lists[minimal_frequency].pop_back();
		}
		// Since it is a new item for sure we set minimal frequency to 1
		minimal_frequency = 1;
		frequency_lists[minimal_frequency].push_front({key, value, minimal_frequency});
		key_to_list_iterator[key] = frequency_lists[minimal_frequency].begin();
	}

};

#endif //LFU_CACHE_H
