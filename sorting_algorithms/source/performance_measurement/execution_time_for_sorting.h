//
// Created by andreas on 15.01.22.
//

#ifndef EXECUTION_TIME_FOR_SORTING_H
#define EXECUTION_TIME_FOR_SORTING_H
#include "i_execution_time_for_sorting.h"

class ExecutionTimeForSorting final: public IExecutionTimeForSorting
{
public:
	ExecutionTimeForSorting() = default;
	explicit ExecutionTimeForSorting(std::shared_ptr<ISort> &sorting_algorithm);
	void measure(std::vector<int64_t> &array) final;
	void measure(std::shared_ptr<std::vector<int64_t>> array) final;
	int64_t execution_time() final;
	void set_sorting_algorithm(std::shared_ptr<ISort> algorithm) override;
private:
	std::shared_ptr<ISort> sorting_algorithm_ = nullptr;
	int64_t execution_time_{};

};


#endif //EXECUTION_TIME_FOR_SORTING_H
