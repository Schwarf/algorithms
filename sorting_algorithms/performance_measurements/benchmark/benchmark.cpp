//
// Created by andreas on 02.11.24.
//
#include <benchmark/benchmark.h>
#include <vector>
#include <algorithm>
#include <functional>
#include <random>
#include "./../../heap_sort.h"
#include "./../../insertion_sort.h"
#include "./../../merge_sort.h"
#include "./../../quick_sort.h"
#include "./../../optimized_sort.h"
#include <iostream>

template <typename T>
requires std::is_arithmetic_v<T>
static void generic_sorting_benchmark(benchmark::State& state, const std::function<void(std::vector<T>&)>& sort_func) {
    std::vector<T> data(state.range(0));
    for (auto _ : state) {
        int seed = static_cast<int>(state.range(0)) * static_cast<int>(state.iterations());
        std::mt19937 generator(seed);

        // Fill the vector with new random data each time
        std::generate(data.begin(), data.end(), generator);
        auto temp = data;
        benchmark::DoNotOptimize(temp);

        sort_func(temp); // Call the provided sorting function

        benchmark::ClobberMemory();
    }
}

template <typename T>
requires std::is_arithmetic_v<T>
void std_sort(std::vector<T>& v) { std::sort(v.begin(), v.end()); }

template <typename T>
requires std::is_arithmetic_v<T>
void std_stable_sort(std::vector<T>& v) { std::stable_sort(v.begin(), v.end()); }


template <typename T>
requires std::is_arithmetic_v<T>
void my_heap_sort(std::vector<T>& v) { heap_sort(v); }


template <typename T>
requires std::is_arithmetic_v<T>
void my_insertion_sort(std::vector<T>& v) { insertion_sort(v); }

template <typename T>
requires std::is_arithmetic_v<T>
void my_merge_sort(std::vector<T>& v) { merge_sort(v); }

template <typename T>
requires std::is_arithmetic_v<T>
void my_quick_sort(std::vector<T>& v) { quick_sort(v); }

template <typename T>
requires std::is_arithmetic_v<T>
void my_optimized_sort(std::vector<T>& v) { optimized_sort(v, std::less()); }

// --------------------
// Wrappers for int
// --------------------
static void BM_std_sort(benchmark::State& s)        { generic_sorting_benchmark<int>(s, std_sort<int>); }
static void BM_std_stable_sort(benchmark::State& s) { generic_sorting_benchmark<int>(s, std_stable_sort<int>); }
static void BM_heap_sort(benchmark::State& s)       { generic_sorting_benchmark<int>(s, my_heap_sort<int>); }
// static void BM_insertion_sort(benchmark::State& s)  { generic_sorting_benchmark<int>(s, my_insertion_sort<int>); }
// static void BM_merge_sort(benchmark::State& s)      { generic_sorting_benchmark<int>(s, my_merge_sort<int>); }
static void BM_quick_sort(benchmark::State& s)      { generic_sorting_benchmark<int>(s, my_quick_sort<int>); }
static void BM_optimized_sort(benchmark::State& s)  { generic_sorting_benchmark<int>(s, my_optimized_sort<int>); }

// Register benchmarks
BENCHMARK(BM_std_sort)        ->RangeMultiplier(10)->Range(5, 5'000'000);
BENCHMARK(BM_std_stable_sort) ->RangeMultiplier(10)->Range(5, 5'000'000);
BENCHMARK(BM_heap_sort)       ->RangeMultiplier(10)->Range(5, 5'000'000);
//BENCHMARK(BM_insertion_sort)  ->RangeMultiplier(10)->Range(5, 5'000'000);
//BENCHMARK(BM_merge_sort)      ->RangeMultiplier(10)->Range(5, 5'000'000);
BENCHMARK(BM_quick_sort)      ->RangeMultiplier(10)->Range(5, 5'000'000);
BENCHMARK(BM_optimized_sort)  ->RangeMultiplier(10)->Range(5, 5'000'000);
int main(int argc, char** argv) {
    // Compiler check
#ifdef __clang__
    std::cout << "Compiled with Clang, version: " << __clang_version__ << std::endl;
#else
    std::cout << "Not using Clang!" << std::endl;
#endif

    // Initialize and run benchmarks
    ::benchmark::Initialize(&argc, argv);
    ::benchmark::RunSpecifiedBenchmarks();
    return 0;
}