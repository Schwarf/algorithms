//
// Created by andreas on 18.07.22.
//
#include <iostream>
#include "maximum_length_of_same_subarray_in_two_arrays.h"
int main()
{
	std::vector<int> test1{1,2,2,3,4};
	std::vector<int> test2{2,3,4,3,2,5};
	std::cout << maximum_length(test1, test2) << std::endl;
	return 0;
}
