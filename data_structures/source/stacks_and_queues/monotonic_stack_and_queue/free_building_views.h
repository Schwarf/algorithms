//
// Created by andreas on 24.08.26.
//

#ifndef ALGORITHMS_FREE_BUILDING_VIEWS_H
#define ALGORITHMS_FREE_BUILDING_VIEWS_H
// You are given an array of positive integers buildings, where each value represents the height of a building. The
// buildings are arranged from west to east. You are also given a string direction, which is either "EAST" or "WEST" and
// specifies the direction in which we view. A building has a free view if every building between it and the horizon is
// strictly shorter. Return the indices of all buildings that have a free view, sorted in increasing order.

#include <algorithm>
#include <string>
#include <vector>

std::vector<int> free_views(const std::vector<int>& buildings, const std::string& direction)
{
    std::vector<int> result;
    int n = buildings.size();
    if (direction == "EAST")
    {
        int max_height = -1;
        for (int i = n - 1; i > -1; --i)
        {
            if (buildings[i] > max_height)
            {
                max_height = buildings[i];
                result.push_back(i);
            }
        }
        std::reverse(result.begin(), result.end());
    }
    else
    {
        int max_height = -1;
        for (int i = 0; i < buildings.size(); ++i)
        {
            if (buildings[i] > max_height)
            {
                max_height = buildings[i];
                result.push_back(i);
            }
        }
    }
    return result;
}

std::vector<int> free_views_monotonic_stack(const std::vector<int>& buildings, const std::string& direction)
{
    std::vector<int> result;
    const int n = static_cast<int>(buildings.size());

    if (direction == "EAST")
    {
        for (int i = 0; i < n; ++i)
        {
            while (!result.empty() && buildings[result.back()] <= buildings[i])
                result.pop_back();
            result.push_back(i);
        }
        return result;
    }

    for (int i = n - 1; i >= 0; --i)
    {
        while (!result.empty() && buildings[result.back()] <= buildings[i])
            result.pop_back();
        result.push_back(i);
    }

    std::reverse(result.begin(), result.end());
    return result;
}


#endif // ALGORITHMS_FREE_BUILDING_VIEWS_H
