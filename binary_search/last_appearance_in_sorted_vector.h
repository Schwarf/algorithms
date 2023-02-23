//
// Created by andreas on 09.06.22.
//

#ifndef LAST_APPEARANCE_IN_SORTED_VECTOR_H
#define LAST_APPEARANCE_IN_SORTED_VECTOR_H
#include <type_traits>
#include <vector>
#include <stdexcept>


template<typename T, typename std::enable_if<std::is_integral<T>::value, bool>::type = true>
int last_appearance(std::vector<T> & input, T target)
{
	int iterator_distance = input.size() -1;
	int current_index{};
	int step{};
	int start_index{};
	while(iterator_distance > 0)
	{
		current_index = start_index;
		step = iterator_distance/2;
		current_index += step;
		if(target >= input[current_index])
		{
			start_index = current_index;
			++start_index;
			iterator_distance -= step + 1;
		}
		else
			iterator_distance = step;
	}
	return start_index == input.size()-1 ? ++start_index : start_index;

}

#endif //LAST_APPEARANCE_IN_SORTED_VECTOR_H
