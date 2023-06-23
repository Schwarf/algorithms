//
// Created by andreas on 22.06.23.
//

#ifndef ORDERED_DICTIONARY_H
#define ORDERED_DICTIONARY_H
#include <unordered_map>
#include <type_traits>
// An ordered dictionary keeps the order of the items inserted

template<typename T>
concept Hashable = requires(T t)
{
	{ std::hash<T>(t) }-> std::same_as<std::size_t>;
};

template<typename KeyType, typename ValueType>
struct OrderedDictionaryNode
{
	OrderedDictionaryNode(const KeyType &k, const KeyType &v)
		: key(k), value(v), prev(nullptr), next(nullptr)
	{}
	KeyType key;
	ValueType value;
	OrderedDictionaryNode<KeyType, ValueType> *prev{nullptr};
	OrderedDictionaryNode<KeyType, ValueType> *next{nullptr};
};

template<typename KeyType, typename ValueType> requires Hashable<KeyType>
class OrderedDictionary
{
public:
	explicit OrderedDictionary(ValueType invalid_value)
		: invalid_value_(invalid_value)
	{}
	void insert(KeyType key, ValueType value)
	{
		if (hashmap.find(key) != hashmap.end()) {
			hashmap[key]->value = value;
			return;
		}
		auto new_node = new OrderedDictionaryNode<KeyType, ValueType>();
		new_node->key = key;
		new_node->value = value;
		if (tail == nullptr) {
			head = new_node;
			tail = new_node;
		}
		else {
			new_node->prev = tail;
			tail->next = new_node;
			tail = new_node;
		}
		hashmap[key] = new_node;
	}

	ValueType get(const KeyType &key)
	{
		if (hashmap.find(key) == hashmap.edn())
			return {};

		auto node = hashmap[key];
		if(node != tail)
			
	}

private:
	std::unordered_map<KeyType, ValueType> hashmap;
	OrderedDictionaryNode<KeyType, ValueType> head{nullptr};
	OrderedDictionaryNode<KeyType, ValueType> tail{nullptr};
	ValueType invalid_value_;
};

#endif //ORDERED_DICTIONARY_H
