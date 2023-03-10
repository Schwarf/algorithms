//
// Created by andreas on 10.03.23.
//

#include "gtest/gtest.h"
#include "reservoir_sampling.h"

TEST(reservoir_sampling, test_size)
{
	std::vector<int> input{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int sample_size{5};
	auto sample = reservoir_sampling(input, sample_size);
	EXPECT_EQ(sample.size(), sample_size);
}

TEST(reservoir_sampling, test_output)
{
	std::vector<int> input{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int sample_size{5};
	auto sample = reservoir_sampling(input, sample_size);
	for (const auto &sample_element: sample)
		EXPECT_TRUE(std::ranges::find(input, sample_element) != input.end());
}


TEST(reservoir_sampling, test_distribution)
{
	std::vector<int> input(200);
	double input_size = static_cast<double>(input.size());

	std::iota(input.begin(), input.end(), 1);
	int sample_size{30};
	double sample_size_d = static_cast<double>(sample_size);
	int draws{10000};
	int count = draws;
	std::vector<int> frequencies(input.size()+1);
	double mean = (input_size+1.0)/2.0;
	double standard_deviation {};
	for(const auto & element: input)
		standard_deviation += (static_cast<double>(element) - mean)*(static_cast<double>(element) - mean);
	standard_deviation *= 1.0/input_size;
	standard_deviation = std::sqrt(standard_deviation);
	double one_sigma_error = standard_deviation/std::sqrt(static_cast<double>(draws));
	double mean_estimate {};
	while (count--) {
		auto sample = reservoir_sampling(input, sample_size);
		for (const auto &sample_element: sample)
			frequencies[sample_element]++;
	}

	for (int i{1} ; i < input_size+1 ; ++i)
		mean_estimate += static_cast<double>(frequencies[i])* input[i-1];
	mean_estimate = mean_estimate/ static_cast<double >(draws)/sample_size_d;

	std::cout << mean_estimate <<  "  " << mean << "  " << one_sigma_error ;
}
