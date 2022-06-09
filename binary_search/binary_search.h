//
// Created by andreas on 09.06.22.
//

#ifndef BINARY_SEARCH_H
#define BINARY_SEARCH_H
#include <type_traits>
#include <vector>
#include <stdexcept>
template<typename T, typename std::enable_if<std::is_integral<T>::value, bool>::type = true>
bool find(std::vector<T> & input, T target)
{
	if(input.empty())
		throw std::invalid_argument("Input is empty!");

	int left{};
	int right = input.size()-1;
	int middle{};
	while(left <=right)
	{
		middle = (left+right)/2;
		if(input[middle] == target)
			return true;
		else if (input[middle] > target)
		{
			right = middle -1;
		}
		else if (input[middle] < target)
		{
			left = middle +1;
		}
	}
	return false;
}

#endif //BINARY_SEARCH_H
