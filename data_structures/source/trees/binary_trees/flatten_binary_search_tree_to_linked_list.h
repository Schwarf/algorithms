//
// Created by andreas on 04.08.22.
//

#ifndef FLATTEN_BINARY_SEARCH_TREE_TO_LINKED_LIST_H
#define FLATTEN_BINARY_SEARCH_TREE_TO_LINKED_LIST_H
#include "tree_node.h"

/*
     TreeNode * get_right_most(TreeNode* root)
    {
        if(!root->right)
            return root;
        return get_right_most(root->right);
    }

    void flatten(TreeNode* root) {
        if (!root)
            return;
        TreeNode * right_most;
        TreeNode * right_tree;
        while(root)
        {
            if(root->left)
            {
                right_tree = root->right;
                root->right = root->left;
                right_most = get_right_most(root->right);
                right_most->right = right_tree;
                root->left = nullptr;
            }
            root = root->right;
        }

    }

  */
template<typename T>
TreeNode<T> *get_right_most(TreeNode<T> *root)
{
	if (!root->right)
		return root;
	return get_right_most(root->right);
}

template<typename T>
void flatten_to_linked_list(TreeNode<T> *root)
{
	if (!root)
		return;
	TreeNode<T> *right_most;
	TreeNode<T> *right_tree;
	while (root) {
		if (root->left) {
			right_tree = root->right;
			root->right = root->left;
			right_most = get_right_most(root->right);
			right_most->right = right_tree;
			root->left = nullptr;
		}
		root = root->right;
	}
}

#endif //FLATTEN_BINARY_SEARCH_TREE_TO_LINKED_LIST_H
