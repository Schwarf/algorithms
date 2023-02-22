//
// Created by andreas on 22.02.23.
//

#ifndef MINIMUM_CAR_SIZE_TO_SHIP_PACKAGES_H
#define MINIMUM_CAR_SIZE_TO_SHIP_PACKAGES_H
// We want to ship 'n' packages in the given order in 'd' number of days.
// The ith package has a weight weights[i]
// Return the least weight capacity of the car that will result in all the packages shipped within d days.
#include <vector>
#include <algorithm>

template<typename T>
bool is_valid_car_size(const std::vector<T> &weights, T max_load, int max_days)
{
	int days{1};
	T current_load{};
	for (const auto &weight: weights) {
		current_load += weight;
		if (current_load > max_load) {
			days++;
			current_load = weight;
		}
	}
	return days <= max_days;
}

template<typename T>
T get_car_size_to_ship_in_days(const std::vector<T> &weights, int days)
{
	T max_weight{}, total_weight{};
	for (const auto &weight: weights) {
		max_weight = std::max(max_weight, weight);
		total_weight += weight;
	}

	T left{max_weight}, right{total_weight};
	while (left < right) {
		auto mid = (left + right) / T{2};
		if (is_valid_car_size(weights, mid, days))
			right = mid;
		else
			left += T{1};
	}
	return left;

}


#endif //MINIMUM_CAR_SIZE_TO_SHIP_PACKAGES_H
