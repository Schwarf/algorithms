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
#include <unordered_map>
#include <vector>
#include <cmath>
#include <iostream>
#include <ostream>
#include <set>

int get_max_shared_priority(const std::vector<int>& priorities) {
    std::unordered_map<int, int> frequency_map;
    int max_shared_priority = 0;

    // Build a frequency map of priorities
    for (int priority : priorities) {
        frequency_map[priority]++;
        if (frequency_map[priority] > 1 && priority > max_shared_priority) {
            max_shared_priority = priority;
        }
    }

    return max_shared_priority; // Return the highest shared priority
}

    std::vector<int> priorities_after_execution_brute_force(std::vector<int> priorities) {
    while (true) {
        // Step 1: Find the maximum shared priority
        int max_shared_priority = get_max_shared_priority(priorities);
        if (max_shared_priority == 0) {
            break; // Terminate if no shared priority is found
        }

        bool first_found = false;
        for (size_t i = 0; i < priorities.size(); i++) {
            if (priorities[i] == max_shared_priority) {
                if (!first_found) {
                    // O(N) operation
                    priorities.erase(priorities.begin() + i);
                    i--; // Adjust the index after removal
                    first_found = true;
                } else {
                    priorities[i] = floor(max_shared_priority / 2.0);
                    break;
                }
            }
        }
    }
    return priorities; // Return the final priorities
}



#endif //PRIORITIES_AFTER_EXECUTION_H
