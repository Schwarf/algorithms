//
// Created by andreas on 14.04.25.
//

#ifndef NUMBER_OF_VALID_TRIPLETS_H
#define NUMBER_OF_VALID_TRIPLETS_H
// LC 2222
// You are given a 0-indexed binary string s which represents the types of buildings along a street where:
//    s[i] = '0' denotes that the ith building is an office and
//    s[i] = '1' denotes that the ith building is a restaurant.
// As a city official, you would like to select 3 buildings for random inspection. However, to ensure variety, no two consecutive buildings out of the selected buildings can be of the same type.
// For example, given s = "001101", we cannot select the 1st, 3rd, and 5th buildings as that would form "011" which is not allowed due to having two consecutive buildings of the same type.
// Return the number of valid ways to select 3 buildings.
#include <vector>
#include <string>

long long number_of_valid_triplets(const std::string& input)
{
    int n = input.size();
    std::vector<int> zero_prefix(n);
    std::vector<int> one_prefix(n);

    zero_prefix[0] = (input[0] == '0');
    one_prefix[0] = (input[0] == '1');
    for (int i{1}; i < n; ++i)
    {
        zero_prefix[i] = zero_prefix[i - 1] + (input[i] == '0');
        one_prefix[i] = one_prefix[i - 1] + (input[i] == '1');
    }
    long long result{};
    for (int i{1}; i < n - 1; ++i)
    {
        if (input[i] == '0')
        {
            int left_ones = one_prefix[i - 1];
            int right_ones = one_prefix[n - 1] - one_prefix[i];
            result += static_cast<long long>(left_ones) * right_ones;
        }
        else
        {
            int left_zeros = zero_prefix[i - 1];
            int right_zeros = zero_prefix[n - 1] - zero_prefix[i];
            result += static_cast<long long>(left_zeros) * right_zeros;
        }
    }
    return result;
}

long long number_of_valid_triplets_optimal(const std::string& s)
{
    long long ones{};
    long long zeros{};
    long long result{};
    for (const auto& c : s)
    {
        if (c == '1')
            ones++;
        else
            zeros++;
    }
    long long occurences_one{};
    long long occurences_zero{};
    for (const auto& c : s)
    {
        if (c == '1')
        {
            result += occurences_zero * zeros;
            ones--;
            occurences_one++;
        }
        else
        {
            result += occurences_one * ones;
            zeros--;
            occurences_zero++;
        }
    }
    return result;
}

};

#endif //NUMBER_OF_VALID_TRIPLETS_H
