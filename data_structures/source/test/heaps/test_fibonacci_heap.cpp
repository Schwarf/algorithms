//
// Created by andreas on 23.04.24.
//
#include "gtest/gtest.h"
#include "heaps/fibonacci_heap.h"
#include <queue>
#include <random>
#include <unordered_map>

class SetupFibonacciHeap : public testing::Test {
public:
    static inline std::vector<std::pair<int, double>> get_random_n_numbers(int n) {
        if (n < 1)
            return {};
        int lower_bound = -10 * n;
        int upper_bound = 10 * n;
        auto int_distribution_ = std::uniform_int_distribution<int>(lower_bound, upper_bound);
        auto double_distribution_ = std::uniform_real_distribution<double>(lower_bound, upper_bound);
        std::random_device device;
        auto generator = std::mt19937(device());
        std::vector<std::pair<int, double>> result{};
        // Currently the "order" of elements with the same key is undetermined in the Fibonacci heap. Therefore each
        // key-element can only appear once.
        std::set<int> unique_keys;
        for (int i{}; i < n; ++i) {

            auto key = int_distribution_(generator);
            if (unique_keys.contains(key))
                continue;
            auto value = double_distribution_(generator);
            result.emplace_back(key, value);
            unique_keys.insert(key);
        }
        return result;
    }

    template<typename T>
    std::string VectorToString(const std::vector<T> &vec) {
        std::ostringstream oss;
        oss << "{";
        for (size_t i = 0; i < vec.size(); ++i) {
            oss << vec[i];
            if (i < vec.size() - 1) {
                oss << ", ";
            }
        }
        oss << "}";
        return oss.str();
    }

};


TEST(TestFibonacciHeap, insert) {
    constexpr double value1{1.0};
    constexpr double value2{2.0};
    constexpr double value3{3.0};

    constexpr int key1{1};
    constexpr int key2{2};
    constexpr int key3{3};

    auto heap = FibonacciHeap<int, double>();
    heap.insert(key1, value1);
    heap.insert(key2, value2);
    heap.insert(key3, value3);
    EXPECT_EQ(value1, heap.get_min());
    EXPECT_TRUE(heap.check_heap_property());
}


TEST(TestFibonacciHeap, heap_property) {
    constexpr double value1{10.0};
    constexpr double value2{20.0};
    constexpr double value3{30.0};
    constexpr double value4{40.0};
    constexpr double value5{50.0};
    constexpr int key1{1};
    constexpr int key2{2};
    constexpr int key3{3};
    constexpr int key4{4};
    constexpr int key5{5};
    auto heap = FibonacciHeap<int, double>();
    heap.insert(key3, value3);
    heap.insert(key2, value2);
    heap.insert(key5, value5);
    heap.insert(key1, value1);
    heap.insert(key4, value4);
    EXPECT_TRUE(heap.check_heap_property()) << "Heap property should be intact.";
    EXPECT_EQ(value1, heap.get_min());
}

TEST(TestFibonacciHeap, merge) {
    constexpr double value1{10.0};
    constexpr double value2{20.0};
    constexpr double value3{30.0};
    constexpr double value4{40.0};
    constexpr double value5{50.0};
    constexpr int key1{1};
    constexpr int key2{2};
    constexpr int key3{3};
    constexpr int key4{4};
    constexpr int key5{5};
    auto heap1 = FibonacciHeap<int, double>();
    auto heap2 = FibonacciHeap<int, double>();
    heap1.insert(key3, value3);
    heap2.insert(key2, value2);
    heap1.insert(key5, value5);
    heap2.insert(key1, value1);
    heap1.insert(key4, value4);
    EXPECT_TRUE(heap1.check_heap_property()) << "Heap property should be intact.";
    EXPECT_TRUE(heap2.check_heap_property()) << "Heap property should be intact.";
    EXPECT_EQ(value3, heap1.get_min());
    EXPECT_EQ(value1, heap2.get_min());
    heap1.merge(heap2);
    EXPECT_TRUE(heap1.check_heap_property());
    EXPECT_EQ(heap1.get_min(), value1);
}


TEST(TestFibonacciHeap, pop_min) {
    constexpr double value1{10.0};
    constexpr double value2{20.0};
    constexpr double value3{30.0};
    constexpr double value4{40.0};
    constexpr double value5{50.0};
    constexpr int key1{1};
    constexpr int key2{2};
    constexpr int key3{3};
    constexpr int key4{4};
    constexpr int key5{5};
    auto heap = FibonacciHeap<int, double>();
    heap.insert(key3, value3);
    heap.insert(key2, value2);
    heap.insert(key5, value5);
    heap.insert(key1, value1);
    heap.insert(key4, value4);
    EXPECT_TRUE(heap.check_heap_property()) << "Heap property should be intact.";
    EXPECT_EQ(heap.size(), 5);
    EXPECT_EQ(value1, heap.get_min());
    EXPECT_EQ(value1, heap.pop_min());
    EXPECT_EQ(heap.size(), 4);
    EXPECT_TRUE(heap.check_heap_property()) << "Heap property should be intact.";
    EXPECT_EQ(value2, heap.get_min());
    EXPECT_EQ(value2, heap.pop_min());
    EXPECT_EQ(heap.size(), 3);
    EXPECT_TRUE(heap.check_heap_property()) << "Heap property should be intact.";
    EXPECT_EQ(value3, heap.get_min());
    EXPECT_EQ(value3, heap.pop_min());
    EXPECT_EQ(heap.size(), 2);
    EXPECT_TRUE(heap.check_heap_property()) << "Heap property should be intact.";
    EXPECT_EQ(value4, heap.get_min());
    EXPECT_EQ(value4, heap.pop_min());
    EXPECT_EQ(heap.size(), 1);
    EXPECT_TRUE(heap.check_heap_property()) << "Heap property should be intact.";
    EXPECT_EQ(value5, heap.get_min());
    EXPECT_EQ(value5, heap.pop_min());
    EXPECT_EQ(heap.size(), 0);
    EXPECT_TRUE(heap.is_empty());
    EXPECT_TRUE(heap.check_heap_property()) << "Heap property should be intact.";
}

TEST(TestFibonacciHeap, decrease_key) {
    constexpr double value1{10.0};
    constexpr double value2{20.0};
    constexpr double value3{30.0};
    constexpr double value4{40.0};
    constexpr double value5{50.0};
    constexpr int key1{1};
    constexpr int key2{2};
    constexpr int key3{3};
    constexpr int key4{4};
    constexpr int key5{5};
    auto heap = FibonacciHeap<int, double>();
    heap.insert(key3, value3);
    heap.insert(key2, value2);
    heap.insert(key5, value5);
    auto node1 = heap.insert(key1, value1);
    heap.insert(key4, value4);
    EXPECT_TRUE(heap.check_heap_property()) << "Heap property should be intact.";
    EXPECT_EQ(heap.size(), 5);
    EXPECT_EQ(value1, heap.get_min());
    constexpr double new_key1{};
    heap.decrease_key(node1, new_key1);
    EXPECT_TRUE(heap.check_heap_property());
    EXPECT_EQ(value1, heap.get_min());
}


TEST(TestFibonacciHeap, decrease_key_mix) {
    constexpr double value1{10.0};
    constexpr double value2{20.0};
    constexpr double value3{30.0};
    constexpr double value4{40.0};
    constexpr double value5{50.0};
    constexpr int key1{1};
    constexpr int key2{2};
    constexpr int key3{3};
    constexpr int key4{4};
    constexpr int key5{5};
    auto heap = FibonacciHeap<int, double>();
    auto node3 = heap.insert(key3, value3);
    heap.insert(key2, value2);
    auto node5 = heap.insert(key5, value5);
    heap.insert(key1, value1);
    heap.insert(key4, value4);
    EXPECT_TRUE(heap.check_heap_property()) << "Heap property should be intact.";
    EXPECT_EQ(heap.size(), 5);
    EXPECT_EQ(value1, heap.get_min());
    constexpr double new_key3{};
    heap.decrease_key(node3, new_key3);
    EXPECT_TRUE(heap.check_heap_property());
    EXPECT_EQ(value3, heap.get_min());
    constexpr double value6{60.0};
    constexpr int key6{-1};
    EXPECT_EQ(value3, heap.pop_min());
    EXPECT_EQ(heap.size(), 4);
    EXPECT_EQ(value1, heap.get_min());
    heap.insert(key6, value6);
    EXPECT_EQ(value6, heap.get_min());
    EXPECT_EQ(heap.size(), 5);
    constexpr int new_key5{-10};
    heap.decrease_key(node5, new_key5);
    EXPECT_EQ(value5, heap.get_min());
    EXPECT_EQ(heap.size(), 5);
}

TEST_F(SetupFibonacciHeap, RandomSetupPopMin) {
    struct Comparator {
        bool operator()(const std::pair<int, double> node1, const std::pair<int, double> node2) {
            return node1.first > node2.first;
        }
    };
    for (int runs{}; runs < 150; ++runs) {
        std::priority_queue<std::pair<int, double>, std::vector<std::pair<int, double>>, Comparator> q;
        constexpr int number_of_random_inputs{1000};
        auto input = get_random_n_numbers(number_of_random_inputs);
        auto heap = FibonacciHeap<int, double>();
        for (const auto &element: input) {
            auto node = heap.insert(element.first, element.second);
            q.push({element.first, element.second});
            EXPECT_FLOAT_EQ(q.top().second, heap.get_min());
            EXPECT_EQ(q.size(), heap.size());
            if (q.size() > 100) {
                for (int i{}; i < 33; ++i) {
                    q.pop();
                    heap.pop_min();
                    EXPECT_EQ(q.size(), heap.size());
                    EXPECT_FLOAT_EQ(q.top().second, heap.get_min());

                }
            }
        }
    }
}


TEST_F(SetupFibonacciHeap, RandomSetupDecreaseKey) {
    for (int runs{}; runs < 20; runs++) {
        constexpr int number_of_random_inputs{1000};
        auto input = get_random_n_numbers(number_of_random_inputs);
        auto heap = FibonacciHeap<int, double>();
        std::vector<Node<int, double> *> nodes;
        std::set<int> unique_keys;
        for (const auto &element: input) {
            auto node = heap.insert(element.first, element.second);
            unique_keys.insert(element.first);
            nodes.emplace_back(node);
        }


        constexpr int number_of_decreases{50};
        for (int i{}; i < number_of_decreases; ++i) {
            auto node_index = rand() % nodes.size();
            auto node = nodes[node_index];
            int new_key = node->key - (rand() % 100);
            if (unique_keys.contains(new_key))
                continue;
            heap.decrease_key(node, new_key);
            node->key = new_key;
            nodes[node_index] = node;
            unique_keys.insert(new_key);
            EXPECT_TRUE(heap.check_heap_property());
        }
        std::map<int, double> map;
        for (const auto &node: nodes) {
            map[node->key] = node->value;
        }
        EXPECT_EQ(map.size(), heap.size());
        while (!heap.is_empty()) {
            EXPECT_EQ(map.size(), heap.size());
            EXPECT_EQ(heap.pop_min(), map.begin()->second);
            map.erase(map.begin());
            EXPECT_EQ(map.size(), heap.size());

        }
    }
}