//
// Created by andreas on 12.04.22.
//

#ifndef TRIE_H
#define TRIE_H

#include <memory>
#include <string>
// https://leetcode.com/problems/word-search-ii/

template <size_t alphabet_size>
class Trie
{
    struct TrieNode
    {
        TrieNode* children[alphabet_size];
        bool is_end_of_word{};
    };

public:
    Trie()
    {
        root_ = get_new_node();
    }

    void insert(const std::string& key)
    {
        auto node = root_;
        for (const auto& character : key)
        {
            int trie_index = character;
            if (!node->children[trie_index])
                node->children[trie_index] = get_new_node();
            node = node->children[trie_index];
        }
        node->is_end_of_word = true;
    }

    void remove(const std::string& key)
    {
        remove(root_, key, 0);
    }

    bool search(const std::string& key)
    {
        auto node = root_;
        for (const auto& character : key)
        {
            auto trie_index = static_cast<int>(character);
            if (!node->children[trie_index])
                return false;
            node = node->children[trie_index];
        }
        return node->is_end_of_word;
    }

    bool prefix(const std::string& key)
    {
        auto node = root_;
        for (const auto& character : key)
        {
            auto trie_index = character;
            if (!node->children[trie_index])
                return false;
            node = node->children[trie_index];
        }
        return true;
    }

private:
    bool has_node_children(TrieNode* node)
    {
        for (int i{}; i < alphabet_size; i++)
            if (node->children[i])
                return true;
        return false;
    }

    TrieNode* remove(TrieNode* node, const std::string& key, size_t depth)
    {
        if (!node)
            return nullptr;
        if (depth == key.size())
        {
            if (node->is_end_of_word)
                node->is_end_of_word = false;
            if (has_node_children(node) == false)
            {
                delete (node);
                node = nullptr;
            }
            return node;
        }
        auto trie_index = static_cast<size_t>(key[depth]);
        node->children[trie_index] = remove(node->children[trie_index], key, depth + 1);
        if (has_node_children(node) == false && node->is_end_of_word == false)
        {
            delete node;
            node = nullptr;
        }
        return node;
    }

    TrieNode* get_new_node()
    {
        auto new_node = new TrieNode();
        for (size_t index = 0; index < alphabet_size; ++index)
            new_node->children[index] = nullptr;
        return new_node;
    }

    TrieNode* root_;
};

struct TrieMinimal
{
};


#endif //TRIE_H
