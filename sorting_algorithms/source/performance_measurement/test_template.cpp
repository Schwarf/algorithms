//
// Created by andreas on 16.01.22.
//

#include "test_template.h"
TestTemplate::TestTemplate()
{
	std::random_device random_device;
	std::mt19937_64 mersenne_generator(random_device());
	size_t maximal_random_numbers = 10000000000; //10 billion
	for(size_t number_of_random_numbers= 10; number_of_random_numbers < maximal_random_numbers; number_of_random_numbers*=10)
	{
		std::shared_ptr<std::vector<int64_t>> random_numbers = std::make_shared<std::vector<int64_t>>();
		generate_N_random_numbers_(random_numbers, number_of_random_numbers, mersenne_generator);
		data_accumulator_.add_data_vector(random_numbers);
	}
}


void TestTemplate::generate_N_random_numbers_(std::shared_ptr<std::vector<int64_t>> &random_numbers, size_t N,  std::mt19937_64 & engine)
{
	std::uniform_int_distribution<int64_t> uniform_distribution;
	for(size_t index =0; index < N; ++index)
	{
		random_numbers->push_back(uniform_distribution(engine));
	}
}

void TestTemplate::execute_all_with(std::shared_ptr<ISort> &sorting_algorithm)
{
	execution_time_for_sorting_.set_sorting_algorithm(sorting_algorithm);
	std::shared_ptr<std::vector<int64_t>> execution_times = std::make_shared<std::vector<int64_t>>();
	for(size_t data_index =0 ; data_index < data_accumulator_.number_of_entries(); ++data_index)
		{
			execution_time_for_sorting_.measure(data_accumulator_.get_data_vector(data_index));
			execution_times->push_back(execution_time_for_sorting_.execution_time());
		}
	execution_times_dictionary_[sorting_algorithm] = execution_times;
}
std::map<std::shared_ptr<ISort>,
		 std::shared_ptr<std::vector<int64_t>>> TestTemplate::get_execution_time_dictionary() const
{
	return execution_times_dictionary_;
}
