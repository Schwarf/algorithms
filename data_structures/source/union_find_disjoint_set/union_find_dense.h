//
// Created by andreas on 31.01.23.
//

#ifndef OPTIMIZED_DISJOINT_SET_H
#define OPTIMIZED_DISJOINT_SET_H
#include <vector>
#include <optional>

template <typename IdType>
requires std::is_signed_v<IdType>
class UnionFindDense
{
    bool in_set(IdType value)
    {
        return 0 <= value && value < roots.size() && roots[value] != -1;
    }

public:
    explicit UnionFindDense(int size)
        :
        roots(size),
        ranks(size)
    {
        for (int i{}; i < size; ++i)
        {
            roots[i] = IdType{i};
            ranks[i] = 0;
        }
    }

    std::optional<IdType> find_root(IdType value)
    {
        if(!in_set(value))
            return std::nullopt;
        if (value == roots[value])
            return value;
        return roots[value] = *find_root(roots[value]);
    }

    void union_set(IdType value1, IdType value2)
    {
        auto root1 = find_root(value1);
        auto root2 = find_root(value2);
        if (!root1 || !root2)
            return;
        IdType root_value1 = *root1;
        IdType root_value2 = *root2;
        if (root_value1 == root_value2)
            return;
        if (ranks[root_value1] > ranks[root_value2])
            roots[root_value2] = root_value1;
        else if (ranks[root_value1] < ranks[root_value2])
            roots[root_value1] = root_value2;
        else
        {
            roots[root_value2] = root_value1;
            ranks[root_value1]++;
        }
    }

    bool are_connected(IdType value1, IdType value2)
    {
        auto r1 = find_root(value1);
        auto r2 = find_root(value2);
        if (!r1 || !r2)
            return false;

        return *r1 == *r2;
    }

private:
    std::vector<IdType> roots;
    std::vector<IdType> ranks;
};

#endif //OPTIMIZED_DISJOINT_SET_H
