//
// Created by andreas on 15.01.22.
//

#ifndef I_EXECUTION_TIME_FOR_SORTING_H
#define I_EXECUTION_TIME_FOR_SORTING_H
#include <chrono>
#include "./../algorithms/i_sort.h"

class IExecutionTimeForSorting()
{
public:
	virtual void measure() = 0;
}

#endif //I_EXECUTION_TIME_FOR_SORTING_H
