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

template <typename InputType>
class PerformanceMeasurement
{
public:
	PerformanceMeasurement() = default;
	template<IndexedContainer Container, typename SortFunction>
	auto measure_sort_performance(SortFunction sort_function, const Container &container, size_t number_of_measurements)
	{
		std::int64_t total_duration{};
		for(int i{}; i < number_of_measurements; ++i)
		{
			IndexedContainer auto input_copy = container;
			auto start_time = std::chrono::high_resolution_clock::now();
			sort_function(input_copy);
			auto end_time = std::chrono::high_resolution_clock::now();
			total_duration += std::chrono::duration_cast<std::chrono::microseconds>(end_time- start_time).count();
		}
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

	std::tuple<size_t, double, double> create_results()
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
		double average = static_cast<double>(std::accumulate(measurements.begin(), measurements.end(), 0))/ static_cast<double>(measurements.size());

		return std::make_tuple<size_t, double, double>(measurements.size(), median, average);
	}

	void reset()
	{
		min_heap = std::priority_queue<InputType, std::vector<InputType>, std::less<>>();
		max_heap = std::priority_queue<InputType, std::vector<InputType>, std::greater<>>();
		measurements.clear();
	}

	std::priority_queue<InputType, std::vector<InputType>, std::less<>> max_heap;
	std::priority_queue<InputType, std::vector<InputType>, std::greater<>> min_heap;
	std::vector<InputType> measurements;
};

#endif //PERFORMANCE_MEASUREMENT_H

