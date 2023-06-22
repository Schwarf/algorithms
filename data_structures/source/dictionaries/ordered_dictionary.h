//
// Created by andreas on 22.06.23.
//

#ifndef ORDERED_DICTIONARY_H
#define ORDERED_DICTIONARY_H
#include <unordered_map>
#include <type_traits>

template<typename T>
concept Hashable = requires(T t)
{
	{ std::hash<T>(t) }-> std::same_as<std::size_t>;
};

template<typename KeyType, typename ValueType>

struct OrderedDictionaryNode
{
	KeyType key;
	ValueType value;
	OrderedDictionaryNode<KeyType, ValueType> *prev;
	OrderedDictionaryNode<KeyType, ValueType> *next;
};

template<typename KeyType, typename ValueType> requires Hashable<KeyType>
class OrderedDictionary
{
public:
	void insert(KeyType key, ValueType value)
	{
		if (hashmap.find(key) != hashmap.end())
			hashmap[key]->value = value;
	}

private:
	std::unordered_map<KeyType, ValueType> hashmap;
	OrderedDictionaryNode<KeyType, ValueType> head{nullptr};
	OrderedDictionaryNode<KeyType, ValueType> prev{nullptr};
};

#endif //ORDERED_DICTIONARY_H
