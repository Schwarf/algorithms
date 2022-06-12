#include <iostream>
#include "sum_longest_subarray_with_unique_elements.h"

int main()
{
	std::vector<int> test1{4,2,4,5,6};
	std::vector<int> test2{5,2,1,2,5,2,1,2,5};
	std::vector<int> test3{5,5,5,5};
	std::vector<int> test4{2,3,4,5,6,7,8,4,15};
	std::vector<int> test5{4,1,4,2,4,3,4,5,6,4,4,7,8};
	int result1 = 17, result2=8, result3 = 5, result4 = 45, result5 = 19;
	std::cout << sum_longest_subarray_with_unique_elements(test1) - result1 << std::endl;
	std::cout << sum_longest_subarray_with_unique_elements(test2) - result2 << std::endl;
	std::cout << sum_longest_subarray_with_unique_elements(test3) - result3 << std::endl;
	std::cout << sum_longest_subarray_with_unique_elements(test4) - result4 << std::endl;
	std::cout << sum_longest_subarray_with_unique_elements(test5) - result5 << std::endl;

	return 0;
}
