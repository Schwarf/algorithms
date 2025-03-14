//
// Created by andreas on 14.03.25.
//
#include "./../priorities_after_execution.h"
#include "gtest/gtest.h"

TEST(TestPrioritiesAfterExecutionBruteForce, simple1)
{
    std::vector<int> process_priorities{6, 6, 6, 1, 2, 2};
    std::vector<int> expected_result{3, 6, 0};
    EXPECT_EQ(expected_result, priorities_after_execution_brute_force(process_priorities));
}

TEST(TestPrioritiesAfterExecutionBruteForce, simple2)
{
    std::vector<int> process_priorities{4, 4, 2, 1};
    std::vector<int> expected_result{0};
    EXPECT_EQ(expected_result, priorities_after_execution_brute_force(process_priorities));
}

TEST(TestPrioritiesAfterExecutionBruteForce, simple3)
{
    std::vector<int> process_priorities{2, 1, 5, 10, 10, 1};
    std::vector<int> expected_result{0, 1};
    EXPECT_EQ(expected_result, priorities_after_execution_brute_force(process_priorities));
}

TEST(TestPrioritiesAfterExecution, simple1)
{
    std::vector<int> process_priorities{6, 6, 6, 1, 2, 2};
    std::vector<int> expected_result{3, 6, 0};
    EXPECT_EQ(expected_result, priorities_after_execution(process_priorities));
}
TEST(TestPrioritiesAfterExecution, simple2)
{
    std::vector<int> process_priorities{4, 4, 2, 1};
    std::vector<int> expected_result{0};
    EXPECT_EQ(expected_result, priorities_after_execution(process_priorities));
}

TEST(TestPrioritiesAfterExecution, simple3)
{
    std::vector<int> process_priorities{2, 1, 5, 10, 10, 1};
    std::vector<int> expected_result{0, 1};
    EXPECT_EQ(expected_result, priorities_after_execution(process_priorities));
}
