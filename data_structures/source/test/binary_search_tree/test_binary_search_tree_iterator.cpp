#include "../../binary_search_tree/binary_search_tree_iterator.h"

#include <initializer_list>
#include <limits>
#include <string>

#include "gtest/gtest.h"

namespace
{
template <typename T>
void expectTraversal(TreeNode<T>* root, std::initializer_list<T> expected)
{
    BinarySearchTreeIterator<T> iterator(root);
    for (const auto& value : expected)
    {
        ASSERT_TRUE(iterator.hasNext());
        // Checking availability must not advance the iterator.
        EXPECT_TRUE(iterator.hasNext());
        EXPECT_EQ(iterator.next(), value);
    }
    EXPECT_FALSE(iterator.hasNext());
    EXPECT_FALSE(iterator.hasNext());
}
}

TEST(BinarySearchTreeIterator, EmptyTree)
{
    expectTraversal<int>(nullptr, {});
}

TEST(BinarySearchTreeIterator, SingleNode)
{
    TreeNode<int> root(42);
    expectTraversal(&root, {42});
}

TEST(BinarySearchTreeIterator, BalancedTree)
{
    TreeNode<int> one(1), three(3), five(5), seven(7);
    TreeNode<int> two(2, &one, &three), six(6, &five, &seven);
    TreeNode<int> root(4, &two, &six);

    expectTraversal(&root, {1, 2, 3, 4, 5, 6, 7});
}

TEST(BinarySearchTreeIterator, LeftSkewedTree)
{
    TreeNode<int> one(1);
    TreeNode<int> two(2, &one, nullptr);
    TreeNode<int> root(3, &two, nullptr);

    expectTraversal(&root, {1, 2, 3});
}

TEST(BinarySearchTreeIterator, RightSkewedTree)
{
    TreeNode<int> three(3);
    TreeNode<int> two(2, nullptr, &three);
    TreeNode<int> root(1, nullptr, &two);

    expectTraversal(&root, {1, 2, 3});
}

TEST(BinarySearchTreeIterator, DescendsLeftWithinRightSubtree)
{
    TreeNode<int> nine(9);
    TreeNode<int> eight(8, nullptr, &nine);
    TreeNode<int> twelve(12, &eight, nullptr);
    TreeNode<int> fifteen(15, &twelve, nullptr);
    TreeNode<int> three(3);
    TreeNode<int> root(7, &three, &fifteen);

    expectTraversal(&root, {3, 7, 8, 9, 12, 15});
}

TEST(BinarySearchTreeIterator, IntegerLimitsAndNegativeValues)
{
    const int minimum = std::numeric_limits<int>::min();
    const int maximum = std::numeric_limits<int>::max();
    TreeNode<int> lowest(minimum), highest(maximum);
    TreeNode<int> negative(-1, &lowest, nullptr);
    TreeNode<int> root(0, &negative, &highest);

    expectTraversal(&root, {minimum, -1, 0, maximum});
}

TEST(BinarySearchTreeIterator, SupportsNonIntegerValues)
{
    TreeNode<std::string> left("apple"), right("pear");
    TreeNode<std::string> root("banana", &left, &right);

    expectTraversal<std::string>(&root, {"apple", "banana", "pear"});
}

TEST(BinarySearchTreeIterator, IteratorsAdvanceIndependently)
{
    TreeNode<int> left(1), right(3);
    TreeNode<int> root(2, &left, &right);
    BinarySearchTreeIterator<int> first(&root), second(&root);

    ASSERT_TRUE(first.hasNext());
    EXPECT_EQ(first.next(), 1);
    ASSERT_TRUE(first.hasNext());
    EXPECT_EQ(first.next(), 2);

    ASSERT_TRUE(second.hasNext());
    EXPECT_EQ(second.next(), 1);
    ASSERT_TRUE(first.hasNext());
    EXPECT_EQ(first.next(), 3);
    EXPECT_FALSE(first.hasNext());

    ASSERT_TRUE(second.hasNext());
    EXPECT_EQ(second.next(), 2);
    ASSERT_TRUE(second.hasNext());
    EXPECT_EQ(second.next(), 3);
    EXPECT_FALSE(second.hasNext());

    EXPECT_EQ(root.left, &left);
    EXPECT_EQ(root.right, &right);
    expectTraversal(&root, {1, 2, 3});
}
