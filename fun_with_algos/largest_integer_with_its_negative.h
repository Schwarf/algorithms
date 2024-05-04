//
// Created by andreas on 04.05.24.
//

#ifndef FUN_WITH_ALGOS_LARGEST_INTEGER_WITH_ITS_NEGATIVE_H
#define FUN_WITH_ALGOS_LARGEST_INTEGER_WITH_ITS_NEGATIVE_H

#include <vector>
int largest_integer_with_its_negative(std::vector<int> & input)
{
    std::sort(input.begin(), input.end());
    int left{};
    int right = input.size()-1;
    while(left !=right)
    {
        if(input[left]/input[right] > 0)
            return -1;
        if(std::abs(input[left]) == input[right])
            return input[right];
        else if(std::abs(input[left]) > input[right])
            left++;
        else
            right--;
    }
    return -1;

}

#endif //FUN_WITH_ALGOS_LARGEST_INTEGER_WITH_ITS_NEGATIVE_H
