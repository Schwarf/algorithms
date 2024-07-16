//
// Created by andreas on 16.07.24.
//

#ifndef DATA_STRUCTURES_ROBOT_COLLISIONS_H
#define DATA_STRUCTURES_ROBOT_COLLISIONS_H
// There are n robots, each having a position on a line, health, and movement direction.
// You are given 0-indexed integer arrays positions, healths, and a string directions (directions[i] is either \
// 'L' for left or 'R' for right). All integers in positions are unique.
// All robots start moving on the line simultaneously at the same speed in their given directions.
// If two robots ever share the same position while moving, they will collide.
// If two robots collide, the robot with lower health is removed from the line, and the health of the other
// robot decreases by one. The surviving robot continues in the same direction it was going.
// If both robots have the same health, they are both removed from the line.
// Your task is to determine the health of the robots that survive the collisions,
// in the same order that the robots were given, i.e. final heath of robot 1 (if survived), final health
// of robot 2 (if survived), and so on. If there are no survivors, return an empty array.
// Return an array containing the health of the remaining robots (in the order they were given in the input),
// after no further collisions can occur.
// Note: The positions may be unsorted.
#include <vector>
#include <string>
#include <stack>
#include <numeric>

std::vector<int> survivedRobotsHealths(std::vector<int> &positions,
                                       std::vector<int> &healths, std::string directions) {
    int n = positions.size();
    std::vector<int> indices(n);
    std::iota(indices.begin(), indices.end(), 0);
    std::vector<int> result;
    std::stack<int> stack;

    // Compare the positions of the robots and sort indices accordingly to the provided positions.
    // Alternative: Using a tuple for positions, healths and directions and sport that according to positions did
    // not work
    std::sort(indices.begin(), indices.end(),
              [&](int lhs, int rhs) { return positions[lhs] < positions[rhs]; });

    for (int currentIndex: indices) {
        // Add right-moving robots to the stack
        if (directions[currentIndex] == 'R') {
            stack.push(currentIndex);
        } else {
            while (!stack.empty() && healths[currentIndex] > 0) {
                // Pop the top robot from the stack for collision check
                int topIndex = stack.top();
                stack.pop();

                // Top robot survives, current robot is destroyed
                if (healths[topIndex] > healths[currentIndex]) {
                    healths[topIndex] -= 1;
                    healths[currentIndex] = 0;
                    stack.push(topIndex);
                } else if (healths[topIndex] < healths[currentIndex]) {
                    // Current robot survives, top robot is destroyed
                    healths[currentIndex] -= 1;
                    healths[topIndex] = 0;
                } else {
                    // Both robots are destroyed
                    healths[currentIndex] = 0;
                    healths[topIndex] = 0;
                }
            }
        }
    }

    // Collect surviving robots
    for (int index = 0; index < n; ++index) {
        if (healths[index] > 0) {
            result.push_back(healths[index]);
        }
    }
    return result;
}

#endif //DATA_STRUCTURES_ROBOT_COLLISIONS_H
