//
// Created by andreas on 26.11.24.
//

#ifndef OPTIMIZED_SORT_H
#define OPTIMIZED_SORT_H
#include <algorithm>

template<typename T, typename Comparator>
constexpr void sort_net2(T& x, T& y, Comparator comparator) {
    if (comparator(y, x)) {
        std::swap(x, y);
    }
}

template<typename T, typename Comparator>
constexpr void sort2(T &a, T &b, Comparator comparator) {
    sort_net2(a, b, comparator);
};

template<typename T, typename Comparator>
constexpr void sort3(T &a, T &b, T &c, Comparator comparator) {
    sort_net2(b, c, comparator);
    sort_net2(a, c, comparator);
    sort_net2(a, b, comparator);
};

template<typename T, typename Comparator>
constexpr void sort4(T &a, T &b, T &c, T &d, Comparator comparator) {
    sort_net2(a, b, comparator);
    sort_net2(c, d, comparator);
    sort_net2(a, c, comparator);
    sort_net2(b, d, comparator);
    sort_net2(b, c, comparator);
};

template<typename T, typename Comparator>
constexpr void sort5(T &a, T &b, T &c, T &d, T &e, Comparator comparator) {
    sort_net2(a, b, comparator);
    sort_net2(d, e, comparator);
    sort_net2(c, e, comparator);
    sort_net2(c, d, comparator);
    sort_net2(b, e, comparator);
    sort_net2(a, d, comparator);
    sort_net2(a, c, comparator);
    sort_net2(b, d, comparator);
    sort_net2(b, c, comparator);
};

template<typename T, typename Comparator>
constexpr void sort6(T &a, T &b, T &c, T &d, T &e, T &f, Comparator comparator) {
    sort_net2(b, c, comparator);
    sort_net2(e, f, comparator);
    sort_net2(a, c, comparator);
    sort_net2(d, f, comparator);
    sort_net2(a, b, comparator);
    sort_net2(d, e, comparator);
    sort_net2(c, f, comparator);
    sort_net2(a, d, comparator);
    sort_net2(b, e, comparator);
    sort_net2(c, e, comparator);
    sort_net2(b, d, comparator);
    sort_net2(c, d, comparator);
};
#endif //OPTIMIZED_SORT_H
