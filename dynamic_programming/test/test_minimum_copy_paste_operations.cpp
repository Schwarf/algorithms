//
// Created by andreas on 19.08.24.
//
#include "gtest/gtest.h"
#include "./../minimum_copy_paste_operations.h"

TEST(TestMinimumCopyPasteOperationsRecursive, simple1) {
    constexpr int input{3};
    constexpr int expected_result{3};
    EXPECT_EQ(expected_result, minimum_copy_paste_operations_recursive(input));
}

TEST(TestMinimumCopyPasteOperationsRecursive, simple2) {
    constexpr int input{1};
    constexpr int expected_result{0};
    EXPECT_EQ(expected_result, minimum_copy_paste_operations_recursive(input));
}

TEST(TestMinimumCopyPasteOperationsRecursive, simple3) {
    constexpr int input{10};
    constexpr int expected_result{7};
    EXPECT_EQ(expected_result, minimum_copy_paste_operations_recursive(input));
}

TEST(TestMinimumCopyPasteOperationsRecursive, simple4) {
    constexpr int input{21};
    constexpr int expected_result{10};
    EXPECT_EQ(expected_result, minimum_copy_paste_operations_recursive(input));
}


TEST(TestMinimumCopyPasteOperationsRecursive, simple5) {
    // prime number inputs should return themselves
    constexpr int input{47};
    constexpr int expected_result{47};
    EXPECT_EQ(expected_result, minimum_copy_paste_operations_recursive(input));
}

TEST(TestMinimumCopyPasteOperationsRecursive, simple6) {
    // prime number inputs should return themselves
    constexpr int input{761};
    constexpr int expected_result{761};
    EXPECT_EQ(expected_result, minimum_copy_paste_operations_recursive(input));
}

TEST(TestMinimumCopyPasteOperationsRecursive, simple7) {
    // prime number inputs should return themselves
    constexpr int input{863};
    constexpr int expected_result{863};
    EXPECT_EQ(expected_result, minimum_copy_paste_operations_recursive(input));
}