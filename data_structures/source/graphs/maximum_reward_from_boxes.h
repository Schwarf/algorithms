//
// Created by andreas on 03.06.25.
//

#ifndef MAXIMUM_REWARD_FROM_BOXES_H
#define MAXIMUM_REWARD_FROM_BOXES_H
// You have n boxes labeled from 0 to n - 1. You are given four arrays: status, rewards, keys, and containedBoxes where:
//
//    status[i] is 1 if the ith box is open and 0 if the ith box is closed,
//    rewards[i] is the number of rewards in the ith box,
//    keys[i] is a list of the labels of the boxes you can open after opening the ith box.
//    containedBoxes[i] is a list of the boxes you found inside the ith box.
//
// You are given an integer array initialBoxes that contains the labels of the boxes you initially have. You can take all the rewards in any open box and you can use the keys in it to open new boxes and you also can use the boxes you find in it.
//
// Return the maximum number of rewards you can get following the rules above.
#include <vector>
#include <queue>

int max_rewards_from_boxes(std::vector<int>& status, std::vector<int>& rewards,
                           std::vector<std::vector<int>>& keys,
                           std::vector<std::vector<int>>& contained_boxes,
                           std::vector<int>& initial_boxes)
{
    int n = status.size();
    std::vector<bool> can_open(n);
    std::vector<bool> has_box(n);
    std::vector<bool> used(n);
    for (int i = 0; i < n; ++i)
    {
        can_open[i] = (status[i] == 1);
    }

    std::queue<int> queue;
    int result = 0;
    for (const auto box : initial_boxes)
    {
        has_box[box] = true;
        if (can_open[box])
        {
            queue.push(box);
            used[box] = true;
            result += rewards[box];
        }
    }

    while (!queue.empty())
    {
        const auto big_box = queue.front();
        queue.pop();
        for (const auto key : keys[big_box])
        {
            can_open[key] = true;
            if (!used[key] && has_box[key])
            {
                queue.push(key);
                used[key] = true;
                result += rewards[key];
            }
        }
        for (const auto box : contained_boxes[big_box])
        {
            has_box[box] = true;
            if (!used[box] && can_open[box])
            {
                queue.push(box);
                used[box] = true;
                result += rewards[box];
            }
        }
    }

    return result;
}
#endif //MAXIMUM_REWARD_FROM_BOXES_H
