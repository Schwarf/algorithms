//
// Created by andreas on 22.05.23.
//
#include "gtest/gtest.h"
#include "heaps/kth_largest_element_in_stream.h"

TEST(KthLargestElementInAstream, constructor_3rd)
{
    std::vector<int> input{5, 1, 3, 4, 2};
    auto test_object = KthLargestElementInStream<int>(3, input);
    int expected_result{3};
    EXPECT_EQ(expected_result, test_object.add_and_return_kth_element(0));
}

TEST(KthLargestElementInAstream, constructor_empty_)
{
    std::vector<int> initial_input{};
    auto test_object = KthLargestElementInStream<int>(1, initial_input);

    std::vector<int> inputs{-3, -2, -4, 0, 4};
    std::vector<int> expected_results{-3, -2, -2, 0, 4};
    for (int i{}; i < inputs.size(); ++i)
    {
        EXPECT_EQ(expected_results[i], test_object.add_and_return_kth_element(inputs[i]));
    }
}
