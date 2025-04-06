//
// Created by andreas on 06.04.25.
//
#include "heaps/find_median_of_data_stream.h"
#include "gtest/gtest.h"

TEST(TestFindMediaOfDataStream, simple1)
{
    std::vector<int> stream{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::vector<double> expected_results{1.0, 1.5, 2.0, 2.5, 3.0, 3.5, 4.0, 4.5, 5.0, 5.5};
    auto median_finder = MedianOfDataStream<int>();
    for (int i{}; i < stream.size(); ++i)
    {
        median_finder.add_element(stream[i]);
        EXPECT_EQ(median_finder.find_median(), expected_results[i]);
    }
}


