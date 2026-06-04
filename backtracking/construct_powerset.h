//
// Created by andreas on 04.06.26.
//

#ifndef ALGORITHMS_CONSTRUCT_POWERSET_H
#define ALGORITHMS_CONSTRUCT_POWERSET_H
#include <vector>

std::vector<std::vector<int>> powerset_no_backtrack(const std::vector<int> & elements)
{
    std::vector<std::vector<int>> powerset;
    powerset.push_back({});
    for (const auto & element : elements)
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


#endif //ALGORITHMS_CONSTRUCT_POWERSET_H