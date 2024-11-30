//
// Created by andreas on 30.11.24.
//

#include <algorithm>
#include <vector>
#include <random>
#include <chrono>
#include <iostream>
#include "./../../optimized_sort.h"

int main() {
    const size_t size = 1000000;
    std::vector<int> data(size);
    std::iota(data.begin(), data.end(), 0);

    std::shuffle(data.begin(), data.end(), std::mt19937{std::random_device{}()});

    auto start = std::chrono::high_resolution_clock::now();
    optimized_sort(data, std::less());
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << "std::sort: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << " ms\n";

    // Reset and test your Introsort
}