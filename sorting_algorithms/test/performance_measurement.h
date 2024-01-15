//
// Created by andreas on 15.01.24.
//

#ifndef PERFORMANCE_MEASUREMENT_H
#define PERFORMANCE_MEASUREMENT_H
#include <queue>
#include <chrono>
#include <numeric>
#include <tuple>
#include "used_concepts.h"
#include <cmath>

template <typename InputType>
class PerformanceMeasurement
{
public:
	PerformanceMeasurement() = default;
	template<IndexedContainer Container, typename SortFunction>
	auto measure_sort_performance_N_times(SortFunction sort_function, const Container &container, size_t number_of_measurements)
	{
		std::int64_t total_duration{};
		for(int i{}; i < number_of_measurements; ++i)
		{
			IndexedContainer auto input_copy = container;
			auto start_time = std::chrono::high_resolution_clock::now();
			sort_function(input_copy);
			auto end_time = std::chrono::high_resolution_clock::now();
			total_duration += std::chrono::duration_cast<std::chrono::microseconds>(end_time- start_time).count();
			store_measurement(total_duration);
		}
		return create_results();
	}

	void reset()
	{
		min_heap = std::priority_queue<InputType, std::vector<InputType>, std::less<>>();
		max_heap = std::priority_queue<InputType, std::vector<InputType>, std::greater<>>();
		measurements.clear();
	}

	template<IndexedContainer Container, typename SortFunction>
	void measure_sort_performance(SortFunction sort_function, Container &container)
	{
		std::int64_t total_duration{};
		auto start_time = std::chrono::high_resolution_clock::now();
		sort_function(container);
		auto end_time = std::chrono::high_resolution_clock::now();
		total_duration += std::chrono::duration_cast<std::chrono::microseconds>(end_time- start_time).count();
		store_measurement(total_duration);
	}

	auto get_results() const
	{
		return create_results();
	}


private:
	void store_measurement(const std::int64_t measurement)
	{
		if(min_heap.size() >= max_heap.size())
			max_heap.push(measurement);
		else
			min_heap.push(measurement);
		measurements.push_back(measurement);
	}

	[[nodiscard]] std::tuple<size_t, double, double, double> create_results() const
	{
		double median{};
		if(min_heap.size() == max_heap.size())
		{
			 median = static_cast<double>(min_heap.top() +max_heap.top())/2.0;
		}
		else if(min_heap.size() >= max_heap.size())
		{
			median = static_cast<double>(min_heap.top());
		}
		else
		{
			median = static_cast<double>(max_heap.top());
		}
		auto mean_std = compute_mean_and_standard_deviation(measurements);
		return std::make_tuple<size_t, double, double>(measurements.size(), median, mean_std.first, mean_std.second);
	}

	std::pair<double, double> compute_mean_and_standard_deviation(const std::vector<InputType> & data)
	{
		// Welford's algorithm
		int n{};
		double mean{};
		double sum_of_square_diff{};
		for(auto element: data)
		{
			n++;
			auto delta = static_cast<double>(element) - mean;
			mean += delta/n;
			sum_of_square_diff += delta*(element-mean);
		}
		double standard_deviation = std::sqrt(sum_of_square_diff/n);
		return {mean, standard_deviation};
	}


	std::priority_queue<InputType, std::vector<InputType>, std::less<>> max_heap;
	std::priority_queue<InputType, std::vector<InputType>, std::greater<>> min_heap;
	std::vector<InputType> measurements;
};

#endif //PERFORMANCE_MEASUREMENT_H

