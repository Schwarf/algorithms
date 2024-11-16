//
// Created by andreas on 16.11.24.
//
#include "can_array_be_sorted.h"
#include "gtest/gtest.h"


TEST(TestCanArrayBeSortedBubbleSort, simple1)
{
    std::vector<int> input{8, 4, 2, 30, 15};
    EXPECT_TRUE(can_array_be_sorted_bubble_sort(input));
}


TEST(TestCanArrayBeSortedBubbleSort, simple2)
{
    std::vector<int> input{1, 2, 3, 4, 5};
    EXPECT_TRUE(can_array_be_sorted_bubble_sort(input));
}


TEST(TestCanArrayBeSortedBubbleSort, simple3)
{
    std::vector<int> input{3, 16, 8, 4, 2};
    EXPECT_FALSE(can_array_be_sorted_bubble_sort(input));
}

TEST(TestCanArrayBeSortedBubbleSort, simple4)
{
    std::vector<int> input{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    EXPECT_TRUE(can_array_be_sorted_bubble_sort(input));
}

TEST(TestCanArrayBeSortedBubbleSort, simple5)
{
    std::vector<int> input{220,200,198,196,189,186,177,157,152,118,112,108,65,27,11};
    EXPECT_FALSE(can_array_be_sorted_bubble_sort(input));
}

////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////

TEST(TestCanArrayBeSorted, simple1)
{
    std::vector<int> input{8, 4, 2, 30, 15};
    EXPECT_TRUE(can_array_be_sorted(input));
}


TEST(TestCanArrayBeSorted, simple2)
{
    std::vector<int> input{1, 2, 3, 4, 5};
    EXPECT_TRUE(can_array_be_sorted(input));
}


TEST(TestCanArrayBeSorted, simple3)
{
    std::vector<int> input{3, 16, 8, 4, 2};
    EXPECT_FALSE(can_array_be_sorted(input));
}

TEST(TestCanArrayBeSorted, simple4)
{
    std::vector<int> input{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    EXPECT_TRUE(can_array_be_sorted(input));
}

TEST(TestCanArrayBeSorted, simple5)
{
    std::vector<int> input{220,200,198,196,189,186,177,157,152,118,112,108,65,27,11};
    EXPECT_FALSE(can_array_be_sorted(input));
}
