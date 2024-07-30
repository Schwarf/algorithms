//
// Created by andreas on 30.07.24.
//

#ifndef DATA_STRUCTURES_FENWICK_TREE_H
#define DATA_STRUCTURES_FENWICK_TREE_H

#include <vector>

template<typename T> requires std::is_arithmetic_v<T>
class FenwickTree {
public:
    FenwickTree() = default;

    FenwickTree(const std::vector<T> &data) {
        size = data.size() + 1;
        binary_indexed_tree = std::vector<T>(T{}, size);
        for (int i{}; i < data.size(); ++i) {
            update(i, data[i]);
        }
    }

    void update(int index, const T &data) {
        for (++index; index < size; index += index & -index)
            binary_indexed_tree[index] += data;
    }

    T get_sum(int left_index, int right_index) {
        return sum(right_index) - sum(left_index - 1);
    }

    T sum(int index) {
        T result{};
        for (++index; index > 0; index -= index & -index)
            result += binary_indexed_tree[index];
        return result;
    }

private:
    std::vector<T> binary_indexed_tree{};
    size_t size{};
};

#endif //DATA_STRUCTURES_FENWICK_TREE_H
