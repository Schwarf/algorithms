//
// Created by andreas on 14.07.23.
//

#ifndef NTH_UGLY_NUMBER_H
#define NTH_UGLY_NUMBER_H
// An ugly number is a positive integer whose prime factors are limited to 2, 3, and 5.
// Given an integer n, return the nth ugly number.
#include <vector>
#include <set>

bool is_ugly(int num) {
    if (num == 1)
        return true;
    if (num % 2 == 0)
        return is_ugly(num / 2);
    if (num % 3 == 0)
        return is_ugly(num / 3);
    if (num % 5 == 0)
        return is_ugly(num / 5);
    return false;
}

int nth_ugly_number_recursive(int n, int num = 1) {
    if (n == 1)
        return num;
    int next = num + 1;
    while (!is_ugly(next))
        next++;
    return nth_ugly_number_recursive(n - 1, next);
}

// O(n) time complexity, O(n) space complexity
int nth_ugly_number(int n) {
    std::vector<int> ugly(n);
    ugly[0] = 1;
    int index2{}, index3{}, index5{};
    int count{1};
    while (count < n) {
        int value2 = ugly[index2] * 2;
        int value3 = ugly[index3] * 3;
        int value5 = ugly[index5] * 5;
        int value = std::min({value2, value3, value5});
        if (value == value2)
            index2++;
        if (value == value3)
            index3++;
        if (value == value5)
            index5++;
        ugly[count++] = value;
    }
    return ugly[n - 1];
}

// O(n *log(m)) where m is the size of the set
int nth_ugly_number_set(int n) {
    std::set<long long> ugly_set;
    ugly_set.insert(1);

    long long current_ugly{1};
    for (int i{}; i < n; ++i) {
        current_ugly = *ugly_set.begin();
        ugly_set.erase(ugly_set.begin());
        ugly_set.insert(current_ugly * 2);
        ugly_set.insert(current_ugly * 3);
        ugly_set.insert(current_ugly * 5);

    }
    return static_cast<int>(current_ugly);
}


#endif //NTH_UGLY_NUMBER_H
