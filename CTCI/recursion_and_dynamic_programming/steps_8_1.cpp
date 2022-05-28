//
// Created by andreas on 28.05.22.
//
#include <iostream>
#include <vector>
int64_t step_count(int steps)
{
	if(steps ==  0)
		return 0;
	if(steps == 1)
		return 1;
	if(steps == 2)
		return 2;

    std::vector<int64_t> help(steps+1, 0);
	help[0] = 0;
    help[1] = 1;
    help[2] = 2;

	for(int i=3; i <= steps; ++i)
    {
        help[i] = help[i-1] + help[i-2] + help[i-3];
    }
    return help[steps];
}

int64_t step_count_recursive(int steps)
{
	if (steps <=0)
		return 0;
	if (steps ==1)
		return 1;
	if (steps ==2)
		return 2;
	return step_count_recursive(steps-1) + step_count_recursive(steps-2) + step_count_recursive(steps-3);
}


int main()
{
	std::cout << step_count(18) << std::endl;
	std::cout << step_count_recursive(18) << std::endl;
}