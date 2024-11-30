//
// Created by andreas on 26.11.24.
//

#ifndef OPTIMIZED_SORT_H
#define OPTIMIZED_SORT_H
#include <algorithm>
#include <limits>
#include <bits/random.h>


template <typename ValueType, typename Comparator>
constexpr void sort_net_two(ValueType& x, ValueType& y, Comparator comparator)
{
    if (comparator(y, x))
    {
        std::swap(x, y);
    }
}

template <typename ValueType, typename Comparator>
constexpr void sort_two(ValueType& a, ValueType& b, Comparator comparator)
{
    sort_net_two(a, b, comparator);
};

template <typename ValueType, typename Comparator>
constexpr void sort_three(ValueType& a, ValueType& b, ValueType& c, Comparator comparator)
{
    sort_net_two(b, c, comparator);
    sort_net_two(a, c, comparator);
    sort_net_two(a, b, comparator);
};

template <typename ValueType, typename Comparator>
constexpr void sort_four(ValueType& a, ValueType& b, ValueType& c, ValueType& d, Comparator comparator)
{
    sort_net_two(a, b, comparator);
    sort_net_two(c, d, comparator);
    sort_net_two(a, c, comparator);
    sort_net_two(b, d, comparator);
    sort_net_two(b, c, comparator);
};

template <typename ValueType, typename Comparator>
constexpr void sort_five(ValueType& a, ValueType& b, ValueType& c, ValueType& d, ValueType& e, Comparator comparator)
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

template <typename ValueType, typename Comparator>
constexpr void sort_six(ValueType& a, ValueType& b, ValueType& c, ValueType& d, ValueType& e, ValueType& f,
                        Comparator comparator)
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


template <std::random_access_iterator RandomIterator, typename Comparator>
typename std::iterator_traits<RandomIterator>::value_type
choose_pivot(RandomIterator begin, RandomIterator end, Comparator comparator) {
    auto middle = begin + (end - begin) / 2; // Middle index
    if (comparator(*middle, *begin)) std::iter_swap(middle, begin);
    if (comparator(*(end - 1), *begin)) std::iter_swap(end - 1, begin);
    if (comparator(*(end - 1), *middle)) std::iter_swap(end - 1, middle);
    return *middle;
}

template <std::random_access_iterator RandomIterator, typename Comparator>
std::pair<RandomIterator, RandomIterator> three_way_partition(RandomIterator begin, RandomIterator end,
                                                              Comparator comparator)
{
    RandomIterator lower = begin;
    RandomIterator higher = end;
    auto pivot = choose_pivot(begin, end, comparator);

    auto current = begin;
    while (current <= higher)
    {
        if (comparator(*current, pivot))
            std::iter_swap(lower++, current++); // Move pivot to the left
        else if (comparator(pivot, *current))
            std::iter_swap(current, higher--); // Move pivot to the right
        else
            ++current;
    }

    return {lower, higher};
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

template <typename RandomIterator>
unsigned find_maximal_depth(RandomIterator low, RandomIterator high)
{
    return (sizeof(int) * __CHAR_BIT__ - 1 - __builtin_clz(high - low)) * 2;
}


template <std::random_access_iterator RandomAccessIterator, typename Comparator>
void optimized_sort(RandomAccessIterator begin, RandomAccessIterator end, unsigned int depth, Comparator comparator)
{
    constexpr int insertion_sort_threshold{25};
    while (begin <= end)
    {
        const auto distance = end - begin + 1;

        if (distance <= 1)
            return;

        switch (distance)
        {
        case 2:
            sort_two(*begin, *(begin + 1), comparator);
            return;
        case 3:
            sort_three(*begin, *(begin + 1), *(begin + 2), comparator);
            return;
        case 4:
            sort_four(*begin, *(begin + 1), *(begin + 2), *(begin + 3), comparator);
            return;
        case 5:
            sort_five(*begin, *(begin + 1), *(begin + 2), *(begin + 3), *(begin + 4), comparator);
            return;
        case 6:
            sort_six(*begin, *(begin + 1), *(begin + 2), *(begin + 3), *(begin + 4), *(begin + 5), comparator);
            return;
        default:
            break;
        }
        if (distance <= insertion_sort_threshold)
        {
            insertion_sort(begin, end + 1, comparator);
            return;
        }
        if (depth == 0)
        {
            std::make_heap(begin + 1, end, comparator);
            std::sort_heap(begin + 1, end, comparator);
            return;
        }


        auto partition_indices = three_way_partition(begin, end, comparator);

        if (partition_indices.first - begin < end - partition_indices.second)
        {
            optimized_sort(begin, partition_indices.first - 1, depth - 1, comparator);
            begin = partition_indices.second + 1;
        }
        else
        {
            optimized_sort(partition_indices.second + 1, end, depth - 1, comparator);
            end = partition_indices.first - 1;
        }

        depth -= 1;
    }
}

template <typename Container, typename Comparator>
void optimized_sort(Container& container, Comparator comparator = std::less())
{
    auto begin = container.begin();
    auto end = container.end();
    --end;
    optimized_sort(begin, end, find_maximal_depth(begin, end), comparator);
}


#endif //OPTIMIZED_SORT_H
