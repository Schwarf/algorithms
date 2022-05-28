//
// Created by andreas on 28.05.22.
//
#include <iostream>
#include <vector>
int64_t step_count(int steps)
{
    std::vector<int64_t> help(steps+1, 0);
    help[0] = 0;
    help[1] = 1;
    help[2] = 2;
    help[3] = 4;
    for(int i=4; i <= steps; ++i)
    {
        help[i] = help[i-1] + help[i-2] + help[i-3];
    }
    return help[steps];
}


int main()
{
	std::cout << step_count(37) << std::endl;
}