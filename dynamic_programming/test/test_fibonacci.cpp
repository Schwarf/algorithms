//
// Created by andreas on 08.07.23.
//

#include "gtest/gtest.h"
#include "./../fibonacci_numbers.h"
#include <vector>


class SetupFibonacciTest : public testing::Test
{
protected:
    static constexpr int max{51};
    static constexpr unsigned long long
    fibonacci_numbers[max]{
        0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597,
        2584, 4181, 6765, 10946, 17711, 28657, 46368, 75025, 121393, 196418,
        317811, 514229, 832040, 1346269, 2178309, 3524578, 5702887, 9227465,
        14930352, 24157817, 39088169, 63245986, 102334155, 165580141,
        267914296, 433494437, 701408733, 1134903170, 1836311903, 2971215073,
        4807526976, 7778742049, 12586269025
    };
};

TEST_F(SetupFibonacciTest, nth_fibonacci_number_atRuntime)
{
    for (int i{}; i < SetupFibonacciTest::max; ++i)
        EXPECT_EQ(fibonacci_numbers[i], n_th_fibonacci_number(i));
}

TEST_F(SetupFibonacciTest, nth_fibonacci_number_atRuntimeThrowsForValueOver50)
{
    const std::string message{"We only compute fibonacci numbers up to 50"};
    try
    {
        n_th_fibonacci_number(51);
        FAIL() << "Expected std::out_of_range";
    }
    catch (std::out_of_range const& err)
    {
        EXPECT_TRUE(err.what() == message);
    }
}


TEST_F(SetupFibonacciTest, nth_fibonacci_number_atCompileTime)
{
    for (int i{}; i < SetupFibonacciTest::max; ++i)
        EXPECT_EQ(fibonacci_numbers[i], first_50_fibonacci_numbers()[i]);
}
