//
// Created by andreas on 28.06.25.
//

#ifndef SERIALIZE_DESERIALIZE_BINARY_TREE_H
#define SERIALIZE_DESERIALIZE_BINARY_TREE_H

#include <string>
#include <sstream>
#include "tree_node.h"

template <typename T>
void serialize(TreeNode<T>* root, std::string& output)
{
    if (!root)
    {
        output += "#,";
        return;
    }

    output += std::to_string(root->value) + ",";
    serialize(root->left, output);
    serialize(root->right, output);
}

template <typename T>
std::string serialize_tree(TreeNode<T>* root)
{
    std::string output;
    serialize(root, output);
    return output;
}

template <typename T>
TreeNode<T>* deserialize(std::string& input, int &pos)
{
    int next_comma = input.find(',', pos);
    std::string token = input.substr(pos, next_comma - pos);
    pos = next_comma + 1; // advance past the comma

    // 2) Null marker?
    if (token == "#")
        return nullptr;

    T value = static_cast<T>(std::stoll(token));
    auto node = new TreeNode<T>(value);
    // 4) Recurse
    node->left = deserialize<T>(input, pos);
    node->right = deserialize<T>(input, pos);
    return node;
}

template <typename T>
TreeNode<T>* deserialize_tree(std::string& data)
{
    int pos = 0;
    return deserialize<T>(data, pos);
}
#endif //SERIALIZE_DESERIALIZE_BINARY_TREE_H
