//
// Created by andreas on 31.07.24.
//
#include "./../minimal_height_book_shelves.h"
#include "gtest/gtest.h"

TEST(MinimalHeightBookShelvesTopDownDP, simple1) {
    std::vector<std::vector<int>> books{{1, 1},
                                        {2, 3},
                                        {2, 3},
                                        {1, 1},
                                        {1, 1},
                                        {1, 1},
                                        {1, 2}};
    constexpr int shelf_width{4};
    constexpr int expected_result{6};
    EXPECT_EQ(minimal_height_shelves(books, shelf_width), expected_result);
}
