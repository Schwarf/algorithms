//
// Created by andreas on 15.04.25.
//

// You and a gang of thieves are planning on robbing a bank. You are given a 0-indexed integer array security,
// where security[i] is the number of guards on duty on the ith day. The days are numbered starting from 0. You are also given an integer time.
// The ith day is a good day to rob the bank if:
//    There are at least time days before and after the ith day,
//    The number of guards at the bank for the time days before i are non-increasing, and
//    The number of guards at the bank for the time days after i are non-decreasing.
// More formally, this means day i is a good day to rob the bank if and only if
// security[i - time] >= security[i - time + 1] >= ... >= security[i] <= ... <= security[i + time - 1] <= security[i + time].
// Return a list of all days (0-indexed) that are good days to rob the bank. The order that the days are returned in does not matter.
// LC 2100
#include <vector>
std::vector<int> rob_banks(std::vector<int>& security, int time) {
    int n = security.size();
    std::vector<int> prefix(n ,0);
    std::vector<int> suffix(n ,0);
    int count{};
    for(int i=1; i<n; ++i)
    {
        if(security[i] <= security[i-1])
        {
            count++;
        }
        else
        {
            count = 0;
        }
        prefix[i] = count;
    }
    count = 0;
    for(int i=n-2; i>-1; --i)
    {
        if(security[i] <= security[i+1])
        {
            count++;
        }
        else
        {
            count = 0;
        }
        suffix[i] = count;
    }
    std::vector<int> result;
    for(int i{}; i < n; ++i)
    {
        // We check both sides
        if(prefix[i] >= time && suffix[i] >= time)
            result.push_back(i);
    }
    return result;
}