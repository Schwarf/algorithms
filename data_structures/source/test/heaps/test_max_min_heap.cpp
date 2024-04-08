//
// Created by andreas on 03.04.24.
//
#include "gtest/gtest.h"
#include "heaps/max_min_heap.h"
#include <random>
#include <utility>
#include <algorithm>

class SetupMaxMinHeap : public testing::Test {
public:
    template<typename T>
    static inline std::pair<std::vector<T>, std::vector<T>> get_random_n_numbers(int n) {
        if (n < 1)
            return std::make_pair(std::vector<T>(), std::vector<T>());
        int lower_bound{};
        int upper_bound = 10 * n;
        auto int_distribution_ = std::uniform_int_distribution<int>(lower_bound, upper_bound);
        std::vector<T> input{};
        std::vector<T> output{};
        std::random_device device;
        auto generator = std::mt19937(device());
        for (int i{}; i < n; ++i) {
            auto value = int_distribution_(generator);
            input.push_back(static_cast<T>(value));
            output.push_back(static_cast<T>(value));
        }
        std::sort(output.begin(), output.end());

        return std::make_pair(input, output);
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

TEST_F(SetupMaxMinHeap, TestMinAndMaxThrowsWhenHeapEmpty) {
    auto max_min_heap = MaxMinHeap<int>();
    EXPECT_THROW(max_min_heap.min(), std::underflow_error);
    EXPECT_THROW(max_min_heap.max(), std::underflow_error);
}


TEST_F(SetupMaxMinHeap, TestMinAndMaxSmallSequence) {
    for (int count{}; count < 100; ++count) {

        constexpr int number_of_elements{100};
        auto [input, output] = get_random_n_numbers<int>(number_of_elements);
        auto max_min_heap = MaxMinHeap<int>();
        for (const auto &element: input) {
            max_min_heap.push(element);
            EXPECT_TRUE(max_min_heap.is_heap());
        }
        EXPECT_EQ(max_min_heap.min(), output.front());
        EXPECT_EQ(max_min_heap.max(), output.back());
    }
}

TEST_F(SetupMaxMinHeap, fixedsample) {
    std::vector<double> input
            {69, 320, 232, 537, 117, 959, 451, 723, 550, 761, 527, 748, 493, 492, 285, 317, 558, 757, 280, 609, 480,
             462,
             358, 175, 685, 404, 179, 656, 953, 591, 830, 814, 408, 188, 991, 350, 165, 158, 448, 779, 959, 273, 536,
             233,
             957, 786, 411, 976, 177, 342, 687, 138, 8, 681, 743, 132, 444, 205, 519, 48, 785, 293, 947, 983, 176, 593,
             337,
             365, 343, 911, 114, 880, 257, 46, 568, 38, 301, 781, 203, 337, 6, 778, 131, 373, 95, 579, 991, 464, 1, 852,
             978, 972, 458, 984, 982, 448, 268, 604, 256, 909};
    std::vector<double> output
            {1, 6, 8, 38, 46, 48, 69, 95, 114, 117, 131, 132, 138, 158, 165, 175, 176, 177, 179, 188, 203, 205, 232,
             233,
             256, 257, 268, 273, 280, 285, 293, 301, 317, 320, 337, 337, 342, 343, 350, 358, 365, 373, 404, 408, 411,
             444,
             448, 448, 451, 458, 462, 464, 480, 492, 493, 519, 527, 536, 537, 550, 558, 568, 579, 591, 593, 604, 609,
             656,
             681, 685, 687, 723, 743, 748, 757, 761, 778, 779, 781, 785, 786, 814, 830, 852, 880, 909, 911, 947, 953,
             957,
             959, 959, 972, 976, 978, 982, 983, 984, 991, 991};
    auto max_min_heap = MaxMinHeap<double>();
    for (const auto &element: input) {
        max_min_heap.push(element);
        EXPECT_TRUE(max_min_heap.is_heap());
    }
    for (int i{}; i < 20; ++i) {
        EXPECT_EQ(max_min_heap.min(), output[i]);
        EXPECT_TRUE(max_min_heap.is_heap());
        max_min_heap.pop_min();
    }

}

TEST_F(SetupMaxMinHeap, TestPopMinSmallSequence) {
    for (int count{}; count < 100; ++count) {
        constexpr int number_of_elements{100};
        auto [input, output] = get_random_n_numbers<double>(number_of_elements);
        auto max_min_heap = MaxMinHeap<double>();
        for (const auto &element: input) {
            max_min_heap.push(element);
            EXPECT_TRUE(max_min_heap.is_heap());
        }
        for (int i{}; i < number_of_elements / 5; ++i) {

            EXPECT_EQ(max_min_heap.min(), output[i]);
            max_min_heap.pop_min();
        }
    }
}

TEST_F(SetupMaxMinHeap, TestPopMaxSmallSequence) {
    for (int count{}; count < 100; ++count) {
        constexpr int number_of_elements{100};
        auto [input, output] = get_random_n_numbers<double>(number_of_elements);
        auto max_min_heap = MaxMinHeap<double>();
        for (const auto &element: input) {
            max_min_heap.push(element);
            EXPECT_TRUE(max_min_heap.is_heap());
        }
        for (int i{}; i < number_of_elements / 5; ++i) {
            EXPECT_EQ(max_min_heap.max(), output[number_of_elements - 1 - i]);
            EXPECT_TRUE(max_min_heap.is_heap());
            max_min_heap.pop_max();
        }
    }
}

TEST_F(SetupMaxMinHeap, TestPopMinAndPopMaxThrowsWhenHeapEmpty) {
    auto max_min_heap = MaxMinHeap<int>();
    EXPECT_THROW(max_min_heap.pop_min(), std::underflow_error);
    EXPECT_THROW(max_min_heap.pop_max(), std::underflow_error);
}


TEST_F(SetupMaxMinHeap, TestPopMaxMinSmallSequence) {
    for (int count{}; count < 100; ++count) {
        constexpr int number_of_elements{100};
        auto [input, output] = get_random_n_numbers<int16_t>(number_of_elements);
        auto max_min_heap = MaxMinHeap<int16_t>();
        for (const auto &element: input) {
            max_min_heap.push(element);
            EXPECT_TRUE(max_min_heap.is_heap());
        }
        for (int i{}; i < number_of_elements / 5; ++i) {
            EXPECT_EQ(max_min_heap.max(), output[number_of_elements - 1 - i]);
            EXPECT_EQ(max_min_heap.min(), output[i]);
            max_min_heap.pop_max();
            EXPECT_TRUE(max_min_heap.is_heap());
            max_min_heap.pop_min();
            EXPECT_TRUE(max_min_heap.is_heap());
        }
    }
}

TEST_F(SetupMaxMinHeap, TestInsertPopMaxMinSmallSequence) {

    for (int count{}; count < 10; count++) {
        std::vector<int> input{3, 2, 34, 5, 13, 8, 21, 1};
        std::vector<int> output(input.begin(), input.end());
        std::vector<int> insertion{7, 12, 19, 17, 30, 32, 14, 16, 33, 4, 9, 11, 51, -1, 0, 27, 27, 27, 28, 28, 28, 28,
                                   0, -1, 102, 102, 102};
        std::random_shuffle(insertion.begin(), insertion.end());
        auto max_min_heap = MaxMinHeap<int>();
        constexpr int number_of_bi_insertions{10};
        for (const auto &element: input) {
            max_min_heap.push(element);
            EXPECT_TRUE(max_min_heap.is_heap());
        }
        for (int i{}; i < number_of_bi_insertions; ++i) {
            std::sort(output.begin(), output.end());
            EXPECT_EQ(max_min_heap.max(), output.back());
            EXPECT_EQ(max_min_heap.min(), output.front());
            output.pop_back();
            output.erase(output.begin());
            max_min_heap.pop_max();
            EXPECT_TRUE(max_min_heap.is_heap());
            max_min_heap.pop_min();
            EXPECT_TRUE(max_min_heap.is_heap());
            max_min_heap.push(insertion[i]);
            EXPECT_TRUE(max_min_heap.is_heap());
            max_min_heap.push(insertion[2 * number_of_bi_insertions - 1 - i]);
            EXPECT_TRUE(max_min_heap.is_heap());
            output.push_back(insertion[i]);
            output.push_back(insertion[2 * number_of_bi_insertions - 1 - i]);
        }
    }
}
