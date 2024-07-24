//
// Created by andreas on 05.11.23.
//

#ifndef SPIDER_BRAINTEASER_H
#define SPIDER_BRAINTEASER_H

#include <vector>
#include <algorithm>
// We have a wooden plank of the length n units. Some spiders are walking on the plank,
// each spider moves with a speed of 1 unit per second. Some of the spiders move to the left, the other move to the right.
// When two spiders moving in two different directions meet at some point, they change their 
// directions and continue moving again. Assume changing directions does not take any additional time.
// When an spider reaches one end of the plank at a time t, it falls out of the plank immediately.
// Given an integer n and two integer arrays left and right, the positions of the spiders 
// moving to the left and the right, return the moment when the last spider(s) fall out of the plank.

template<typename T, typename = typename std::enable_if<std::is_unsigned_v<T>>>
T get_last_moment(T n, const std::vector<T> &left, const std::vector<T> &right) {
    T ans = 0;
    for (auto num: left) {
        ans = std::max(ans, num);
    }

    for (auto num: right) {
        ans = std::max(ans, n - num);
    }

    return ans;
}

#endif //SPIDER_BRAINTEASER_H
