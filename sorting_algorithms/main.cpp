#include <algorithm>
#include <iostream>
#include <vector>

bool compare_pointers(const int* a, const int* b)
{
	return *a < *b;
}

int main()
{
	std::vector<int*> vec{new int(5), new int(2), new int(9)};

	// Sort the vector using the custom comparison function
	std::sort(vec.begin(), vec.end(), compare_pointers);

	// Print the sorted vector
	for (int* ptr : vec)
	{
		std::cout << *ptr << " ";
	}
	std::cout << std::endl;

	// Delete the dynamically allocated integers
	for (int* ptr : vec)
	{
		delete ptr;
	}

	return 0;
}

