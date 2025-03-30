//
// Created by andreas on 30.05.24.
//

#ifndef DATA_STRUCTURES_FIND_MOST_BOOKED_ROOM_H
#define DATA_STRUCTURES_FIND_MOST_BOOKED_ROOM_H
// You are given an integer n. There are n rooms numbered from 0 to n - 1.
// You are given a 2D integer array meetings where meetings[i] = [start_i, end_i]
// means that a meeting will be held during the half-closed time interval [start_i, end_i).
// All the values of start_i are unique.
// Meetings are allocated to rooms in the following manner:
// Each meeting will take place in the unused room with the lowest number.
// If there are no available rooms, the meeting will be delayed until a room becomes free.
// The delayed meeting should have the same duration as the original meeting.
// When a room becomes unused, meetings that have an earlier original start time should be given the room.
// Return the number of the room that held the most meetings. If there are multiple rooms,
// return the room with the lowest number.
// A half-closed interval [a, b) is the interval between a and b including a and not including b.
#include <vector>
#include <algorithm>
#include <queue>

int most_booked_room(int n, std::vector<std::vector<int>>& meetings)
{
    std::vector<int> meeting_counts(n);
    using room_number = int;
    using availability_time = long long;
    std::priority_queue<std::pair<availability_time, room_number>, std::vector<std::pair<
                            availability_time, room_number>>, std::greater<std::pair<availability_time, room_number>>>
        used_rooms;
    std::priority_queue<room_number, std::vector<room_number>, std::greater<room_number>> unused_rooms;
    for (int i{}; i < n; ++i)
        unused_rooms.push(i);
    std::ranges::sort(meetings);

    for (const auto& meeting : meetings)
    {
        auto start = meeting.front();
        auto end = meeting.back();
        // Update used and unused rooms with current time, the start-time of the current room
        while (!used_rooms.empty() && used_rooms.top().first <= start)
        {
            int room_number = used_rooms.top().second;
            used_rooms.pop();
            unused_rooms.push(room_number);
        }
        if (!unused_rooms.empty())
        {
            int unused_room = unused_rooms.top();
            unused_rooms.pop();
            used_rooms.emplace(end, unused_room);
            meeting_counts[unused_room]++;
        }
        else
        {
            auto [room_availability_time, room_number] = used_rooms.top();
            used_rooms.pop();
            // Update the availability-time of the room_number
            used_rooms.emplace(room_availability_time + end - start, room_number);
            meeting_counts[room_number]++;
        }
    }
    int max_meeting_count{};
    int max_meeting_room_number{};
    for (int i{}; i < n; ++i)
    {
        if (meeting_counts[i] > max_meeting_count)
        {
            max_meeting_count = meeting_counts[i];
            max_meeting_room_number = i;
        }
    }
    return max_meeting_room_number;
}

#endif //DATA_STRUCTURES_FIND_MOST_BOOKED_ROOM_H
