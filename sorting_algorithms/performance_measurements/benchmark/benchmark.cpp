//
// Created by andreas on 02.11.24.
//
#include <benchmark/benchmark.h>
#include <vector>
#include <algorithm>
#include <functional>
#include <random>

static void generic_sorting_benchmark(benchmark::State& state, const std::function<void(std::vector<int>&)>& sort_func) {
    std::vector<int> data(state.range(0));
    std::mt19937 generator(42);
    std::generate(data.begin(), data.end(), generator);

    for (auto _ : state) {
        std::vector<int> temp = data;
        benchmark::DoNotOptimize(temp);

        sort_func(temp); // Call the provided sorting function

        benchmark::ClobberMemory();
    }
}


