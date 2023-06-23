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
	{ std::hash<T>{}(t) }-> std::same_as<std::size_t>;
};

template<typename T>
concept OptionalType = std::same_as<T, std::optional<typename T::value_type>>;

template<typename KeyType, typename ValueType> requires OptionalType<ValueType>
struct OrderedDictionaryNode
{
	OrderedDictionaryNode(const KeyType &k, const ValueType &v)
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
	~OrderedDictionary()
	{
		auto current = head;
		while (current) {
			auto next = current->next;
			delete current;
			current = next;
		}
	}
	void insert(const KeyType &key, const ValueType &value)
	{
		if (hashmap.find(key) != hashmap.end()) {
			hashmap[key]->value = value;
			return;
		}
		auto new_node = new OrderedDictionaryNode<KeyType, ValueType>(key, value);
		if (head == nullptr) {
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
		if (hashmap.find(key) == hashmap.end())
			return std::nullopt;
		auto node = hashmap[key];
		return node->value;
	}

	ValueType front()
	{
		if (head == nullptr)
			return std::nullopt;
		return head->value;
	}

	ValueType back()
	{
		if (tail == nullptr)
			return std::nullopt;
		return tail->value;
	}

	void pop_front()
	{
		if (head) {
			auto node = head;
			head = head->next;
			if (head)
				head->prev = nullptr;
			else
				tail = nullptr;
			hashmap.erase(node->key);
			delete node;
		}
	}

	void pop_back()
	{
		if (tail) {
			auto node = tail;
			tail = tail->prev;
			if (tail)
				tail->next = nullptr;
			else
				head = nullptr;
			hashmap.erase(node->key);
			delete node;
		}
	}


private:
	std::unordered_map<KeyType, OrderedDictionaryNode<KeyType, ValueType> *> hashmap;
	OrderedDictionaryNode<KeyType, ValueType> *head{nullptr};
	OrderedDictionaryNode<KeyType, ValueType> *tail{nullptr};
	ValueType invalid_value_;
};

#endif //ORDERED_DICTIONARY_H
