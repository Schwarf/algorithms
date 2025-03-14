//
// Created by andreas on 14.03.25.
//

#ifndef EXECUTE_PROCESSES_H
#define EXECUTE_PROCESSES_H

// Execute Processes
// There are several processors for executing processes scheduled on the servers.
// There are n processes to be executed, where the ith process takes execution[i] amount of time to execute.
// Two processes are cohesive if and only if their original execution times are equal.
// When a process with execution time execution[i] is executed, it takes execution[i] time to
// complete and simultaneously reduces the execution time of all its cohesive processes to ceil(execution[i] / 2) .
// Given the execution time of n processes, find the total amount of time the processor takes to
// execute all the processes if you execute the processes in the given order, i.e. from left to right.
// Notes
// - The ceil() function returns the smallest integer that is bigger or equal to its argument.
//   For example, ceil(1.1) = 2 , ceil(2.5) = 3 , ceil(5) = 5 , etc.
// - If the execution time of some process i is reduced and becomes equal to the execution time of any
//   other process j , then the two processes i and j are not considered cohesive.
// Function Description
// Complete the function totalExecutionTime in the editor.
// totalExecutionTime has the following parameter:
// int execution[n] : an array of integers representing the execution times
#include <vector>
#include <unordered_map>
#include <deque>
#include <cmath>
int time_to_execute_process(std::vector<int>& processes)
{
    int n = processes.size();
    std::unordered_map<int, std::vector<int>> processes_index;

    // Build a map where each processes time has a list of its indices
    for (int i = 0; i < n; i++) {
        processes_index[processes[i]].push_back(i);
    }

    int total_time = 0;

    for (int i = 0; i < n; i++) {
        total_time += processes[i]; // Add execution time
        // Get the list of indices that had the same execution time originally
        std::vector <int>& indexes = processes_index[processes[i]];

        if (!indexes.empty() && indexes.front() == i) {

            // Update execution times for the remaining cohesive processes
            int new_execution_time = ceil(processes[i] / 2.0);
            for (int index : indexes) {
                processes[index] = new_execution_time; // Update the execution time
            }
        }
    }
    return total_time;
}

#endif //EXECUTE_PROCESSES_H
