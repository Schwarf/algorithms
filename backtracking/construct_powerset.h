//
// Created by andreas on 04.06.26.
//

#ifndef ALGORITHMS_CONSTRUCT_POWERSET_H
#define ALGORITHMS_CONSTRUCT_POWERSET_H
#include <vector>

#include "compute_all_permutations.h"

std::vector<std::vector<int>> powerset_no_backtrack(const std::vector<int>& elements)
{
    std::vector<std::vector<int>> powerset;
    powerset.push_back({});
    for (const auto& element : elements)
    {
        auto size = powerset.size();
        for (int i{}; i < size; ++i)
        {
            auto new_set = powerset[i];
            new_set.push_back(element);
            powerset.push_back(new_set);
        }
    }
    return powerset;
}

void backtrack(const std::vector<int>& elements, int index, std::vector<int>& current,
               std::vector<std::vector<int>>& powerset)
{
    if (index == elements.size())
    {
        powerset.push_back(current);
        return;
    }
    // Do not take elements[index]
    backtrack(elements, index + 1, current, powerset);

    // Take elements[index]
    current.push_back(elements[index]);
    backtrack(elements, index + 1, current, powerset);
    current.pop_back();
}


std::vector<std::vector<int>> powerset_backtrack(const std::vector<int>& elements)
{
    std::vector<std::vector<int>> powerset;
    std::vector<int> current;
    backtrack(elements, 0, current, powerset);
    return powerset;
}


#endif // ALGORITHMS_CONSTRUCT_POWERSET_H
