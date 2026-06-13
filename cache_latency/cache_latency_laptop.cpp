//
// Created by andreas on 13.06.26.
//
#include <algorithm>
#include <chrono>
#include <cstdint>
#include <iomanip>
#include <iostream>
#include <limits>
#include <numeric>
#include <random>
#include <stdexcept>
#include <string>
#include <vector>

namespace {

constexpr std::size_t KiB = 1024;
constexpr std::size_t MiB = 1024 * KiB;

// Written after each measurement so the compiler cannot remove the load chain.
volatile std::uint32_t sink = 0;

std::vector<std::uint32_t> makeRandomCycle(
    const std::size_t bytes,
    std::mt19937& randomGenerator)
{
    const std::size_t count =
        std::max<std::size_t>(2, bytes / sizeof(std::uint32_t));

    if (count > std::numeric_limits<std::uint32_t>::max())
        throw std::runtime_error("Working set too large for 32-bit indices");

    std::vector<std::uint32_t> order(count);
    std::iota(order.begin(), order.end(), 0U);
    std::shuffle(order.begin(), order.end(), randomGenerator);

    std::vector<std::uint32_t> next(count);

    // Construct one cycle containing every index:
    //
    // order[0] -> order[1] -> ... -> order[n - 1] -> order[0]
    for (std::size_t i = 0; i < count; ++i)
        next[order[i]] = order[(i + 1) % count];

    return next;
}

double measureNanosecondsPerAccess(
    const std::vector<std::uint32_t>& next,
    const std::size_t numberOfAccesses)
{
    std::uint32_t index = 0;

    // Touch every element once before timing.
    for (std::size_t i = 0; i < next.size(); ++i)
        index = next[index];

    const auto start = std::chrono::steady_clock::now();

    for (std::size_t i = 0; i < numberOfAccesses; ++i)
        index = next[index];

    const auto end = std::chrono::steady_clock::now();

    sink = index;

    const double elapsedNanoseconds =
        std::chrono::duration<double, std::nano>(end - start).count();

    return elapsedNanoseconds /
           static_cast<double>(numberOfAccesses);
}

std::string formatSize(const std::size_t bytes)
{
    if (bytes >= MiB)
        return std::to_string(bytes / MiB) + " MiB";

    return std::to_string(bytes / KiB) + " KiB";
}

} // namespace

int main()
{
    const std::vector<std::size_t> workingSetSizes{
        4 * KiB,
        8 * KiB,
        16 * KiB,
        24 * KiB,
        32 * KiB,
        48 * KiB,
        64 * KiB,
        128 * KiB,
        256 * KiB,
        384 * KiB,
        512 * KiB,
        768 * KiB,
        1 * MiB,
        2 * MiB,
        3 * MiB,
        4 * MiB,
        6 * MiB,
        8 * MiB,
        16 * MiB,
        32 * MiB,
        64 * MiB
    };

    constexpr std::size_t minimumAccesses = 5'000'000;
    constexpr int repetitions = 3;

    // Fixed seed makes the benchmark reproducible.
    std::mt19937 randomGenerator{123456789U};

    std::cout << std::left << std::setw(14) << "Working set"
              << std::right << std::setw(14) << "ns/access"
              << '\n';

    std::cout << std::string(28, '-') << '\n';

    for (const std::size_t bytes : workingSetSizes) {
        const auto next = makeRandomCycle(bytes, randomGenerator);

        // Large working sets get at least one complete traversal.
        const std::size_t accesses =
            std::max(minimumAccesses, next.size());

        std::vector<double> measurements;
        measurements.reserve(repetitions);

        for (int repetition = 0; repetition < repetitions; ++repetition) {
            measurements.push_back(
                measureNanosecondsPerAccess(next, accesses));
        }

        // Use the median result to reduce interference from interrupts.
        std::sort(measurements.begin(), measurements.end());
        const double median = measurements[measurements.size() / 2];

        std::cout << std::left << std::setw(14) << formatSize(bytes)
                  << std::right << std::setw(14)
                  << std::fixed << std::setprecision(2)
                  << median << '\n';
    }

    // An observable use of sink.
    return sink == std::numeric_limits<std::uint32_t>::max() ? 1 : 0;
}
