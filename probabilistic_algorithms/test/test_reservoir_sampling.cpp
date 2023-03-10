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
	std::vector<int> input(1000);
	std::iota(input.begin(), input.end(), 1);
	int sample_size{10};
	int draws{10000};
	int count = draws;
	double expected_frequency = static_cast<double>(sample_size) / static_cast<double>(input.size());
	std::vector<int> frequencies(input.size()+1);
	double one_sigma_error = std::sqrt(
		1.0 / (static_cast<double>(input.size()) - 1.0) * (1.0 - 1.0 / static_cast<double>(input.size()))
			/ sample_size);
	while (count--) {
		auto sample = reservoir_sampling(input, sample_size);
		for (const auto &sample_element: sample)
			frequencies[sample_element]++;
	}
	for (const auto &frequency: frequencies) {
		double absolute_error = std::abs(static_cast<double>(frequency) / draws - expected_frequency);
		EXPECT_TRUE(absolute_error < 3.0*one_sigma_error);
	}
}
