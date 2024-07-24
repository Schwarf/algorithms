//
// Created by andreas on 11.02.24.
//
//
// Created by andreas on 30.01.24.
//
#include <random>
#include "gtest/gtest.h"
#include "./../interval_map2.h"

TEST(Testinterval_map, simple1) {
    constexpr int start{1};
    constexpr int end{4};
    constexpr float value{1.f};
    constexpr float val_begin{0.f};
    auto map = interval_map<int, float>(val_begin);
    map.assign(start, end, value);
    EXPECT_EQ(map[2], value);
    EXPECT_EQ(map[0], int{});
    EXPECT_EQ(map[1000], int{});
}


TEST(Testinterval_map, simple2) {
    const std::vector<int> start{1, 3, 6, 9, 18};
    const std::vector<int> end{2, 4, 7, 15, 21};
    const std::vector<double> value{1., 2., 3., 4., 5.};
    constexpr double val_begin{0.0};
    auto map = interval_map<int, double>(val_begin);
    for (int i{}; i < start.size(); ++i)
        map.assign(start[i], end[i], value[i]);
    EXPECT_EQ(map[2], int{});
    EXPECT_EQ(map[10], value[3]);
    EXPECT_EQ(map[20], value[4]);
}


TEST(Testinterval_map, internalOverlap1) {
    const std::vector<int> starts{1, 6, 10, 15};
    const std::vector<int> ends{5, 10, 15, 1000};
    const std::vector<char> values{'a', 'b', 'c', 'd'};
    constexpr char val_begin{'y'};
    auto map = interval_map<int, char>(val_begin);
    for (int i{}; i < starts.size(); ++i)
        map.assign(starts[i], ends[i], values[i]);
    EXPECT_EQ(map[2], values[0]);
    EXPECT_EQ(map[3], values[0]);
    EXPECT_EQ(map[4], values[0]);
    EXPECT_EQ(map[5], val_begin);
    EXPECT_EQ(map[6], values[1]);

    constexpr int start{3};
    constexpr int end{4};
    constexpr char value{'x'};
    map.assign(start, end, value);
    EXPECT_EQ(map[2], values[0]);
    EXPECT_EQ(map[3], value);
    EXPECT_EQ(map[4], values[0]);
    EXPECT_EQ(map[5], val_begin);
    EXPECT_EQ(map[6], values[1]);
}

TEST(Testinterval_map, internalOverlap2) {
    const std::vector<int> starts{1};
    const std::vector<int> ends{5};
    const std::vector<char> values{'a'};
    constexpr char val_begin{'y'};
    auto map = interval_map<int, char>(val_begin);
    for (int i{}; i < starts.size(); ++i)
        map.assign(starts[i], ends[i], values[i]);
    EXPECT_EQ(map[-1], val_begin);
    EXPECT_EQ(map[1], values[0]);
    EXPECT_EQ(map[3], values[0]);
    EXPECT_EQ(map[4], values[0]);
    EXPECT_EQ(map[5], val_begin);

}


TEST(Testinterval_map, internalOverlapEndEqual) {
    const std::vector<int> starts{1, 5, 10, 15};
    const std::vector<int> ends{5, 10, 15, 1000};
    const std::vector<char> values{'a', 'b', 'c', 'd'};
    constexpr char val_begin{'y'};
    auto map = interval_map<int, char>(val_begin);
    for (int i{}; i < starts.size() - 1; ++i)
        map.assign(starts[i], ends[i], values[i]);
    constexpr int start{3};
    constexpr int end{5};
    constexpr char value{'x'};
    map.assign(start, end, value);
    EXPECT_EQ(map[3], value);
    EXPECT_EQ(map[4], value);
    EXPECT_EQ(map[5], values[1]);
    EXPECT_EQ(map[6], values[1]);
}


TEST(Testinterval_map, nooverlap) {
    const std::vector<int> starts{1, 5, 10, 15};
    const std::vector<int> ends{5, 10, 15, 1000};
    const std::vector<char> values{'a', 'b', 'c', 'd'};
    constexpr char val_begin{'y'};
    auto map = interval_map<int, char>(val_begin);
    for (int i{}; i < starts.size() - 1; ++i)
        map.assign(starts[i], ends[i], values[i]);
    constexpr int start{3};
    constexpr int end{4};
    constexpr char value{'x'};
    map.assign(start, end, value);
    EXPECT_EQ(map[3], value);
    EXPECT_EQ(map[4], values[0]);
    EXPECT_EQ(map[5], values[1]);
    EXPECT_EQ(map[6], values[1]);
}


TEST(Testinterval_map, overlap1) {
    const std::vector<int> start{1, 3, 9};
    const std::vector<int> end{10, 7, 12};
    const std::vector<double> value{1., 2., 3.};
    constexpr double val_begin{0.0};
    auto map = interval_map<int, double>(val_begin);
    for (int i{}; i < start.size() - 1; ++i)
        map.assign(start[i], end[i], value[i]);
    map.assign(start[2], end[2], value[2]);
    EXPECT_EQ(map[2], value[0]);
    EXPECT_EQ(map[6], value[1]);
    EXPECT_EQ(map[11], value[2]);
    EXPECT_EQ(map[8], value[0]);
}


TEST(Testinterval_map, overlap2) {
    const std::vector<int> start{1, 3, 5, 7, 3};
    const std::vector<int> end{3, 5, 7, 10, 8};
    const std::vector<double> value{1., 2., 3., 4., 10.};
    constexpr double val_begin{0.0};
    auto map = interval_map<int, double>(val_begin);
    for (int i{}; i < start.size(); ++i)
        map.assign(start[i], end[i], value[i]);
    EXPECT_EQ(map[2], value[0]);
    EXPECT_EQ(map[4], value[4]);
    EXPECT_EQ(map[8], value[3]);
    EXPECT_EQ(map[9], value[3]);
}

TEST(Testinterval_map, overwriteExistingIntervals1) {
    const std::vector<int> starts{0, 5, 10, 15};
    const std::vector<int> ends{5, 10, 15, 1000};
    const std::vector<char> values{'a', 'b', 'c', 'd'};
    constexpr char val_begin{'y'};
    auto map = interval_map<int, char>(val_begin);
    for (int i{}; i < starts.size(); ++i)
        map.assign(starts[i], ends[i], values[i]);

    EXPECT_EQ(map[1], values[0]);
    EXPECT_EQ(map[7], values[1]);
    EXPECT_EQ(map[11], values[2]);
    EXPECT_EQ(map[20], values[3]);
    constexpr int start{0};
    constexpr int end{5};
    constexpr char value{'x'};
    map.assign(start, end, value);
    EXPECT_EQ(map[1], value);
    EXPECT_EQ(map[7], values[1]);
    EXPECT_EQ(map[11], values[2]);
    EXPECT_EQ(map[20], values[3]);

}

TEST(Testinterval_map, overwriteExistingIntervals2) {
    const std::vector<int> starts{0, 5, 10, 15};
    const std::vector<int> ends{5, 10, 15, 1000};
    const std::vector<char> values{'a', 'b', 'c', 'd'};
    constexpr char val_begin{'y'};
    auto map = interval_map<int, char>(val_begin);
    for (int i{}; i < starts.size(); ++i)
        map.assign(starts[i], ends[i], values[i]);

    EXPECT_EQ(map[1], values[0]);
    EXPECT_EQ(map[7], values[1]);
    EXPECT_EQ(map[11], values[2]);
    EXPECT_EQ(map[20], values[3]);
    constexpr int start{5};
    constexpr int end{10};
    constexpr char value{'x'};
    map.assign(start, end, value);
    EXPECT_EQ(map[1], values[0]);
    EXPECT_EQ(map[7], value);
    EXPECT_EQ(map[11], values[2]);
    EXPECT_EQ(map[20], values[3]);

}

TEST(Testinterval_map, overwriteExistingIntervals3) {
    const std::vector<int> starts{0, 5, 10, 15};
    const std::vector<int> ends{5, 10, 15, 1000};
    const std::vector<char> values{'a', 'b', 'c', 'd'};
    constexpr char val_begin{'y'};
    auto map = interval_map<int, char>(val_begin);
    for (int i{}; i < starts.size(); ++i)
        map.assign(starts[i], ends[i], values[i]);

    EXPECT_EQ(map[1], values[0]);
    EXPECT_EQ(map[7], values[1]);
    EXPECT_EQ(map[11], values[2]);
    EXPECT_EQ(map[20], values[3]);
    constexpr int start{0};
    constexpr int end{10};
    constexpr char value{'x'};
    map.assign(start, end, value);
    EXPECT_EQ(map[1], value);
    EXPECT_EQ(map[7], value);
    EXPECT_EQ(map[11], values[2]);
    EXPECT_EQ(map[20], values[3]);

}

TEST(Testinterval_map, overwriteExistingIntervals4) {
    const std::vector<int> starts{0, 5, 10, 15};
    const std::vector<int> ends{5, 10, 15, 1000};
    const std::vector<char> values{'a', 'b', 'c', 'd'};
    constexpr char val_begin{'y'};
    auto map = interval_map<int, char>(val_begin);
    for (int i{}; i < starts.size(); ++i)
        map.assign(starts[i], ends[i], values[i]);

    EXPECT_EQ(map[1], values[0]);
    EXPECT_EQ(map[7], values[1]);
    EXPECT_EQ(map[11], values[2]);
    EXPECT_EQ(map[20], values[3]);
    constexpr int start{0};
    constexpr int end{15};
    constexpr char value{'x'};
    map.assign(start, end, value);
    EXPECT_EQ(map[1], value);
    EXPECT_EQ(map[7], value);
    EXPECT_EQ(map[11], value);
    EXPECT_EQ(map[20], values[3]);

}

TEST(Testinterval_map, overwriteExistingIntervals5) {
    const std::vector<int> starts{0, 5, 10, 15};
    const std::vector<int> ends{5, 10, 15, 1000};
    const std::vector<char> values{'a', 'b', 'c', 'd'};
    constexpr char val_begin{'y'};
    auto map = interval_map<int, char>(val_begin);
    for (int i{}; i < starts.size(); ++i)
        map.assign(starts[i], ends[i], values[i]);

    EXPECT_EQ(map[1], values[0]);
    EXPECT_EQ(map[7], values[1]);
    EXPECT_EQ(map[11], values[2]);
    EXPECT_EQ(map[20], values[3]);
    constexpr int start{0};
    constexpr int end{1000};
    constexpr char value{'x'};
    map.assign(start, end, value);
    EXPECT_EQ(map[1], value);
    EXPECT_EQ(map[7], value);
    EXPECT_EQ(map[11], value);
    EXPECT_EQ(map[20], value);

}


TEST(Testinterval_map, beginIsIn1) {
    const std::vector<int> starts{0, 5, 10, 15};
    const std::vector<int> ends{5, 10, 15, 1000};
    const std::vector<char> values{'a', 'b', 'c', 'd'};
    constexpr char val_begin{'y'};
    auto map = interval_map<int, char>(val_begin);
    for (int i{}; i < starts.size(); ++i)
        map.assign(starts[i], ends[i], values[i]);

    EXPECT_EQ(map[1], values[0]);
    EXPECT_EQ(map[7], values[1]);
    EXPECT_EQ(map[11], values[2]);
    EXPECT_EQ(map[20], values[3]);
    constexpr int start{5};
    constexpr int end{8};
    constexpr char value{'x'};
    map.assign(start, end, value);
    EXPECT_EQ(map[1], values[0]);
    EXPECT_EQ(map[5], value);
    EXPECT_EQ(map[7], value);
    EXPECT_EQ(map[8], values[1]);
    EXPECT_EQ(map[9], values[1]);
    EXPECT_EQ(map[11], values[2]);
    EXPECT_EQ(map[20], values[3]);

}


TEST(Testinterval_map, beginIsIn2) {
    const std::vector<int> starts{0, 5, 10, 15};
    const std::vector<int> ends{5, 10, 15, 1000};
    const std::vector<char> values{'a', 'b', 'c', 'd'};
    constexpr char val_begin{'y'};
    auto map = interval_map<int, char>(val_begin);
    for (int i{}; i < starts.size(); ++i)
        map.assign(starts[i], ends[i], values[i]);

    EXPECT_EQ(map[1], values[0]);
    EXPECT_EQ(map[7], values[1]);
    EXPECT_EQ(map[11], values[2]);
    EXPECT_EQ(map[20], values[3]);
    constexpr int start{5};
    constexpr int end{12};
    constexpr char value{'x'};
    map.assign(start, end, value);
    EXPECT_EQ(map[1], values[0]);
    EXPECT_EQ(map[5], value);
    EXPECT_EQ(map[7], value);
    EXPECT_EQ(map[8], value);
    EXPECT_EQ(map[9], value);
    EXPECT_EQ(map[11], value);
    EXPECT_EQ(map[12], values[2]);
    EXPECT_EQ(map[20], values[3]);

}

TEST(Testinterval_map, beginIsIn3) {
    const std::vector<int> starts{0, 5, 10, 15};
    const std::vector<int> ends{5, 10, 15, 1000};
    const std::vector<char> values{'a', 'b', 'c', 'd'};
    constexpr char val_begin{'y'};
    auto map = interval_map<int, char>(val_begin);
    for (int i{}; i < starts.size(); ++i)
        map.assign(starts[i], ends[i], values[i]);

    EXPECT_EQ(map[1], values[0]);
    EXPECT_EQ(map[7], values[1]);
    EXPECT_EQ(map[11], values[2]);
    EXPECT_EQ(map[20], values[3]);
    constexpr int start{0};
    constexpr int end{14};
    constexpr char value{'x'};
    map.assign(start, end, value);
    EXPECT_EQ(map[0], value);
    EXPECT_EQ(map[1], value);
    EXPECT_EQ(map[5], value);
    EXPECT_EQ(map[7], value);
    EXPECT_EQ(map[8], value);
    EXPECT_EQ(map[9], value);
    EXPECT_EQ(map[11], value);
    EXPECT_EQ(map[12], value);
    EXPECT_EQ(map[20], values[3]);

}


TEST(Testinterval_map, endIsIn1) {
    const std::vector<int> starts{0, 5, 10, 15};
    const std::vector<int> ends{5, 10, 15, 1000};
    const std::vector<char> values{'a', 'b', 'c', 'd'};
    constexpr char val_begin{'y'};
    auto map = interval_map<int, char>(val_begin);
    for (int i{}; i < starts.size(); ++i)
        map.assign(starts[i], ends[i], values[i]);

    EXPECT_EQ(map[1], values[0]);
    EXPECT_EQ(map[7], values[1]);
    EXPECT_EQ(map[11], values[2]);
    EXPECT_EQ(map[20], values[3]);
    constexpr int start{2};
    constexpr int end{5};
    constexpr char value{'x'};
    map.assign(start, end, value);
    EXPECT_EQ(map[0], values[0]);
    EXPECT_EQ(map[1], values[0]);
    EXPECT_EQ(map[2], value);
    EXPECT_EQ(map[3], value);
    EXPECT_EQ(map[5], values[1]);
    EXPECT_EQ(map[9], values[1]);
    EXPECT_EQ(map[11], values[2]);
    EXPECT_EQ(map[12], values[2]);
    EXPECT_EQ(map[20], values[3]);

}


TEST(Testinterval_map, endIsIn2) {
    const std::vector<int> starts{0, 5, 10, 15};
    const std::vector<int> ends{5, 10, 15, 1000};
    const std::vector<char> values{'a', 'b', 'c', 'd'};
    constexpr char val_begin{'y'};
    auto map = interval_map<int, char>(val_begin);
    for (int i{}; i < starts.size(); ++i)
        map.assign(starts[i], ends[i], values[i]);

    EXPECT_EQ(map[1], values[0]);
    EXPECT_EQ(map[7], values[1]);
    EXPECT_EQ(map[11], values[2]);
    EXPECT_EQ(map[20], values[3]);
    constexpr int start{2};
    constexpr int end{15};
    constexpr char value{'x'};
    map.assign(start, end, value);
    EXPECT_EQ(map[0], values[0]);
    EXPECT_EQ(map[1], values[0]);
    EXPECT_EQ(map[2], value);
    EXPECT_EQ(map[3], value);
    EXPECT_EQ(map[5], value);
    EXPECT_EQ(map[9], value);
    EXPECT_EQ(map[11], value);
    EXPECT_EQ(map[12], value);
    EXPECT_EQ(map[20], values[3]);
}


TEST(Testinterval_map, fallback) {
    const std::vector<int> starts{0, 7};
    const std::vector<int> ends{5, 10};
    const std::vector<char> values{'a', 'b'};
    constexpr char val_begin{'y'};
    auto map = interval_map<int, char>(val_begin);
    for (int i{}; i < starts.size(); ++i)
        map.assign(starts[i], ends[i], values[i]);

    EXPECT_EQ(map[6], val_begin);
    EXPECT_EQ(map[7], values[1]);
    EXPECT_EQ(map[11], val_begin);
}


TEST(Testinterval_map, merging1) {
    const std::vector<int> starts{0, 7, 11};
    const std::vector<int> ends{5, 10, 13};
    const std::vector<char> values{'a', 'b', 'c'};
    constexpr char val_begin{'y'};
    auto map = interval_map<int, char>(val_begin);
    for (int i{}; i < starts.size(); ++i)
        map.assign(starts[i], ends[i], values[i]);

    EXPECT_EQ(map[6], val_begin);
    EXPECT_EQ(map[7], values[1]);
    EXPECT_EQ(map[11], values[2]);
    constexpr int start{7};
    constexpr int end{13};
    constexpr char value{'b'};
    map.assign(start, end, value);
    EXPECT_EQ(map[12], values[1]);
}

TEST(Testinterval_map, floatsimple1) {
    constexpr float start{1.f};
    constexpr float end{4.f};
    constexpr float value{1.f};
    constexpr float val_begin{0.f};
    auto map = interval_map<int, float>(val_begin);
    map.assign(start, end, value);
    EXPECT_FLOAT_EQ(map[2], value);
    EXPECT_FLOAT_EQ(map[0], float{});
    EXPECT_FLOAT_EQ(map[1000], float{});
}


TEST(Testinterval_map, floatNooverlap) {
    const std::vector<double> starts{1.0, 5.0000000000000002, 10, 15};
    const std::vector<double> ends{5.0, 10., 15, 1000};
    const std::vector<char> values{'a', 'b', 'c', 'd'};
    constexpr char val_begin{'y'};
    auto map = interval_map<double, char>(val_begin);
    for (int i{}; i < starts.size() - 1; ++i)
        map.assign(starts[i], ends[i], values[i]);
    constexpr int start{3};
    constexpr int end{4};
    constexpr char value{'x'};
    map.assign(start, end, value);
    EXPECT_EQ(map[3], value);
    EXPECT_EQ(map[4], values[0]);
    EXPECT_EQ(map[5], values[1]);
    EXPECT_EQ(map[6], values[1]);
}


TEST(Testinterval_map, mergingValues) {
    const std::vector<int> starts{1, 5, 10, 15};
    const std::vector<int> ends{5, 10, 15, 1000};
    const std::vector<char> values{'a', 'b', 'a', 'd'};
    constexpr char val_begin{'y'};
    auto map = interval_map<double, char>(val_begin);
    for (int i{}; i < starts.size() - 1; ++i)
        map.assign(starts[i], ends[i], values[i]);
    EXPECT_EQ(map[0], val_begin);
    EXPECT_EQ(map[1], values[0]);
    EXPECT_EQ(map[5], values[1]);
    EXPECT_EQ(map[10], values[0]);
    constexpr int start{2};
    constexpr int end{12};
    constexpr char value{'a'};
    map.assign(start, end, value);
    EXPECT_EQ(map[0], val_begin);
    EXPECT_EQ(map[1], values[0]);
    EXPECT_EQ(map[5], values[0]);
    EXPECT_EQ(map[10], values[0]);
    EXPECT_EQ(map[11], values[0]);

}


int randomInt(int min, int max) {
    static std::mt19937 generator(std::random_device{}());
    std::uniform_int_distribution<int> distribution(min, max);
    return distribution(generator);
}

struct KeyTypeStruct {
    int key;

    // Constructor for ease of use
    KeyTypeStruct() = delete;

    explicit KeyTypeStruct(int k) : key(k) {}

    // Copy constructor and assignment operator are implicitly defined

    // Less-than comparison operator
    bool operator<(const KeyTypeStruct &other) const {
        return key < other.key;
    }
};


struct ValueTypeStruct {
    char value;

    // Constructor for ease of use
    ValueTypeStruct() = delete;

    explicit ValueTypeStruct(char v) : value(v) {}

    // Copy constructor and assignment operator are implicitly defined

    // Less-than comparison operator
    bool operator==(const ValueTypeStruct &other) const {
        return value == other.value;
    }
};


TEST(Testinterval_map, randomTest1_check_adjacent_values) {
    interval_map<int, char> intervalMap(-128); // Assuming 'A' is the default value
    for (int i = 0; i < 250; ++i) { // Number of insertions
        int start = randomInt(1, 1000);
        int end = randomInt(start, 1000); // Ensure end is >= start
        char value = -128 + randomInt(0, 250); // Random char from 'A' to 'Z'
        intervalMap.assign(start, end, value);
    }

    // Make sure no adjacent intervals have the same value
    int previousKey{};
    char previousValue{};
    std::cout << intervalMap.m_map.size() << std::endl;
    for (const auto &[key, value]: intervalMap.m_map) {
        if (previousKey == 0) {
            previousKey = key;
            previousValue = value;
            continue;
        }
        EXPECT_NE(previousValue, value);
        EXPECT_NE(previousKey, key);
        previousValue = value;
        previousKey = key;
    }
}


TEST(Testinterval_map, randomTest1_check_adjacent_values_struct) {
    interval_map<KeyTypeStruct, ValueTypeStruct> intervalMap(ValueTypeStruct{'A'}); // Assuming 'A' is the default value
    for (int i = 0; i < 250; ++i) { // Number of insertions
        const auto start = KeyTypeStruct(randomInt(1, 1000));
        const auto end = KeyTypeStruct(randomInt(start.key, 1000)); // Ensure end is >= start
        const auto value = ValueTypeStruct(static_cast<char>(randomInt(-100, 100))); // Random char from 'A' to 'Z'
        intervalMap.assign(start, end, value);
    }

    // Make sure no adjacent intervals have the same value
    int previousKey{};
    char previousValue{};
    std::cout << intervalMap.m_map.size() << std::endl;
    for (const auto &[key, value]: intervalMap.m_map) {
        if (previousKey == 0) {
            previousKey = key.key;
            previousValue = value.value;
            continue;
        }
        EXPECT_NE(previousValue, value.value);
        EXPECT_NE(previousKey, key.key);
        previousValue = value.value;
        previousKey = key.key;
    }
}
