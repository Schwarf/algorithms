//
// Created by andreas on 05.02.23.
//

#ifndef UNION_FIND_SPARSE_H
#define UNION_FIND_SPARSE
#include <unordered_map>
#include <optional>

template <typename IdType>
class UnionFindSparse
{
public:
    bool add_set(const IdType& element)
    {
        if (parent_mapping.find(element) != parent_mapping.end())
            return false;
        parent_mapping[element] = element;
        rank[element] = 1;
        return true;
    }

    std::optional<IdType> get_root(const IdType& element)
    {
        auto it = parent_mapping.find(element);
        if (it == parent_mapping.end())
            return std::nullopt;
        if (it->second == element)
            return element;
        auto root = get_root(it->second);
        if (!root)
            return std::nullopt;
        it->second = *root;
        return it->second;
    }

    void union_set(const IdType& element1, const IdType& element2)
    {
        auto r1 = get_root(element1);
        auto r2 = get_root(element2);
        if (!r1 || !r2)
            return;

        auto root1 = *r1;
        auto root2 = *r2;
        if (root1 == root2)
            return;
        if (rank[root1] > rank[root2])
            parent_mapping[root2] = root1;
        else if (rank[root1] < rank[root2])
            parent_mapping[root1] = root2;
        else
        {
            parent_mapping[root2] = root1;
            rank[root1]++;
        }
    }

    bool are_connected(const IdType& element1, const IdType& element2)
    {
        auto r1 = get_root(element1);
        auto r2 = get_root(element2);
        if (!r1 || !r2)
            return false;
        return *r1 == *r2;
    }

private:
    std::unordered_map<IdType, IdType> parent_mapping;
    std::unordered_map<IdType, std::size_t> rank;
};

#endif //UNION_FIND_SPARSE
