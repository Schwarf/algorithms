#include <iostream>
#include "binary_search.h"
#include "first_appearance_in_sorted_vector.h"
int main()
{
	std::vector<int> test{1,  3, 3, 3, 3, 4, 5};
	std::cout << first_appearance(test, 3) << std::endl;
	return 0;
}
