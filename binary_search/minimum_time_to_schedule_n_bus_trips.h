//
// Created by andreas on 08.03.23.
//

#ifndef MINIMUM_TIME_TO_SCHEDULE_N_BUS_TRIPS_H
#define MINIMUM_TIME_TO_SCHEDULE_N_BUS_TRIPS_H
#include <concepts>

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
ReturnType minimum_time_to_schedule_n_bus_trips()
{

}


#endif //MINIMUM_TIME_TO_SCHEDULE_N_BUS_TRIPS_H
