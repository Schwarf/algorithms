//
// Created by andreas on 09.05.22.
//

#ifndef SETUP_BINARY_TREE_H
#define SETUP_BINARY_TREE_H

#include "gtest/gtest.h"
#include <vector>
#include "trees/binary_trees/tree_node.h"


class SetupBinaryTree : public testing::Test {
public:
    SetupBinaryTree() = default;

protected:
    std::vector<unsigned int> insertion{25, 15, 50, 10, 22, 35, 70, 4, 12, 18, 24, 31, 44, 66, 90};
    std::vector<unsigned int> inorder{4, 10, 12, 15, 18, 22, 24, 25, 31, 35, 44, 50, 66, 70, 90};
    std::vector<unsigned int> preorder{25, 15, 10, 4, 12, 22, 18, 24, 50, 35, 31, 44, 70, 66, 90};
    std::vector<unsigned int> postorder{4, 12, 10, 18, 24, 22, 15, 31, 44, 35, 66, 90, 70, 50, 25};
    std::vector<std::vector<unsigned int>>
            levelorder{{25},
                       {15, 50},
                       {10, 22, 35, 70},
                       {4,  12, 18, 24, 31, 44, 66, 90}};
    std::vector<std::vector<unsigned int>>
            levelorder_inverted_tree{{25},
                                     {50, 15},
                                     {70, 35, 22, 10},
                                     {90, 66, 44, 31, 24, 18, 12, 4}};
    std::vector<std::vector<unsigned int>> levelorder_small_tree{{3},
                                                                 {9,  20},
                                                                 {15, 7}};
    int depth{4};

    static TreeNode<unsigned int> *inverted_tree() {
        auto root = new TreeNode<unsigned int>(25);
        root->left = new TreeNode<unsigned int>(50);
        root->right = new TreeNode<unsigned int>(15);

        root->left->left = new TreeNode<unsigned int>(70);
        root->left->right = new TreeNode<unsigned int>(35);

        root->right->left = new TreeNode<unsigned int>(22);
        root->right->right = new TreeNode<unsigned int>(10);

        root->left->left->left = new TreeNode<unsigned int>(90);
        root->left->left->right = new TreeNode<unsigned int>(66);

        root->left->right->left = new TreeNode<unsigned int>(44);
        root->left->right->right = new TreeNode<unsigned int>(31);

        root->right->left->left = new TreeNode<unsigned int>(24);
        root->right->left->right = new TreeNode<unsigned int>(18);

        root->right->right->left = new TreeNode<unsigned int>(12);
        root->right->right->right = new TreeNode<unsigned int>(4);

        return root;
    }

    static TreeNode<unsigned int> *binary_tree_root() {
        auto root = new TreeNode<unsigned int>(25);
        root->left = new TreeNode<unsigned int>(15);
        root->right = new TreeNode<unsigned int>(50);

        root->left->left = new TreeNode<unsigned int>(10);
        root->left->right = new TreeNode<unsigned int>(22);

        root->right->left = new TreeNode<unsigned int>(35);
        root->right->right = new TreeNode<unsigned int>(70);

        root->left->left->left = new TreeNode<unsigned int>(4);
        root->left->left->right = new TreeNode<unsigned int>(12);

        root->left->right->left = new TreeNode<unsigned int>(18);
        root->left->right->right = new TreeNode<unsigned int>(24);

        root->right->left->left = new TreeNode<unsigned int>(31);
        root->right->left->right = new TreeNode<unsigned int>(44);

        root->right->right->left = new TreeNode<unsigned int>(66);
        root->right->right->right = new TreeNode<unsigned int>(90);

        return root;
    }

    static TreeNode<unsigned int> *small_binary_tree_root() {
        auto root = new TreeNode<unsigned int>(3);
        root->left = new TreeNode<unsigned int>(9);
        root->right = new TreeNode<unsigned int>(20);
        root->right->left = new TreeNode<unsigned int>(15);
        root->right->right = new TreeNode<unsigned int>(7);
        return root;
    }

    static TreeNode<unsigned int> *inverted_small_binary_tree_root() {
        auto root = new TreeNode<unsigned int>(3);
        root->left = new TreeNode<unsigned int>(20);
        root->right = new TreeNode<unsigned int>(9);
        root->left->left = new TreeNode<unsigned int>(7);
        root->left->right = new TreeNode<unsigned int>(15);
        return root;
    }

    static TreeNode<unsigned int> *small_tree_with_subtree_duplicates() {
        auto root = new TreeNode<unsigned int>(1);
        root->left = new TreeNode<unsigned int>(2);
        root->right = new TreeNode<unsigned int>(2);
        return root;
    }

    static TreeNode<unsigned int> *medium_tree_with_subtree_duplicates1() {
        auto root = new TreeNode<unsigned int>(1);
        root->left = new TreeNode<unsigned int>(2);
        root->right = new TreeNode<unsigned int>(3);
        root->left->left = new TreeNode<unsigned int>(4);
        root->right->left = new TreeNode<unsigned int>(2);
        root->right->left->left = new TreeNode<unsigned int>(4);
        root->right->right = new TreeNode<unsigned int>(4);
        return root;
    }

    static TreeNode<unsigned int> *medium_tree_with_subtree_duplicates2() {
        auto root = new TreeNode<unsigned int>(1);
        root->left = new TreeNode<unsigned int>(2);
        root->right = new TreeNode<unsigned int>(2);
        root->left->left = new TreeNode<unsigned int>(3);
        root->right->left = new TreeNode<unsigned int>(3);
        return root;
    }

    static TreeNode<unsigned int> *medium_tree_with_subtree_duplicates3() {
        auto root = new TreeNode<unsigned int>(2);
        root->left = new TreeNode<unsigned int>(1);
        root->right = new TreeNode<unsigned int>(1);
        root->left->left = new TreeNode<unsigned int>(2);
        root->left->right = new TreeNode<unsigned int>(3);
        root->right->left = new TreeNode<unsigned int>(4);
        root->right->right = new TreeNode<unsigned int>(5);
        return root;
    }

    static TreeNode<unsigned int> *imbalanced_right_tree() {
        auto root = new TreeNode<unsigned int>(2);
        root->right = new TreeNode<unsigned int>(1);
        root->right->left = new TreeNode<unsigned int>(4);
        root->right->right = new TreeNode<unsigned int>(5);
        root->right->right->right = new TreeNode<unsigned int>(12);
        return root;
    }

    static std::pair<TreeNode<unsigned int> *, TreeNode<unsigned int> *> k_distance_tree() {
        auto root = new TreeNode<unsigned int>(3);
        root->left = new TreeNode<unsigned int>(5);
        root->right = new TreeNode<unsigned int>(1);
        root->left->left = new TreeNode<unsigned int>(6);
        root->left->right = new TreeNode<unsigned int>(2);
        root->left->right->left = new TreeNode<unsigned int>(7);
        root->left->right->right = new TreeNode<unsigned int>(4);
        root->right->left = new TreeNode<unsigned int>(0);
        root->right->right = new TreeNode<unsigned int>(8);
        return std::make_pair(root, root->left);
    }

    static std::pair<TreeNode<unsigned int> *, TreeNode<unsigned int> *> k_distance_tree2() {
        auto root = new TreeNode<unsigned int>(3);
        root->left = new TreeNode<unsigned int>(5);
        root->right = new TreeNode<unsigned int>(1);
        root->left->left = new TreeNode<unsigned int>(6);
        root->left->right = new TreeNode<unsigned int>(2);
        root->left->right->left = new TreeNode<unsigned int>(7);
        root->left->right->right = new TreeNode<unsigned int>(4);
        root->right->left = new TreeNode<unsigned int>(0);
        root->right->right = new TreeNode<unsigned int>(8);
        return std::make_pair(root, root->left->right->left);
    }

    static std::vector<std::pair<TreeNode<int> *, int>> trees_maximum_path_sum() {
        std::vector<std::pair<TreeNode<int> *, int >> results;
        auto root1 = new TreeNode<int>(1);
        root1->left = new TreeNode<int>(2);
        root1->right = new TreeNode<int>(3);
        constexpr int result1{6};

        auto root2 = new TreeNode<int>(-10);
        root2->left = new TreeNode<int>(9);
        root2->right = new TreeNode<int>(20);
        root2->right->left = new TreeNode<int>(15);
        root2->right->right = new TreeNode<int>(7);
        constexpr int result2{42};

        auto root3 = nullptr;
        constexpr int result3{0};

        auto root4 = new TreeNode<int>(9);
        root4->left = new TreeNode<int>(-2);
        root4->right = new TreeNode<int>(-8);
        root4->left->left = new TreeNode<int>(25);
        root4->right->left = new TreeNode<int>(15);
        constexpr int result4{39};

        results.push_back({root1, result1});
        results.push_back({root2, result2});
        results.push_back({root3, result3});
        results.push_back({root4, result4});
        return results;
    }

    static TreeNode<int> *infected_tree1() {
        auto root = new TreeNode<int>(1);
        root->right = new TreeNode<int>(3);
        root->right->left = new TreeNode<int>(10);
        root->right->right = new TreeNode<int>(6);
        root->left = new TreeNode<int>(5);
        root->left->right = new TreeNode<int>(4);
        root->left->right->left = new TreeNode<int>(9);
        root->left->right->right = new TreeNode<int>(2);

        return root;
    }

    static TreeNode<int> *infected_tree2() {
        auto root = new TreeNode<int>(1);
        root->left = new TreeNode<int>(2);
        root->right = new TreeNode<int>(3);

        root->left->left = new TreeNode<int>(4);
        root->left->right = new TreeNode<int>(5);

        root->right->left = new TreeNode<int>(6);
        root->right->right = new TreeNode<int>(7);

        root->left->left->left = new TreeNode<int>(8);
        root->left->left->right = new TreeNode<int>(9);

        root->left->right->left = new TreeNode<int>(10);
        root->left->right->right = new TreeNode<int>(11);

        root->right->left->left = new TreeNode<int>(12);
        root->right->left->right = new TreeNode<int>(13);

        root->right->right->left = new TreeNode<int>(14);
        root->right->right->right = new TreeNode<int>(15);

        return root;
    }

    static TreeNode<int> *palindromic_tree1() {
        auto root = new TreeNode<int>(2);
        root->left = new TreeNode<int>(3);
        root->left->right = new TreeNode<int>(1);
        root->left->left = new TreeNode<int>(3);

        root->right = new TreeNode<int>(1);
        root->right->right = new TreeNode<int>(1);
        return root;
    }

    static TreeNode<int> *palindromic_tree2() {
        auto root = new TreeNode<int>(2);
        root->left = new TreeNode<int>(1);
        root->left->right = new TreeNode<int>(3);
        root->left->left = new TreeNode<int>(1);
        root->left->right->left = new TreeNode<int>(1);

        root->right = new TreeNode<int>(1);
        return root;
    }

    static TreeNode<int> *even_odd_tree1() {
        auto root = new TreeNode<int>(1);
        root->left = new TreeNode<int>(10);
        root->right = new TreeNode<int>(4);
        root->left->left = new TreeNode<int>(3);
        root->right->left = new TreeNode<int>(7);
        root->right->right = new TreeNode<int>(9);

        root->left->left->left = new TreeNode<int>(12);
        root->left->left->right = new TreeNode<int>(8);
        root->right->left->left = new TreeNode<int>(6);
        root->right->right->right = new TreeNode<int>(2);

        return root;
    }

    static TreeNode<int> *even_odd_tree2() {
        auto root = new TreeNode<int>(1);
        root->right = new TreeNode<int>(4);
        root->right->left = new TreeNode<int>(7);
        root->right->right = new TreeNode<int>(94819);
        root->right->left->left = new TreeNode<int>(4);

        return root;
    }

    template<typename T>
    static std::tuple<TreeNode<T> *, TreeNode<T> *, T, int> tree_and_inserted_row_tree() {
        constexpr int depth{2};
        constexpr T value{-1.f};
        auto root = new TreeNode<T>(1.f);
        root->right = new TreeNode<T>(4.f);
        root->left = new TreeNode<T>(4.f);
        root->right->left = new TreeNode<T>(7.f);
        root->right->right = new TreeNode<T>(94819.f);
        root->right->left->left = new TreeNode<T>(4.f);

        auto root2 = new TreeNode<T>(1.f);
        root2->right = new TreeNode<T>(-1.f);
        root2->left = new TreeNode<T>(-1.f);
        root2->right->right = new TreeNode<T>(4.f);
        root2->left->left = new TreeNode<T>(4.f);
        root2->right->right->left = new TreeNode<T>(7.f);
        root2->right->right->right = new TreeNode<T>(94819.f);
        root2->right->right->left->left = new TreeNode<T>(4.f);


        return std::make_tuple(root, root2, value, depth);

    }

};

#endif //SETUP_BINARY_TREE_H


