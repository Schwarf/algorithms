//
// Created by andreas on 14.11.25.
//

// add_queries_test.cpp
#include <gtest/gtest.h>
#include <vector>

#include "../increment_sub_matrices.h"



TEST(AddQueriesTest, NoQueriesReturnsZeroMatrix) {
    int n = 3;
    std::vector<std::vector<int>> queries; // empty

    auto result = add_queries<int>(n, queries);

    std::vector<std::vector<int>> expected(n, std::vector<int>(n, 0));
    EXPECT_EQ(result, expected);
}

TEST(AddQueriesTest, SingleFullMatrixQuery) {
    int n = 3;
    std::vector<std::vector<int>> queries = {
        {0, 0, 2, 2}  // whole 3x3 matrix
    };

    auto result = add_queries<int>(n, queries);

    std::vector<std::vector<int>> expected = {
        {1, 1, 1},
        {1, 1, 1},
        {1, 1, 1}
    };

    EXPECT_EQ(result, expected);
}

TEST(AddQueriesTest, SingleCellQuery) {
    int n = 3;
    std::vector<std::vector<int>> queries = {
        {1, 1, 1, 1}  // only cell (1,1)
    };

    auto result = add_queries<int>(n, queries);

    std::vector<std::vector<int>> expected = {
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0}
    };

    EXPECT_EQ(result, expected);
}

TEST(AddQueriesTest, RowRangeQuery) {
    int n = 3;
    std::vector<std::vector<int>> queries = {
        {1, 0, 1, 2}  // entire row 1
    };

    auto result = add_queries<int>(n, queries);

    std::vector<std::vector<int>> expected = {
        {0, 0, 0},
        {1, 1, 1},
        {0, 0, 0}
    };

    EXPECT_EQ(result, expected);
}

TEST(AddQueriesTest, OverlappingQueries) {
    int n = 3;
    std::vector<std::vector<int>> queries = {
        {0, 0, 1, 1}, // top-left 2x2
        {1, 1, 2, 2}  // bottom-right 2x2
    };

    auto result = add_queries<int>(n, queries);

    // cell (1,1) is covered by both rectangles -> value 2
    std::vector<std::vector<int>> expected = {
        {1, 1, 0},
        {1, 2, 1},
        {0, 1, 1}
    };

    EXPECT_EQ(result, expected);
}

TEST(AddQueriesTest, MultipleDisjointQueries) {
    int n = 4;
    std::vector<std::vector<int>> queries = {
        {0, 0, 0, 0}, // (0,0)
        {3, 3, 3, 3}, // (3,3)
        {1, 1, 2, 2}  // center 2x2
    };

    auto result = add_queries<int>(n, queries);

    std::vector<std::vector<int>> expected = {
        {1, 0, 0, 0},
        {0, 1, 1, 0},
        {0, 1, 1, 0},
        {0, 0, 0, 1}
    };

    EXPECT_EQ(result, expected);
}
