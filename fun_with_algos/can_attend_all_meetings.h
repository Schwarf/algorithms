//
// Created by andreas on 30.05.24.
//

#ifndef DATA_STRUCTURES_CAN_ATTEND_ALL_MEETINGS_H
#define DATA_STRUCTURES_CAN_ATTEND_ALL_MEETINGS_H
// Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei),
// determine if a person could attend all meetings.
#include <vector>
#include <algorithm>

bool can_attend_all_meetings(std::vector<std::vector<int>> &meetings) {
    std::sort(meetings.begin(), meetings.end(),
              [](const std::vector<int> &a, const std::vector<int> &b) { return a[0] < b[0]; });
    for (int i{1}; i < meetings.size(); ++i) {
        if (meetings[i][0] < meetings[i - 1][i])
            return false;
    }
    return true;
}

#endif //DATA_STRUCTURES_CAN_ATTEND_ALL_MEETINGS_H
