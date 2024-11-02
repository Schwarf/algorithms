//
// Created by andreas on 02.11.24.
//
#include <benchmark/benchmark.h>
#include <vector>
#include <algorithm>
#include <functional>
#include <random>

template <typename T>
requires std::is_arithmetic_v<T>
static void generic_sorting_benchmark(benchmark::State& state, const std::function<void(std::vector<T>&)>& sort_func) {
    std::vector<T> data(state.range(0));
    std::mt19937 generator(427891);
    std::generate(data.begin(), data.end(), generator);

    for (auto _ : state) {
        auto temp = data;
        benchmark::DoNotOptimize(temp);

        sort_func(temp); // Call the provided sorting function

        benchmark::ClobberMemory();
    }
}

void std_sort(std::vector<int>& v) { std::sort(v.begin(), v.end()); }
void std_stable_sort(std::vector<int>& v) { std::stable_sort(v.begin(), v.end()); }


BENCHMARK_CAPTURE(generic_sorting_benchmark<int>, std_sort, std_sort)->Arg(1000);
BENCHMARK_CAPTURE(generic_sorting_benchmark<int>, std_stable_sort, std_stable_sort)->Arg(1000);


BENCHMARK_MAIN();