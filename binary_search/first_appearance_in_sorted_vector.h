//
// Created by andreas on 09.06.22.
//

#ifndef FIRST_APPEARANCE_IN_SORTED_VECTOR_H
#define FIRST_APPEARANCE_IN_SORTED_VECTOR_H
#include <type_traits>
#include <vector>
#include <stdexcept>
template<typename T, typename std::enable_if<std::is_integral<T>::value, bool>::type = true>
int first_appearance(std::vector<T> & input, T target)
{
	int iterator_distance = input.size() -1;
	int current_index{};
	int step_size{};
	int start_index{};
	while(iterator_distance > 0)
	{
		current_index = start_index;
		step_size = iterator_distance/2;
		current_index += step_size;
		if(input[current_index] < target)
		{
			start_index = ++current_index;
			iterator_distance -= step_size + 1;
		}
		else
			iterator_distance = step_size;
	}
	return start_index;

}

#endif //FIRST_APPEARANCE_IN_SORTED_VECTOR_H
