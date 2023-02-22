//
// Created by andreas on 22.02.23.
//

#ifndef MINIMUM_CAR_SIZE_TO_SHIP_PACKAGES_H
#define MINIMUM_CAR_SIZE_TO_SHIP_PACKAGES_H
// We want to ship 'n' packages in the given order in 'd' number of days.
// The ith package has a weight weights[i]
// Return the least weight capacity of the car that will result in all the packages shipped within d days.
#include <vector>

template <typename T>
bool is_valid_car_size(const std::vector<T> & weights, T max_load, int max_days)
{
	int days{1};
	T current_load{};
	for(const auto & weight: weights)
	{
		current_load += weight;
		if(current_load > max_load)
		{
			days++;
			current_load = weight;
		}
	}
	return days <= max_days;
}




#endif //MINIMUM_CAR_SIZE_TO_SHIP_PACKAGES_H
