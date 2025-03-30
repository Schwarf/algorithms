//
// Created by andreas on 19.02.24.
//

#ifndef FURTHEST_BUILDING_TO_REACH_H
#define FURTHEST_BUILDING_TO_REACH_H

// You are given an integer array heights representing the heights of buildings, some bricks, and some ladders.
//
// You start your journey from building 0 and move to the next building by possibly using bricks or ladders.
//
// While moving from building i to building i+1 (0-indexed),
//
// If the current building's height is greater than or equal to the next building's height, you do not need a ladder or bricks.
// If the current building's height is less than the next building's height, you can either use one ladder or (h[i+1] - h[i]) bricks.
//
// Return the furthest building index (0-indexed) you can reach if you use the given ladders and bricks optimally.

#include <vector>
#include <queue>

int furthest_building_to_reach(const std::vector<int>& heights, int bricks, int ladders)
{
    int n = heights.size();
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
    for (int i = 0; i < n - 1; ++i)
    {
        int diff = heights[i + 1] - heights[i];
        if (diff > 0)
        {
            // By default, we use ladders as long as we have some
            if (pq.size() < ladders)
            {
                pq.push(diff);
            }
            else
            {
                // Check if we are out of ladders, then use bricks or when the difference is smaller than the one on top
                if (pq.empty() || pq.top() >= diff)
                {
                    bricks -= diff;
                }
                // Get the smallest gap (covered) by a ladder and use bricks instead and put the current gap into the queue.
                else
                {
                    int poll = pq.top();
                    pq.pop();
                    pq.push(diff);
                    bricks -= poll;
                }
                // if we are out of bricks return i
                if (bricks < 0) return i;
            }
        }
    }
    return n - 1;
}

#endif //FURTHEST_BUILDING_TO_REACH_H
