//
// Created by andreas on 30.05.24.
//

#ifndef FUN_WITH_ALGOS_HOW_MANY_MEETING_ROOMS_REQUIRED_H
#define FUN_WITH_ALGOS_HOW_MANY_MEETING_ROOMS_REQUIRED_H
// Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei),
// find the minimum number of conference rooms required.
#include <vector>
#include <queue>

int how_many_meeting_rooms_required(std::vector<std::vector<int>> &meetings) {
    std::sort(meetings.begin(), meetings.end(),
              [](const std::vector<int> &a, const std::vector<int> &b) { return a[0] < b[0]; });
    // Here we store the meeting end times of each room.
    std::priority_queue<int, std::vector<int>, std::greater<>> end_times;
    for (const auto &meeting: meetings) {
        // if current start-time is larger than the end-time at top we can pop
        if (!end_times.empty() && meeting[0] >= end_times.top())
            end_times.pop();
        end_times.push(meeting[1]);
    }
    return static_cast<int>(end_times.size());
}

#endif //FUN_WITH_ALGOS_HOW_MANY_MEETING_ROOMS_REQUIRED_H
