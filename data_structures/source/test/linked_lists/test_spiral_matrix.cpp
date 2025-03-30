//
// Created by andreas on 09.09.24.
//

#ifndef DATA_STRUCTURES_TEST_SPIRAL_MATRIX_H
#define DATA_STRUCTURES_TEST_SPIRAL_MATRIX_H

#include "setup_singly_linked_lists.h"
#include "linked_lists/spiral_matrix.h"

TEST_F(SetupSinglyLinkedLists, TestSpiralMatrxSimple1)
{
    auto head = get_single_list_from_vector(std::vector<int>{3, 0, 2, 6, 8, 1, 7, 9, 4, 2, 5, 5, 0});
    constexpr int rows{3};
    constexpr int columns{5};
    std::vector<std::vector<int>> expected_result{
        {3, 0, 2, 6, 8},
        {5, 0, -1, -1, 1},
        {5, 2, 4, 9, 7}
    };
    auto result = spiral_matrix(rows, columns, head);
    EXPECT_EQ(expected_result, result);
}

TEST_F(SetupSinglyLinkedLists, TestSpiralMatrxSimple2)
{
    auto head = get_single_list_from_vector(std::vector<int>{0, 1, 2});
    constexpr int rows{1};
    constexpr int columns{4};
    std::vector<std::vector<int>> expected_result{{0, 1, 2, -1}};
    auto result = spiral_matrix(rows, columns, head);
    EXPECT_EQ(expected_result, result);
}

TEST_F(SetupSinglyLinkedLists, TestSpiralMatrxSimple3)
{
    auto head = get_single_list_from_vector(std::vector<int>{});
    constexpr int rows{4};
    constexpr int columns{4};
    std::vector<std::vector<int>> expected_result{
        {-1, -1, -1, -1},
        {-1, -1, -1, -1},
        {-1, -1, -1, -1},
        {-1, -1, -1, -1}
    };
    auto result = spiral_matrix(rows, columns, head);
    EXPECT_EQ(expected_result, result);
}


TEST_F(SetupSinglyLinkedLists, TestSpiralMatrxSimple4)
{
    auto head = get_single_list_from_vector(
        std::vector<int>{
            995, 348, 36, 516, 333, 627, 248, 422, 13, 225, 764, 311, 405, 695, 698, 83, 145, 783,
            478
        });
    constexpr int rows{9};
    constexpr int columns{6};
    std::vector<std::vector<int>> expected_result{
        {995, 348, 36, 516, 333, 627},
        {-1, -1, -1, -1, -1, 248},
        {-1, -1, -1, -1, -1, 422},
        {-1, -1, -1, -1, -1, 13},
        {-1, -1, -1, -1, -1, 225},
        {-1, -1, -1, -1, -1, 764},
        {-1, -1, -1, -1, -1, 311},
        {-1, -1, -1, -1, -1, 405},
        {478, 783, 145, 83, 698, 695}
    };
    auto result = spiral_matrix(rows, columns, head);
    EXPECT_EQ(expected_result, result);
}

#endif //DATA_STRUCTURES_TEST_SPIRAL_MATRIX_H
