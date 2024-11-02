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
#include <iostream>

template <typename T>
requires std::is_arithmetic_v<T>
static void generic_sorting_benchmark(benchmark::State& state, const std::function<void(std::vector<T>&)>& sort_func) {
    std::vector<T> data(state.range(0));
    for (auto _ : state) {
        int seed = static_cast<int>(state.iterations()); // Using the iteration count as a seed
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


BENCHMARK_CAPTURE(generic_sorting_benchmark<int>, std_sort, std_sort<int>)->Arg(1000);
BENCHMARK_CAPTURE(generic_sorting_benchmark<int>, std_stable_sort, std_stable_sort<int>)->Arg(1000);
BENCHMARK_CAPTURE(generic_sorting_benchmark<int>, my_heap_sort, my_heap_sort<int>)->Arg(1000);
BENCHMARK_CAPTURE(generic_sorting_benchmark<int>, my_insertion_sort, my_insertion_sort<int>)->Arg(1000);
BENCHMARK_CAPTURE(generic_sorting_benchmark<int>, my_merge_sort, my_merge_sort<int>)->Arg(1000);
BENCHMARK_CAPTURE(generic_sorting_benchmark<int>, my_quick_sort, my_quick_sort<int>)->Arg(1000);



BENCHMARK_CAPTURE(generic_sorting_benchmark<int>, std_sort, std_sort<int>)->Arg(10000);
BENCHMARK_CAPTURE(generic_sorting_benchmark<int>, std_stable_sort, std_stable_sort<int>)->Arg(10000);
BENCHMARK_CAPTURE(generic_sorting_benchmark<int>, my_heap_sort, my_heap_sort<int>)->Arg(10000);
BENCHMARK_CAPTURE(generic_sorting_benchmark<int>, my_insertion_sort, my_insertion_sort<int>)->Arg(10000);
BENCHMARK_CAPTURE(generic_sorting_benchmark<int>, my_merge_sort, my_merge_sort<int>)->Arg(10000);
BENCHMARK_CAPTURE(generic_sorting_benchmark<int>, my_quick_sort, my_quick_sort<int>)->Arg(10000);

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