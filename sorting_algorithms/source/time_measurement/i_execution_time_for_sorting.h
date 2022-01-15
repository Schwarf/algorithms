//
// Created by andreas on 15.01.22.
//

#ifndef I_EXECUTION_TIME_FOR_SORTING_H
#define I_EXECUTION_TIME_FOR_SORTING_H
#include <chrono>
#include "./../algorithms/i_sort.h"
#include <memory>
class IExecutionTimeForSorting
{
public:
	virtual void measure(std::vector<int64_t> & array) = 0;
	virtual int64_t execution_time() = 0;
};

#endif //I_EXECUTION_TIME_FOR_SORTING_H
