#include <iostream>
#include "selection_sort/selection_sort.h"
#include "insertion_sort/insertion_sort.h"
#include "merge_sort/merge_sort.h"

int main()
{
	std::vector<int64_t> test{17, 10, 1, 2, 25, 6, 62, 3, 3, 4, 4, 5, 5};
	MergeSort selection_sort;
	selection_sort.sort(test);
	size_t i = 0;
	size_t j = 0;
	for (const auto &element: test) {
		std::cout << element << std::endl;
	}
	return 0;
}
