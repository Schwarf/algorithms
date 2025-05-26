//
// Created by andreas on 26.05.25.
//
#include "gtest/gtest.h"
#include "./../rotate_matrix.h"

using Matrix = std::vector<std::vector<int>>;

TEST(TestRotateMatrix90, simple1)
{
    Matrix matrix{{42}};
    Matrix expected_result{{42}};
    rotate_matrix_90(matrix);
    EXPECT_EQ(matrix, expected_result);
}

TEST(TestRotateMatrix90, simple2)
{
    Matrix matrix{
        {1, 2},
        {3, 4}
    };
    Matrix expected_result{
        {3, 1},
        {4, 2}
    };
    rotate_matrix_90(matrix);
    EXPECT_EQ(matrix, expected_result);
}

TEST(TestRotateMatrix90, simple3)
{
    Matrix matrix{
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    Matrix expected_result{
        {7, 4, 1},
        {8, 5, 2},
        {9, 6, 3}
    };
    rotate_matrix_90(matrix);
    EXPECT_EQ(matrix, expected_result);
}

TEST(TestRotateMatrix90, simple4)
{
    Matrix matrix{
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };
    Matrix expected_result{
        {13, 9, 5, 1},
        {14, 10, 6, 2},
        {15, 11, 7, 3},
        {16, 12, 8, 4}
    };
    rotate_matrix_90(matrix);
    EXPECT_EQ(matrix, expected_result);
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

TEST(TestRoTateMatrix180, simple1)
{
    Matrix matrix{{7}};
    Matrix expected_result{{7}};
    rotate_matrix_180(matrix);
    EXPECT_EQ(matrix, expected_result);
}

TEST(TestRoTateMatrix180, simple2)
{
    Matrix matrix{
        {1, 2},
        {3, 4}
    };
    Matrix expected_result{
        {4, 3},
        {2, 1}
    };
    rotate_matrix_180(matrix);
    EXPECT_EQ(matrix, expected_result);
}

TEST(TestRoTateMatrix180, simple3)
{
    Matrix matrix{
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    Matrix expected_result{
        {9, 8, 7},
        {6, 5, 4},
        {3, 2, 1}
    };
    rotate_matrix_180(matrix);
    EXPECT_EQ(matrix, expected_result);
}

TEST(TestRoTateMatrix180, simple4)
{
    Matrix matrix{
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };
    Matrix expected_result{
        {16, 15, 14, 13},
        {12, 11, 10, 9},
        {8, 7, 6, 5},
        {4, 3, 2, 1}
    };
    rotate_matrix_180(matrix);
    EXPECT_EQ(matrix, expected_result);
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

TEST(TestRotateMatrix270, simple1)
{
    Matrix matrix{{-1}};
    Matrix expected_result{{-1}};
    rotate_matrix_270(matrix);
    EXPECT_EQ(matrix, expected_result);
}

TEST(TestRotateMatrix270, simple2)
{
    Matrix matrix{
        {1, 2},
        {3, 4}
    };
    Matrix expected_result{
        {2, 4},
        {1, 3}
    };
    rotate_matrix_270(matrix);
    EXPECT_EQ(matrix, expected_result);
}

TEST(TestRotateMatrix270, simple3)
{
    Matrix matrix{
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    Matrix expected_result{
        {3, 6, 9},
        {2, 5, 8},
        {1, 4, 7}
    };
    rotate_matrix_270(matrix);
    EXPECT_EQ(matrix, expected_result);
}

TEST(TestRotateMatrix270, simple4)
{
    Matrix matrix{
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };
    Matrix expected_result{
        {4, 8, 12, 16},
        {3, 7, 11, 15},
        {2, 6, 10, 14},
        {1, 5, 9, 13}
    };
    rotate_matrix_270(matrix);
    EXPECT_EQ(matrix, expected_result);
}
