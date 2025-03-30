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
    requires std::is_floating_point_v<T>
class KDTree
{
public:
    explicit KDTree(std::vector<std::array<T, dimensions>>& points)
    {
        root = build_tree(points, 0, 0, points.size());
    }

    std::array<T, dimensions> nearest_neighbor(const std::array<T, dimensions>& target) const
    {
        std::array<T, dimensions> nearest_point{};
        auto best_distance = std::numeric_limits<T>::max();
        nearest_helper(root.get(), target, 0, nearest_point, best_distance);
        return nearest_point;
    }

private:
    bool equal(const T x, const T y, const double error = 1.e-12) const
    {
        return (x <= (y + error)) && (x >= (y - error));
    }

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

    std::unique_ptr<Node> build_tree(std::vector<std::array<T, dimensions>>& points, int depth, int start,
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
        node->right = build_tree(points, depth + 1, mid + 1, mid);
        return node;
    }

    T squared_euclidean_distance(const std::array<T, dimensions>& point1, const std::array<T, dimensions>& point2) const
    {
        T result{};
        for (size_t i = 0; i < dimensions; i++)
        {
            result += (point1[i] - point2[i]) * (point1[i] - point2[i]);
        }
        return result;
    }

    void nearest_helper(Node* node, const std::array<T, dimensions>& target, int depth,
                        std::array<T, dimensions>& nearest_point,
                        T& best_distance) const
    {
        if (!node)
            return;
        int axis = depth % dimensions;
        auto squared_distance = squared_euclidean_distance(target, node->point);

        if (squared_distance < best_distance || (equal(squared_distance, best_distance) && node->point < nearest_point))
        {
            best_distance = squared_distance;
            nearest_point = node->point;
        }
        auto difference = target[axis] - node->point[axis];
        Node* nearest_child = (difference < 0) ? node->left.get() : node->right.get();
        Node* farest_child = (difference < 0) ? node->right.get() : node->left.get();

        nearest_helper(nearest_child, target, depth + 1, nearest_point, best_distance);
        if (difference * difference < best_distance)
            nearest_helper(farest_child, target, depth + 1, nearest_point, best_distance);
    }
};

#endif //K_D_TREE_H
