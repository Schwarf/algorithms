//
// Created by andreas on 15.01.22.
//

#ifndef EXECUTION_TIME_FOR_SORTING_H
#define EXECUTION_TIME_FOR_SORTING_H
#include "i_execution_time_for_sorting.h"

class ExecutionTimeForSorting final : public IExecutionTimeForSorting
{
public:
	ExecutionTimeForSorting(std::shared_ptr<ISort> & sorting_object);
	void measure(std::vector<int64_t> &array) final;
	int64_t execution_time() final;
private:
	std::shared_ptr<ISort> & sorting_object_;
	int64_t execution_time_{};

};


#endif //EXECUTION_TIME_FOR_SORTING_H
