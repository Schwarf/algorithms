//
// Created by andreas on 16.01.22.
//

#ifndef TEST_TEMPLATE_H
#define TEST_TEMPLATE_H
#include <memory>
#include <random>
#include <map>
#include <limits>

#include "i_test_template.h"
#include "data_accumulator.h"
#include "execution_time_for_sorting.h"

class TestTemplate final: public ITestTemplate
{
public:
	TestTemplate();
	void execute_all_with(std::shared_ptr<ISort> &sorting_algorithm, const std::string & algorithm_name) final;
	std::map<std::shared_ptr<ISort>, std::shared_ptr<std::vector<int64_t>>> get_execution_time_map() const final;
	std::map<std::shared_ptr<ISort>, std::string> get_algorithm_name_map() const final;
private:
	static void generate_N_random_numbers_(std::shared_ptr<std::vector<int64_t>> &random_numbers,
										   size_t N,
										   std::mt19937_64 &engine);
	DataAccumulator<int64_t> data_accumulator_{};
	ExecutionTimeForSorting execution_time_for_sorting_{};
	std::map<std::shared_ptr<ISort>, std::shared_ptr<std::vector<int64_t>>> execution_times_map_;
	std::map<std::shared_ptr<ISort>, std::string> names_map_;
};


#endif //TEST_TEMPLATE_H

