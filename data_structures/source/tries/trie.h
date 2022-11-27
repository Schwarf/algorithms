//
// Created by andreas on 12.04.22.
//

#ifndef TRIE_H
#define TRIE_H
#include <memory>
#include <string>
// https://leetcode.com/problems/word-search-ii/


template<size_t alphabet_size>
struct TrieNode
{
	TrieNode *children[alphabet_size];
	bool is_end_of_word{};
};

template<size_t alphabet_size>
class Trie
{
public:
	Trie()
	{
		root_ = get_new_node();
	}
	void insert(const std::string &key)
	{
		auto node = root_;
		for (size_t index = 0; index < key.size(); ++index) {
			int trie_index = key[index] - '0';
			if (!node->children[trie_index])
				node->children[trie_index] = get_new_node();
			node = node->children[trie_index];
		}
		node->is_end_of_word = true;
	}
	bool remove(const std::string &key)
	{
		return remove(root_, key, 0) != nullptr;
	}

	bool search(const std::string &key)
	{
		auto node = root_;
		for (size_t index = 0; index < key.size(); ++index) {
			int trie_index = key[index] - '0';
			if (!node->children[trie_index])
				return false;
			node = node->children[trie_index];
		}
		return node->is_end_of_word;
	}

	bool prefix(const std::string &key)
	{
		auto node = root_;
		for (size_t index = 0; index < key.size(); ++index) {
			int trie_index = key[index] - '0';
			if (!node->children[trie_index])
				return false;
			node = node->children[trie_index];
		}
		return true;
	}

private:
	bool has_node_children(TrieNode<alphabet_size> *node)
	{
		for (int i{}; i < alphabet_size; i++)
			if (node->children[i])
				return true;
		return false;
	}
	TrieNode<alphabet_size> *remove(const std::string &key, int depth = 0)
	{
		auto node = root_;
		if (depth == key.size()) {

		}
		else {
			int trie_index = key[depth] - '0';
			node->children[trie_index] = remove();
		}
	}

	TrieNode<alphabet_size> *remove(TrieNode<alphabet_size> *node, const std::string &key, size_t depth)
	{
		if (!node)
			return nullptr;
		if (depth == key.size()) {
			if (node->is_end_of_word)
				node->is_end_of_word = false;
			if (node_has_children(node) == false) {
				delete (node);
				node = nullptr;
			}
			return node;
		}
		int trie_index = key[depth] - '0';
		node->children[trie_index] = remove(node->children[trie_index], key, depth + 1);
		if (has_node_children(node) == false && node->is_end_of_word == false) {
			delete node;
			node = nullptr;
		}
		return node;
	}

	TrieNode<alphabet_size> *get_new_node()
	{
		auto new_node = new TrieNode<alphabet_size>();
		for (size_t index = 0; index < alphabet_size; ++index)
			new_node->children[index] = nullptr;
		return new_node;
	}
	TrieNode<alphabet_size> *root_;
};


#endif //TRIE_H
