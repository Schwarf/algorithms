//
// Created by andreas on 02.08.22.
//

#ifndef LRU_CACHE_H
#define LRU_CACHE_H
#include <unordered_map>
#include <list>

template<typename key_T, typename value_T>
class LRUCache
{
public:
	LRUCache(size_t cache_size){
	}

private:
	using key_value_pair = std::pair<key_T, value_T>;
	std::list<key_value_pair> key_value_list_;
	std::unordered_map<key_T, value_T> cache_;
	size_t cache_size_;
};

#endif //LRU_CACHE_H
