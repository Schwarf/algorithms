//
// Created by andreas on 02.01.24.
//

#ifndef LFU_CACHE_H
#define LFU_CACHE_H
// least frequently used cache
#include <unordered_map>
#include <list>

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
	int capacity;
	int minimal_frequency;
	std::unordered_map<KeyType, typename std::list<Node>::iterator> key_to_iterator;
	
};

#endif //LFU_CACHE_H
