//
// Created by andreas on 08.03.23.
//

#ifndef MINIMUM_TIME_TO_SCHEDULE_N_BUS_TRIPS_H
#define MINIMUM_TIME_TO_SCHEDULE_N_BUS_TRIPS_H
#include <concepts>
#include <ranges>
#include <algorithm>

template <typename Container>
concept IndexedContainerWithUnsignedIntegralElements = requires(Container c)
{
	{ c[0] } -> std::same_as<typename Container::value_type&>;
	{ c.size() } -> std::integral;
	requires std::unsigned_integral<typename Container::value_type>;
};

template <typename T>
concept UnsignedInteger64Bit = std::is_unsigned_v<T> && (sizeof(T) * 8 >= 64);


template <typename Container, typename ReturnType>
requires IndexedContainerWithUnsignedIntegralElements<Container> && UnsignedInteger64Bit<ReturnType>
ReturnType minimum_time_to_schedule_n_bus_trips(const Container & bus_times, int total_trips)
{
	ReturnType left{1};
	auto right = static_cast<ReturnType>(*std::ranges::max_element(bus_times));
	while(left <= right)
	{
		ReturnType trips{};
		ReturnType mid = (left + right)/2;
		for(const auto & bus_time : bus_times)
			trips += mid/bus_time;
		if(trips < total_trips)
			left = mid +1;
		else
			right = mid -1;
	}
	return left;
}


#endif //MINIMUM_TIME_TO_SCHEDULE_N_BUS_TRIPS_H
