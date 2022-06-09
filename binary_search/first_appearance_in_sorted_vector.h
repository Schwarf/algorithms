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
	int current{};
	int step{};
	int begin{};
	while(iterator_distance > 0)
	{
		current = begin;
		step = iterator_distance/2;
		current += step;
		if(input[current] < target)
		{
			begin = ++current;
			iterator_distance -= step + 1;
		}
		else
			iterator_distance = step;
	}
	return begin;

}

#endif //FIRST_APPEARANCE_IN_SORTED_VECTOR_H
