//
// Created by andreas on 26.11.24.
//

#ifndef OPTIMIZED_SORT_H
#define OPTIMIZED_SORT_H
#include <algorithm>
#include <limits>
#include <bits/random.h>


template <typename T, typename Comparator>
constexpr void sort_net2(T& x, T& y, Comparator comparator)
{
    if (comparator(y, x))
    {
        std::swap(x, y);
    }
}

template <typename T, typename Comparator>
constexpr void sort2(T& a, T& b, Comparator comparator)
{
    sort_net2(a, b, comparator);
};

template <typename T, typename Comparator>
constexpr void sort3(T& a, T& b, T& c, Comparator comparator)
{
    sort_net2(b, c, comparator);
    sort_net2(a, c, comparator);
    sort_net2(a, b, comparator);
};

template <typename T, typename Comparator>
constexpr void sort4(T& a, T& b, T& c, T& d, Comparator comparator)
{
    sort_net2(a, b, comparator);
    sort_net2(c, d, comparator);
    sort_net2(a, c, comparator);
    sort_net2(b, d, comparator);
    sort_net2(b, c, comparator);
};

template <typename T, typename Comparator>
constexpr void sort5(T& a, T& b, T& c, T& d, T& e, Comparator comparator)
{
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

template <typename T, typename Comparator>
constexpr void sort6(T& a, T& b, T& c, T& d, T& e, T& f, Comparator comparator)
{
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

template<typename RandomIterator, typename Comparator>
typename std::iterator_traits<RandomIterator>::value_type
choose_pivot(RandomIterator low, RandomIterator high, Comparator comp) {
    static std::random_device random_device;
    static std::mt19937 mersenne_twister_engine(random_device());
    static std::uniform_int_distribution<> distribution(0, std::numeric_limits<int>::max());

    const auto size = high - low + 1;

    typename std::iterator_traits<RandomIterator>::value_type x = *(low + distribution(mersenne_twister_engine) % size);
    typename std::iterator_traits<RandomIterator>::value_type y = *(low + distribution(mersenne_twister_engine) % size);
    typename std::iterator_traits<RandomIterator>::value_type z = *(low + distribution(mersenne_twister_engine) % size);

    sort3(x, y, z, comp); // Sort three elements to pick the median as pivot
    return y; // Median of three for better partitioning
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


#endif //OPTIMIZED_SORT_H
