//
// Created by andreas on 30.03.25.
//

#ifndef K_D_TREE_H
#define K_D_TREE_H
#include <memory>
#include <vector>
#include <array>
#include <algorithm>
#include <ranges>

template <typename T, size_t dimensions>
class KDTree
{
    struct Node
    {
        std::array<T, dimensions> point;
        std::unique_ptr<Node> left;
        std::unique_ptr<Node> right;

        Node(const std::array<T, dimensions>& pt): point(pt), left(nullptr), right(nullptr)
        {
        }
    };

    std::unique_ptr<Node> root;

    std::unique_ptr<Node> build_tree(const std::vector<std::array<T, dimensions>>& points, int depth, int start,
                                     int end)
    {
        if (start >= end)
        {
            return nullptr;
        }
        int axis = depth % dimensions;
        int mid = start + (end - start) / 2;
        std::nth_element(points.begin() + start, points.begin() + mid, points.begin() + end,
            [axis](const std::array<T, dimensions>& p1, const std::array<T, dimensions>& p2)
            {
                return p1[axis] < p2[axis];
            });
        std::unique_ptr<Node> node = std::make_unique<Node>(points[mid]);
        node->left = build_tree(points, depth + 1, start, mid);
        node->right = build_tree(points, depth + 1, mid+1, mid);
        return node;
    }

    T squared_euclidean_distance(const std::array<T, dimensions>& point1, const std::array<T, dimensions>& point2)
    {
        T result{};
        for(size_t i = 0; i < dimensions; i++)
        {
            result += (point1[i] - point2[i]) * (point1[i] - point2[i]);
        }
        return result;
    }

};

#endif //K_D_TREE_H
