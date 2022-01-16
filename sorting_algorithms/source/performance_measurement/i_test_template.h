//
// Created by andreas on 16.01.22.
//

#ifndef I_TEST_TEMPLATE_H
#define I_TEST_TEMPLATE_H
#include "../algorithms/i_sort.h"

class ITestTemplate
{
	virtual void execute_all_with(std::shared_ptr<ISort> &sorting_algorithm) = 0;
	virtual std::map<std::shared_ptr<ISort>,
					 std::shared_ptr<std::vector<int64_t>>> get_execution_time_dictionary() const = 0;
};

#endif //I_TEST_TEMPLATE_H
