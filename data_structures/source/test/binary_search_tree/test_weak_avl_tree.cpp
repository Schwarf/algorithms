#include "binary_search_tree/weak_avl_tree.h"
#include "gtest/gtest.h"

#include <algorithm>
#include <limits>
#include <numeric>
#include <random>
#include <set>
#include <vector>

TEST(WeakAVL, EmptyTree)
{
    const weakAVL<int> tree;
    EXPECT_FALSE(tree.contains(0));
    EXPECT_TRUE(tree.validate_bst());
    EXPECT_TRUE(tree.validate_wavl());
}

TEST(WeakAVL, SingleKeyAndDuplicate)
{
    weakAVL<int> tree;
    EXPECT_TRUE(tree.insert(42));
    EXPECT_FALSE(tree.insert(42));
    const auto& view = tree;
    EXPECT_TRUE(view.contains(42));
    EXPECT_FALSE(view.contains(41));
    EXPECT_FALSE(view.contains(43));
    EXPECT_TRUE(view.validate_bst());
    EXPECT_TRUE(view.validate_wavl());
}

namespace
{
// Check only observable set behavior and BST validity: rotations and rank
// maintenance may change the shape without changing these expectations.
void expect_set_behavior(const std::vector<int>& keys)
{
    weakAVL<int> tree;
    std::set<int> expected;
    for (const int key : keys)
    {
        SCOPED_TRACE(key);
        EXPECT_EQ(tree.insert(key), expected.insert(key).second);
        ASSERT_TRUE(tree.validate_bst());
        for (const int probe : keys)
            EXPECT_EQ(tree.contains(probe), expected.count(probe) != 0);
    }
    for (const int key : expected)
    {
        EXPECT_FALSE(tree.insert(key));
        EXPECT_TRUE(tree.contains(key));
        EXPECT_TRUE(tree.validate_bst());
    }
    EXPECT_FALSE(tree.contains(10000));
    EXPECT_FALSE(tree.contains(-10000));
}
}

TEST(WeakAVL, AscendingInsertion)
{
    std::vector<int> keys(128);
    std::iota(keys.begin(), keys.end(), -64);
    expect_set_behavior(keys);
}

TEST(WeakAVL, DescendingInsertion)
{
    std::vector<int> keys(128);
    std::iota(keys.begin(), keys.end(), -64);
    std::reverse(keys.begin(), keys.end());
    expect_set_behavior(keys);
}

TEST(WeakAVL, MixedInsertionAndDuplicates)
{
    expect_set_behavior({30, 10, 20, 50, 40, 60, 5, 15, 25, 35, 45,
                         30, 5, 60, 20, 0, -1, -20});
}

TEST(WeakAVL, SeededInsertionMatchesSet)
{
    std::mt19937 engine(12345);
    std::vector<int> keys;
    for (int i = 0; i < 256; ++i)
        keys.push_back(static_cast<int>(engine() % 201) - 100);
    expect_set_behavior(keys);
}

TEST(WeakAVL, IntegerLimits)
{
    expect_set_behavior({0, std::numeric_limits<int>::min(),
                         std::numeric_limits<int>::max(), -1, 1,
                         std::numeric_limits<int>::min(),
                         std::numeric_limits<int>::max()});
}

namespace
{
// No default constructor or equality operator: equivalence comes from <.
struct OrderedKey
{
    int value;
    int payload;
    inline static int live_instances = 0;

    OrderedKey(int value, int payload) : value(value), payload(payload) { ++live_instances; }
    OrderedKey(const OrderedKey& other) : value(other.value), payload(other.payload) { ++live_instances; }
    ~OrderedKey() { --live_instances; }

    bool operator<(const OrderedKey& other) const { return value < other.value; }
};
}

TEST(WeakAVL, OrderingDefinesEquivalenceAndTreeOwnsItsKeys)
{
    ASSERT_EQ(OrderedKey::live_instances, 0);
    {
        weakAVL<OrderedKey> tree;
        {
            OrderedKey key(2, 10);
            EXPECT_TRUE(tree.insert(key));
            key.value = 99;
        }
        EXPECT_TRUE(tree.insert(OrderedKey(1, 20)));
        EXPECT_TRUE(tree.insert(OrderedKey(3, 30)));
        EXPECT_FALSE(tree.insert(OrderedKey(2, 999)));
        const auto& view = tree;
        EXPECT_TRUE(view.contains(OrderedKey(1, 0)));
        EXPECT_TRUE(view.contains(OrderedKey(2, 0)));
        EXPECT_TRUE(view.contains(OrderedKey(3, 0)));
        EXPECT_FALSE(view.contains(OrderedKey(99, 0)));
        EXPECT_TRUE(view.validate_bst());
    }
    EXPECT_EQ(OrderedKey::live_instances, 0);
}
