//
// Created by andreas on 07.11.23.
//

#ifndef ELIMINATE_MONSTERS_H
#define ELIMINATE_MONSTERS_H

#include <vector>
#include <queue>

//You are playing a video game where you are defending your city from a group of n monsters. You are given a 0-indexed integer array dist of size n, where dist[i] is the initial distance in kilometers of the ith monster from the city.
//The monsters walk toward the city at a constant speed. The speed of each monster is given to you in an integer array speed of size n, where speed[i] is the speed of the ith monster in kilometers per minute.
//You have a weapon that, once fully charged, can eliminate a single monster. However, the weapon takes one minute to charge. The weapon is fully charged at the very start.
//You lose when any monster reaches your city. If a monster reaches the city at the exact moment the weapon is fully charged, it counts as a loss, and the game ends before you can use your weapon.
//Return the maximum number of monsters that you can eliminate before you lose, or n if you can eliminate all the monsters before they reach the city.
template<typename T>
requires std::is_arithmetic_v<T>
int eliminate_monsters(std::vector<T> &dist, std::vector<T> &speed) {
    std::priority_queue<double, std::vector<double>, std::greater<>> q;
    for (int i{}; i < dist.size(); ++i) {
        q.push(static_cast<double>(dist[i]) / static_cast<double>(speed[i]));
    }
    int time{};
    while (!q.empty()) {
        if (q.top() <= time)
            return time;
        time++;
        q.pop();
    }
    return dist.size();
}

#endif //ELIMINATE_MONSTERS_H


