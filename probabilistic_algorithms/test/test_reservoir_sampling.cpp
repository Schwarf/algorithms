//
// Created by andreas on 10.03.23.
//

#include "gtest/gtest.h"
#include <ranges>
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
	auto input_size = static_cast<double>(input.size());
	// Fill input
	std::iota(input.begin(), input.end(), 1);

	int sample_size{30};
	auto sample_size_d = static_cast<double>(sample_size);

	double mean = (input_size + 1.0) / 2.0;

	double standard_deviation{};
	for (const auto &element: input)
		standard_deviation += (static_cast<double>(element) - mean) * (static_cast<double>(element) - mean);
	standard_deviation *= 1.0 / input_size;
	standard_deviation = std::sqrt(standard_deviation);

	int experiments{10000};
	int count = experiments;
	std::vector<int> frequencies(input.size() + 1);

	while (count--) {
		auto sample = reservoir_sampling(input, sample_size);
		for (const auto &sample_element: sample)
			frequencies[sample_element]++;
	}

	double mean_estimate{};
	for (int i{1}; i < input_size + 1; ++i)
		mean_estimate += static_cast<double>(frequencies[i]) * input[i - 1];
	mean_estimate = mean_estimate / static_cast<double >(experiments) / sample_size_d;

	double one_sigma_error = standard_deviation / std::sqrt(static_cast<double>(experiments));

	double absolute_error = std::abs(mean - mean_estimate);
	EXPECT_TRUE(absolute_error < one_sigma_error);
}


TEST(reservoir_sampling, test_uniform_distribution_frequencies)
{
	std::vector<int> input(100);
	auto input_size = static_cast<double>(input.size());
	// Fill input
	std::iota(input.begin(), input.end(), 1);

	int sample_size{30};
	auto sample_size_d = static_cast<double>(sample_size);

	int experiments{10000};

	double expected_proportion = 1.0 / input_size;
	// Sample proportion follows binomial distribution with parameters
	// p = proportion and
	// number of experiments n = experiments.
	// X= n*p is expected value for the number of successes for one input element.
	// So the proportion for one input-element is given as p = X/n;
	double expected_std_error = std::sqrt(expected_proportion * (1 - expected_proportion) / experiments);
	int count = experiments;
	std::vector<int> frequencies(input.size() + 1);

	while (count--) {
		auto sample = reservoir_sampling(input, sample_size);
		for (const auto &sample_element: sample)
			frequencies[sample_element]++;
	}
	// The number of total draws from the input is given as number of experiments times the sample_size per experiment
	double total_draws = experiments * sample_size_d;
	std::vector<double> sample_proportion(input.size() + 1);
	for (int i{1}; i < input_size + 1; ++i) {
		sample_proportion[i] = static_cast<double>(frequencies[i]) / total_draws;
		double absolute_error = std::abs(sample_proportion[i] - expected_proportion);
		EXPECT_TRUE(absolute_error < 3 * expected_std_error);
	}

}


TEST(reservoir_sampling, test_non_uniform_ditribution_frequencies)
{
	std::vector<int> input{1, 2, 3, 2, 1, 4, 5, 5, 3, 3, 2, 1};
	int sample_size{7};
	double sample_size_d = static_cast<double>(sample_size);
	int experiments{10000};
	std::vector<double> expected_proportion{0., 3. / 12., 3. / 12., 3. / 12., 1. / 12., 2. / 12.};

	// Sample proportion follows binomial distribution with parameters
	// p = proportion and
	// number of experiments n = experiments.
	// X= n*p is expected value for the number of successes for one input element.
	// So the proportion for one input-element is given as p = X/n;

	std::vector<double> expected_std_error(expected_proportion.size());
	for (int i{}; i < expected_proportion.size(); ++i)
		expected_std_error[i] = std::sqrt(expected_proportion[i] * (1 - expected_proportion[i]) / experiments);
	int count = experiments;
	std::vector<int> frequencies(expected_proportion.size());
	while (count--) {
		auto sample = reservoir_sampling(input, sample_size);
		for (const auto &sample_element: sample)
			frequencies[sample_element]++;
	}
	// The number of total draws from the input is given as number of experiments times the sample_size per experiment
	double total_draws = experiments * sample_size_d;

	std::vector<double> sample_proportion(expected_proportion.size());
	for (int i{1}; i < expected_proportion.size(); ++i) {
		// Here we divide by sample_size_d, since we need to normalize the proportion. In
		// 100000 experiments with 7 draws and given sample_size we expect more than 100000 appearances if
		// the values in the input are not uniformly distributed like in this case.
		sample_proportion[i] = static_cast<double>(frequencies[i]) / total_draws;
		double absolute_error = std::abs(sample_proportion[i] - expected_proportion[i]);
		EXPECT_TRUE(absolute_error < 3 * expected_std_error[i]);
	}

}
