#include <iostream>
#include "queens_problem.h"

int main()
{
	auto r = solve_queen_problem(6);
	for(const auto & element : r)
	{
		for(const auto & e : element)
			std::cout << e << std::endl;
		std::cout << std::endl;
	}

	return 0;
}
