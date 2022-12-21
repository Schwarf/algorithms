//
// Created by andreas on 02.08.22.
//

#ifndef LRU_CACHE_H
#define LRU_CACHE_H
#include <unordered_map>
#include <list>
#include <vector>

template<typename key_T, typename value_T>
class LRUCache
{
public:
	LRUCache(size_t cache_size)
		:
		cache_size_(cache_size)
	{
	}

	void put(const key_T & key, const value_T & value)
	{
		auto pair_iterator = cache_.find(key);
		// cache hit, erase item in cache and list
		if(pair_iterator != cache_.end())
		{
			key_value_list_.erase(pair_iterator->second);
			cache_.erase(pair_iterator);
		}
		// put element in front and store
		key_value_list_.push_front(std::make_pair(key, value));
		cache_.insert(std::make_pair(key, key_value_list_.begin()));
		check_cache_size();
	}

	value_T get(key_T key)
	{
		auto pair_iterator = cache_.find(key);
		if(pair_iterator == cache_.end())
			throw std::out_of_range("Element not in cache!");
		key_value_list_.splice(key_value_list_.begin(), key_value_list_, pair_iterator->second);
		return pair_iterator->second->second;
	}

	std::vector<value_T> get_all_values()
	{
		auto result = std::vector<value_T>();
		for(const auto & element : key_value_list_)
		{
			result.push_back(element.second);
		}
		return result;
	}


private:
	void check_cache_size()
	{
		while(cache_.size() > cache_size_)
		{
			auto last_key = key_value_list_.back().first;
			key_value_list_.pop_back();
			cache_.erase(last_key);
		}
	}
	using key_value_pair = std::pair<key_T, value_T>;
	std::list<key_value_pair> key_value_list_;
	// hashtable with key-type and 
	std::unordered_map<key_T, decltype(key_value_list_.begin())> cache_;
	size_t cache_size_;
};

#endif //LRU_CACHE_H
