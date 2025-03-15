//
// Created by andreas on 14.03.25.
//

#ifndef DROPPED_REQUESTS_H
#define DROPPED_REQUESTS_H


// On Black Sale Day, non-critical requests for a transaction system are routed through a throttling gateway to ensure that the network is not choked by non-essential requests. The gateway has the following limits:
// The number of transactions in any given second cannot exceed 3.
// The number of transactions in any given 10 second period cannot exceed 20. A ten-second period includes all requests arriving from time T to T-9 (inclusive of both) for any valid time T.
// The number of transactions in any given minute cannot exceed 60. Similar to above, 1 minute is from max(T, T-59) to T.
// Any request that exceeds any of the above limits will be dropped by the gateway. Given the times at which different requests arrive sorted ascending, find how many requests will be dropped.
// Note : Even if a request is dropped it is still considered for future calculations. Although, if a request is to be dropped due to multiple violations, it is still counted only once.
// Function Description
// Complete the function droppedRequests in the editor.
// droppedRequests has the following parameter(s):
//    List requestTime : an ordered list of integers that represent the times of various requests
// Returns
// int : the total number of dropped requests
#include <deque>
#include <vector>

int dropped_requests(std::vector<int>& requests) {
    int dropped{};

    std::deque<int> last10s, last60s;
    std::vector<int> perSecond(100001, 0);  // Max time limit (1-based index)

    for (int t : requests) {
        // Maintain per-second counter
        perSecond[t]++;

        // Remove expired timestamps from the 10s and 60s window
        while (!last10s.empty() && last10s.front() < t - 9) {
            last10s.pop_front();
        }
        while (!last60s.empty() && last60s.front() < t - 59) {
            last60s.pop_front();
        }

        // Check per-second limit (no more than 3 per second)
        if (perSecond[t] > 3) {
            dropped++;
        }

        // Check 10-second limit (no more than 20 requests in last 10s)
        last10s.push_back(t);
        if (last10s.size() > 20) {
            dropped++;
            last10s.pop_back();  // Remove the extra request
        }

        // Check 60-second limit (no more than 60 requests in last 60s)
        last60s.push_back(t);
        if (last60s.size() > 60) {
            dropped++;
        }
    }

    return dropped;
}
#endif //DROPPED_REQUESTS_H
