//
// Created by andreas on 12.03.23.
//
#include "gtest/gtest.h"
#include "simulated_annealing.h"
#include "held_karp_algorithm.h"

#define EPSILON 1.e-15

class SetupSimulatedAnnealingTest : public testing::Test
{
public:
	explicit SetupSimulatedAnnealingTest()
	: random_generator_(std::random_device{}())
	{

	}
private:
	std::mt19937 random_generator_;
};


TEST(TestSimulatedAnnealing, simple )
{
	std::vector<std::vector<int>> locations = {{0, 0},
											   {1, 1},
											   {2, 0},
											   {3, 2},
											   {4, 1},
											   {5, 3},
											   {6, 0},
											   {7, 2},
											   {27, -10},
											   {-6, -9}};
	double exact_result{80.27812116117478};
	double max_deviation_in_percent{10.0};
	double minimal_temperature{0.1};
	double cooling_rate{0.99};
	double initial_temperature{100.0};
	int tries{10};
	int count_exact{};
	while (tries) {
		double approximate_result = simulated_annealing(locations, initial_temperature, cooling_rate, minimal_temperature);
		tries--;
		double deviation = std::abs(1.0 - approximate_result/exact_result);
		double deviation_in_percent = deviation*100.0;
		EXPECT_TRUE(deviation_in_percent < max_deviation_in_percent);
		if(deviation < EPSILON)
			count_exact++;
	}
	EXPECT_TRUE(count_exact > 0);
}

