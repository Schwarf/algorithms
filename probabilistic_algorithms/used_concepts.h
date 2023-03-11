//
// Created by andreas on 11.03.23.
//

template<typename CoordinatesType>
concept RequireCoordinates = requires(const CoordinatesType &coordinates1, const CoordinatesType &coordinates2)
{
	// coordinates1 & coordinates2 shall provide the index operator and return the value_type
	{ coordinates1[0] } -> std::same_as<typename CoordinatesType::value_type const &>;
	{ coordinates2[0] } -> std::same_as<typename CoordinatesType::value_type const &>;
	// coordinates1 & coordinates2 shall provide the size method
	{ coordinates1.size() } -> std::same_as<std::size_t>;
	{ coordinates2.size() } -> std::same_as<std::size_t>;
	// The values stored in coordinates1 & coordinates2 shall be cast to double
	{ static_cast<double> (coordinates1[0]) };
	{ static_cast<double> (coordinates2[0]) };
};

template<typename ContainerType>
concept RequireIndexedContainer = requires(const ContainerType &container)
{
	{ container[0] } -> std::same_as<typename ContainerType::value_type const &>;
	{ container.size() } -> std::same_as<std::size_t>;
};
/*
template<typename FunctionType, typename ContainerType>
concept RequireDistanceFunction = requires(FunctionType function,
										   const ContainerType &container1,
										   const ContainerType &container2)
{
	requires std::same_as< typename std::invoke_result_t<FunctionType,
											   typename ContainerType::value_type,
											   typename ContainerType::value_type>, double>;
	requires RequireCoordinates<ContainerType>;

};
 */

#ifndef USED_CONCEPTS_H
#define USED_CONCEPTS_H

#endif //USED_CONCEPTS_H
