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
	{container->size()} -> std::same_as<std::size_t>;
};



template <typename InputType, typename SequenceFunction, template <typename ...>  class ContainerType>
requires IndexedContainer<ContainerType<InputType>>
void shell_sort(ContainerType<InputType> & container, SequenceFunction & sequence_function)
{

}


#endif //SHELL_SORT_H
