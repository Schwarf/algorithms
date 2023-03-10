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


TEST(reservoir_sampling, test_overall_mean_value)
{
	std::vector<int> input(100);
	double input_size = static_cast<double>(input.size());
	// Fill input
	std::iota(input.begin(), input.end(), 1);

	int sample_size{30};
	double sample_size_d = static_cast<double>(sample_size);

	double mean = (input_size+1.0)/2.0;

	double standard_deviation {};
	for(const auto & element: input)
		standard_deviation += (static_cast<double>(element) - mean)*(static_cast<double>(element) - mean);
	standard_deviation *= 1.0/input_size;
	standard_deviation = std::sqrt(standard_deviation);

	int draws{100000};
	int count = draws;
	std::vector<int> frequencies(input.size()+1);

	while (count--) {
		auto sample = reservoir_sampling(input, sample_size);
		for (const auto &sample_element: sample)
			frequencies[sample_element]++;
	}

	double mean_estimate {};
	for (int i{1} ; i < input_size+1 ; ++i)
		mean_estimate += static_cast<double>(frequencies[i])* input[i-1];
	mean_estimate = mean_estimate/ static_cast<double >(draws)/sample_size_d;

	double one_sigma_error = standard_deviation/std::sqrt(static_cast<double>(draws));

	double absolute_error = std::abs(mean - mean_estimate);
	EXPECT_TRUE(absolute_error < one_sigma_error);
}


TEST(reservoir_sampling, test_chi_square)
{
	std::vector<int> input(100);
	double input_size = static_cast<double>(input.size());
	// Fill input
	std::iota(input.begin(), input.end(), 1);

	int sample_size{30};
	double sample_size_d = static_cast<double>(sample_size);

	double expected_frequency = sample_size_d/input_size;

	int draws{1000};
	int count = draws;
	std::vector<double> frequencies(input.size()+1);
	while (count--) {
		auto sample = reservoir_sampling(input, sample_size);
		for (const auto &sample_element: sample)
			frequencies[sample_element] += 1.0;
	}

	// compute chi-square
	double chi_square {};
	for(int i{1}; i < input_size + 1;++i)
	{
		double difference = frequencies[i]/draws - expected_frequency;
		chi_square += difference*difference/expected_frequency;
	}
	// degrees of freedom are sample_size - 1
	// int degrees_of_freedom = sample_size -1;
	// double alpha = 0.05
	double critical_value = 42.557;
	std::cout << chi_square <<  std::endl;
	EXPECT_TRUE(chi_square < critical_value);


}