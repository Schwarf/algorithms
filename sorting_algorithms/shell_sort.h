//
// Created by andreas on 17.03.23.
//

#ifndef SHELL_SORT_H
#define SHELL_SORT_H
#include <vector>
#include <algorithm>
template<typename ContainerType>
concept IndexedContainer = requires(const ContainerType & container)
{
	{container[0] }-> std::same_as<typename ContainerType::value_type const &>;
	{container.size()} -> std::same_as<std::size_t>;
};


template <typename SequenceFunction>
concept SequenceFunctionTemplate = requires(SequenceFunction function, std::size_t container_size)
{
	{function(container_size) } -> std::same_as<std::vector<std::size_t>>;
};


std::vector<size_t> simple_gaps(size_t container_size)
{
	std::vector<size_t> result;
	while(container_size)
	{
		container_size >>= 1;
		result.push_back(container_size);
	}
	return result;
}


template <typename InputType, typename SequenceFunction, template <typename ...>  class ContainerType>
requires IndexedContainer<ContainerType<InputType>> && SequenceFunctionTemplate<SequenceFunction>
void shell_sort(ContainerType<InputType> & container, SequenceFunction & sequence_function)
{
	size_t size = container.size();
	auto gaps = sequence_function(size);
	for(const auto & gap : gaps)
	{
		for(auto index = gap; index < size; ++index)
		{
			auto temp = container[index];
			size_t other_index{};
			for(other_index = index; other_index >= gap && container[other_index-gap] > temp; other_index-=gap)
				container[other_index] =container[other_index -gap];
			container[other_index] = temp;
		}
	}
}


#endif //SHELL_SORT_H
