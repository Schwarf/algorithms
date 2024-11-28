//
// Created by andreas on 26.11.24.
//

#ifndef OPTIMIZED_SORT_H
#define OPTIMIZED_SORT_H
#include <algorithm>
#include <limits>
#include <bits/random.h>


template <typename T, typename Comparator>
constexpr void sort_net_two(T& x, T& y, Comparator comparator)
{
    if (comparator(y, x))
    {
        std::swap(x, y);
    }
}

template <typename T, typename Comparator>
constexpr void sort_two(T& a, T& b, Comparator comparator)
{
    sort_net_two(a, b, comparator);
};

template <typename T, typename Comparator>
constexpr void sort_three(T& a, T& b, T& c, Comparator comparator)
{
    sort_net_two(b, c, comparator);
    sort_net_two(a, c, comparator);
    sort_net_two(a, b, comparator);
};

template <typename T, typename Comparator>
constexpr void sort_four(T& a, T& b, T& c, T& d, Comparator comparator)
{
    sort_net_two(a, b, comparator);
    sort_net_two(c, d, comparator);
    sort_net_two(a, c, comparator);
    sort_net_two(b, d, comparator);
    sort_net_two(b, c, comparator);
};

template <typename T, typename Comparator>
constexpr void sort_five(T& a, T& b, T& c, T& d, T& e, Comparator comparator)
{
    sort_net_two(a, b, comparator);
    sort_net_two(d, e, comparator);
    sort_net_two(c, e, comparator);
    sort_net_two(c, d, comparator);
    sort_net_two(b, e, comparator);
    sort_net_two(a, d, comparator);
    sort_net_two(a, c, comparator);
    sort_net_two(b, d, comparator);
    sort_net_two(b, c, comparator);
};

template <typename T, typename Comparator>
constexpr void sort_six(T& a, T& b, T& c, T& d, T& e, T& f, Comparator comparator)
{
    sort_net_two(b, c, comparator);
    sort_net_two(e, f, comparator);
    sort_net_two(a, c, comparator);
    sort_net_two(d, f, comparator);
    sort_net_two(a, b, comparator);
    sort_net_two(d, e, comparator);
    sort_net_two(c, f, comparator);
    sort_net_two(a, d, comparator);
    sort_net_two(b, e, comparator);
    sort_net_two(c, e, comparator);
    sort_net_two(b, d, comparator);
    sort_net_two(c, d, comparator);
};

template<typename RandomIterator, typename Comparator>
typename std::iterator_traits<RandomIterator>::value_type
choose_pivot(RandomIterator low, RandomIterator high, Comparator comparator) {
    static std::random_device random_device;
    static std::mt19937 mersenne_twister_engine(random_device());
    static std::uniform_int_distribution<> distribution(0, std::numeric_limits<int>::max());

    const auto size = high - low + 1;

    typename std::iterator_traits<RandomIterator>::value_type value1 = *(low + distribution(mersenne_twister_engine) % size);
    typename std::iterator_traits<RandomIterator>::value_type value2 = *(low + distribution(mersenne_twister_engine) % size);
    typename std::iterator_traits<RandomIterator>::value_type value3 = *(low + distribution(mersenne_twister_engine) % size);

    sort3(value1, value2, value3, comparator); // Sort three elements to pick the median as pivot
    return value2; // Median of three for better partitioning
}


template <std::random_access_iterator RandomAccessIterator, typename Comparator>
bool insertion_sort(RandomAccessIterator begin, RandomAccessIterator end, Comparator comp,
                    const int max_distance = std::numeric_limits<int>::max())
{
    for (auto iterator = begin + 1; iterator < end; ++iterator)
    {
        auto element = std::move(*iterator);
        decltype(iterator) other_iterator;
        int distance{};

        for (other_iterator = iterator; other_iterator > begin && comp(element, *(other_iterator - 1)); --
             other_iterator)
        {
            *other_iterator = std::move(*(other_iterator - 1));
            if (++distance > max_distance)
                return false;
        }

        *other_iterator = element;
    }

    return true;
}


template<typename RandomIterator, typename Comparator>
   void intro_sort(RandomIterator low, RandomIterator high, unsigned int depth, Comparator comp)
{
    constexpr int insertion_sort_threshold{25};
    constexpr int maximal_distance{15};

    while (low <= high)
    {
        const auto distance = high - low + 1;

        if (distance <= 1)
            return;

        /* For very small ranges (< 7 elements) we use a sorting network */
        switch (distance) {
        case 2:
            sort_two(*low, *(low + 1), comp);
            return;
        case 3:
            sort_three(*low, *(low + 1), *(low + 2), comp);
            return;
        case 4:
            sort_four(*low, *(low + 1), *(low + 2), *(low + 3), comp);
            return;
        case 5:
            sort_five(*low, *(low + 1), *(low + 2), *(low + 3), *(low + 4), comp);
            return;
        case 6:
            sort_six(*low, *(low + 1), *(low + 2), *(low + 3), *(low + 4), *(low + 5), comp);
            return;
        default:
            break;
        }
        if(distance < insertion_sort_threshold)
        {
            insertion_sort(low, high+1, comp);
            return;
        }

    }

}

#endif //OPTIMIZED_SORT_H
