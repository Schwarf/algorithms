//
// Created by andreas on 27.12.23.
//

#include "gtest/gtest.h"
#include "number_of_dice_rolls_for_target.h"

TEST(TestNumberOfDiceRollsForTarget, simple1_bottom_up) {
    constexpr int max_number_of_dice{1};
    constexpr int max_dice_value{6};
    constexpr int target{3};
    constexpr int expected_result{1};
    EXPECT_EQ(expected_result, number_of_dice_rolls_bottom_up(max_number_of_dice, max_dice_value, target));
}

TEST(TestNumberOfDiceRollsForTarget, simple2_bottom_up) {
    constexpr int max_number_of_dice{2};
    constexpr int max_dice_value{6};
    constexpr int target{7};
    constexpr int expected_result{6};
    EXPECT_EQ(expected_result, number_of_dice_rolls_bottom_up(max_number_of_dice, max_dice_value, target));
}

TEST(TestNumberOfDiceRollsForTarget, simple3_bottom_up) {
    constexpr int max_number_of_dice{7};
    constexpr int max_dice_value{10};
    constexpr int target{16};
    constexpr int expected_result{5005};
    EXPECT_EQ(expected_result, number_of_dice_rolls_bottom_up(max_number_of_dice, max_dice_value, target));
}


TEST(TestNumberOfDiceRollsForTarget, complex_bottom_up) {
    constexpr int max_number_of_dice{30};
    constexpr int max_dice_value{30};
    constexpr int target{500};
    constexpr int expected_result{222616187};
    EXPECT_EQ(expected_result, number_of_dice_rolls_bottom_up(max_number_of_dice, max_dice_value, target));
}


TEST(TestNumberOfDiceRollsForTarget, simple1_recursive) {
    constexpr int max_number_of_dice{1};
    constexpr int max_dice_value{6};
    constexpr int target{3};
    constexpr int expected_result{1};
    EXPECT_EQ(expected_result, number_of_dice_rolls_recursive(max_number_of_dice, max_dice_value, target));
}

TEST(TestNumberOfDiceRollsForTarget, simple2_recursive) {
    constexpr int max_number_of_dice{2};
    constexpr int max_dice_value{6};
    constexpr int target{7};
    constexpr int expected_result{6};
    EXPECT_EQ(expected_result, number_of_dice_rolls_recursive(max_number_of_dice, max_dice_value, target));
}

TEST(TestNumberOfDiceRollsForTarget, simple3_recursive) {
    constexpr int max_number_of_dice{7};
    constexpr int max_dice_value{10};
    constexpr int target{16};
    constexpr int expected_result{5005};
    EXPECT_EQ(expected_result, number_of_dice_rolls_recursive(max_number_of_dice, max_dice_value, target));
}


TEST(TestNumberOfDiceRollsForTarget, complex_top_down) {
    constexpr int max_number_of_dice{30};
    constexpr int max_dice_value{30};
    constexpr int target{500};
    constexpr int expected_result{222616187};
    EXPECT_EQ(expected_result, number_of_dice_rolls_top_down(max_number_of_dice, max_dice_value, target));
}

TEST(TestNumberOfDiceRollsForTarget, simple1_top_down) {
    constexpr int max_number_of_dice{1};
    constexpr int max_dice_value{6};
    constexpr int target{3};
    constexpr int expected_result{1};
    EXPECT_EQ(expected_result, number_of_dice_rolls_top_down(max_number_of_dice, max_dice_value, target));
}

TEST(TestNumberOfDiceRollsForTarget, simple2_top_down) {
    constexpr int max_number_of_dice{2};
    constexpr int max_dice_value{6};
    constexpr int target{7};
    constexpr int expected_result{6};
    EXPECT_EQ(expected_result, number_of_dice_rolls_top_down(max_number_of_dice, max_dice_value, target));
}

TEST(TestNumberOfDiceRollsForTarget, simple3_top_down) {
    constexpr int max_number_of_dice{7};
    constexpr int max_dice_value{10};
    constexpr int target{16};
    constexpr int expected_result{5005};
    EXPECT_EQ(expected_result, number_of_dice_rolls_top_down(max_number_of_dice, max_dice_value, target));
}
