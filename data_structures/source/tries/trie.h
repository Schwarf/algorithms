//
// Created by andreas on 12.04.22.
//

#ifndef TRIE_H
#define TRIE_H
#include <memory>
#include <string>


template <size_t alphabet_size>
struct TrieNode
{
	TrieNode * children[alphabet_size];
	bool is_end_of_word{};
};


template <size_t alphabet_size>
class Trie
{
public:
	Trie()
	{
		root_ = get_new_node();
	}
	void insert(const std::string & key)
	{
		auto node = root_;
		for(size_t index=0; index < key.size(); ++index)
		{
			int trie_index = key[index] - 'a';
			if(!node->children[trie_index])
			{
				node->children[trie_index] = get_new_node();
			}
			node = node->children[trie_index];
		}
		node->is_end_of_word = true;
	}

	bool search(const std::string & key)
	{
		auto node = root_;
		for(size_t index=0; index < key.size(); ++index) {
			int trie_index = key[index] - 'a';
			if(!node->children[trie_index])
				return false;
			node = node->children[trie_index];
		}
		return node->is_end_of_word;
	}

	bool prefix(const std::string & key)
	{
		auto node = root_;
		for(size_t index=0; index < key.size(); ++index) {
			int trie_index = key[index] - 'a';
			if(!node->children[trie_index])
				return false;
			node = node->children[trie_index];
		}
		return true;
	}

private:
	TrieNode<alphabet_size> * get_new_node()
	{
		auto new_node = new TrieNode<alphabet_size>();
		for(size_t index=0; index < alphabet_size; ++index)
		{
			new_node->children[index] = nullptr;
		}
		return new_node;
	}
	TrieNode<alphabet_size> * root_;
};




#endif //TRIE_H
