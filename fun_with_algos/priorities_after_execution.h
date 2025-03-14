//
// Created by andreas on 14.03.25.
//

#ifndef PRIORITIES_AFTER_EXECUTION_H
#define PRIORITIES_AFTER_EXECUTION_H

// Priorities after Execution
// Several processes are scheduled for execution on the servers.
// On one server, n processes are schedule where the ith process is assigned a priority of priority[i].
// The processes are placed sequentially in a queue and are numbered 1, 2,..,n.
// The server schedules the processes per the following algorithm:
// It finds the maximum priority shared by at least 2 processes. Let that be denoted by p .
// (if there is no such priority or p = 0 , the algorithm is terminated)
// Otherwise, select the two of the processes with the lowest indexes and priority p , call them process1 and process2 .
// The server executes process1 and removes it from the queue.
// To avoid starvation, it reduces the priority of process2 to floor(p/2) .
// Start again from step 1.
// Given the initial priority of the processes, find the final priority of the processes which remain after the algorithm terminates.
// Note that relative the arrangement of remaining processes in the queue remains the same,only their priorities change.
// Function Description
// Complete the function getPrioritiesAfterExecution in the editor.
//getPrioritiesAfterExecution has the following parameter:
//    int priority[n]: the initial prorities of processes
//Returns
//    int[]: the final priorities of the remaining processes
#include <algorithm>
#include <map>
#include <vector>
#include <cmath>
#include <iostream>
#include <ostream>
#include <set>

std::vector<int> priorities_after_execution(std::vector<int> & process_priorities)
{
    std::multimap<int, int, std::greater<int>> priorities;
    std::map<int, int> index_value;
    for (int i = 0; i < process_priorities.size(); ++i) {
        priorities.emplace(process_priorities[i], i); // (priority, index)
        index_value[i] = process_priorities[i];
    }

    // Print to verify correct order
    for (auto it = priorities.begin(); it != priorities.end(); it = priorities.upper_bound(it->first)) {
        int priority = it->first;
        auto range = priorities.equal_range(priority);
        auto first_it = range.first;
        auto second_it = std::next(first_it); // Seco

        if (second_it == priorities.end()) {
            ++it; // Move to the next key
            continue;
        }

        // Erase the first occurrence
        priorities.erase(first_it);

        // Extract, modify, and reinsert the second occurrence
        int new_value = std::floor(second_it->second / 2.0);

        priorities.erase(second_it); // Remove second occurrence
        priorities.emplace(priority, new_value); // Reinsert modified value
        // Move to the next key safely
        it = priorities.upper_bound(priority);
    }
    std::vector<int> result;
    for (const auto & [index, value] : index_value) {
        result.push_back(value);
    }
    return result;
}
#endif //PRIORITIES_AFTER_EXECUTION_H
