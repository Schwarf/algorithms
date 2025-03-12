//
// Created by andreas on 12.03.25.
//

#ifndef HIRING_CANDIDATES_H
#define HIRING_CANDIDATES_H

// There are n candidates with the expense to hire them listed in an array.
// The expense to hire the i'th candidate is cost[i]. The budget for hiring a pair of new members into our
// team is between min_cost and max_cost, both inclusive.
// Given the array cost and two integers min_cost and max_cost,
// find the number of pairs of people whose total expense is between min_cost and max_cost, both inclusive.
#include <vector>
#include <algorithm>

int number_of_candidate_pairs(std::vector<int> & candidate_costs, int min_cost, int max_cost)
{
     std::sort(candidate_costs.begin(), candidate_costs.end());
     int count{};
     for(int i{}; i<candidate_costs.size()- 1; ++i)
     {
         auto lower = std::lower_bound(candidate_costs.begin() + i + 1, candidate_costs.end(), min_cost - candidate_costs[i]);
         auto upper = std::upper_bound(candidate_costs.begin() + i + 1, candidate_costs.end(), max_cost - candidate_costs[i]);
         count += std::distance(lower, upper); // Count valid pairs
     }
     return count;
}
#endif //HIRING_CANDIDATES_H
