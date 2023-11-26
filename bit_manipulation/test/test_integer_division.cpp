//
// Created by andreas on 26.11.23.
//

#include "gtest/gtest.h"
#include "integer_division.h"

TEST(IntegerDivision, simple1)
{
	constexpr int8_t dividend{121};
	constexpr int8_t divisor{10};
	EXPECT_EQ(integer_division(dividend, divisor), 12);
}

TEST(IntegerDivision, simple2)
{
	constexpr int8_t dividend{-128};
	constexpr int8_t divisor{-1};
	EXPECT_EQ(integer_division(dividend, divisor), std::numeric_limits<int8_t>::max());
}

TEST(IntegerDivision, simple3)
{
	constexpr int32_t dividend{0};
	constexpr int32_t divisor{0};
	EXPECT_THROW(integer_division(dividend, divisor), std::overflow_error);
}

TEST(IntegerDivision, simple4)
{
	constexpr int16_t dividend{0};
	constexpr int16_t divisor{12};
	EXPECT_EQ(integer_division(dividend, divisor), 0);
}

TEST(IntegerDivision, simple5)
{
	constexpr int64_t dividend{4821905920};
	constexpr int64_t divisor{1267};
	EXPECT_EQ(integer_division(dividend, divisor), 3805766);
}


TEST(IntegerDivision, simple6)
{
	constexpr int32_t dividend{-489};
	constexpr int32_t divisor{-120};
	EXPECT_EQ(integer_division(dividend, divisor), 4);
}

TEST(IntegerDivision, simple7)
{
	constexpr int32_t dividend{12489};
	constexpr int32_t divisor{-773};
	EXPECT_EQ(integer_division(dividend, divisor), -16);
}
