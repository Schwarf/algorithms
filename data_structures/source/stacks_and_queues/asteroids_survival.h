//
// Created by andreas on 20.07.23.
//

#ifndef DATA_STRUCTURES_ASTEROIDS_SURVIVAL_H
#define DATA_STRUCTURES_ASTEROIDS_SURVIVAL_H

#include <stack>
#include <concepts>
#include <vector>
// Given a list of asteroids on collision course. The positive ones fly to the right the negative ones to the left.
// If they hit each other the larger one survives. If they are of the same size they both get destroyed.

template<typename T>
requires std::is_arithmetic_v<T>
std::vector<T> survived_asteroids(const std::vector<T> &asteroids) {
    std::stack<T> s;
    for (const auto &asteroid: asteroids) {
        bool survived{true};
        //  We check for clash if asteroid is left-flying and s.top() is right flying
        while (!s.empty() && s.top() > 0 && asteroid < 0) {
            if (std::abs(s.top()) < std::abs(asteroid)) {
                s.pop();
                continue;
            } else if (std::abs(s.top()) == std::abs(asteroid))
                s.pop();

            survived = false;
            break;
        }
        if (survived)
            s.push(asteroid);
    }
    std::vector<T> survivors(s.size());
    for (int i = s.size() - 1; i > -1; --i) {
        survivors[i] = s.top();
        s.pop();
    }
    return survivors;

}

#endif //DATA_STRUCTURES_ASTEROIDS_SURVIVAL_H
