//
// Created by andreas on 23.06.26.
//

#ifndef ALGORITHMS_TARGET_SUM_H
#define ALGORITHMS_TARGET_SUM_H
// Given an integer array nums and an integer target, assign either a + sign or a - sign to every value in nums.
// Evaluate the resulting signed expression and count how many different sign assignments produce exactly target.
// Each number must be used once, in its original order. Two expressions are different if at least one array element
// receives a different sign.

void backtrack(int index, int& count, int current, const std::vector<int>& input, int target)
{
    if (index == input.size())
    {
        if (current == target)
            count++;
        return;
    }

    int current1 = current + input[index];
    int current2 = current - input[index];
    backtrack(index + 1, count, current1, input, target);
    backtrack(index + 1, count, current2, input, target);
}

int target_sum_ways(std::vector<int>& nums, int target)
{
    int count = 0;
    backtrack(0, count, 0, nums, target);
    return count;
}
#endif // ALGORITHMS_TARGET_SUM_H
