//
// Created by andreas on 14.03.23.
//
#include "gtest/gtest.h"
#include "simulated_annealing_full_templated.h"
#include "traveling_salesman_functors.h"

#define EPSILON 1.e-15

TEST(TestSimulatedAnnealing, simple_full_templated)
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
auto perturbation_function = TravelingSalesmanPerturbationFunction<int, std::vector, std::vector>();
auto object_function = TravelingSalesmanObjectFunction<int, std::vector, std::vector>();

while (tries) {
double
	approximate_result = simulated_annealing_algorithm(locations,
													   object_function,
													   perturbation_function,
													   initial_temperature,
													   cooling_rate,
													   minimal_temperature);
tries--;
double deviation = std::abs(1.0 - approximate_result / exact_result);
double deviation_in_percent = deviation * 100.0;
EXPECT_TRUE(deviation_in_percent < max_deviation_in_percent);
if (deviation < EPSILON)
count_exact++;
}
EXPECT_TRUE(count_exact > 0);
}


TEST(TestSimulatedAnnealing, simple_full_templated2)
{
std::vector<std::vector<int>> locations = {{14, 12, 24}, {-1, -10, 11}, {-5, 5, 18}, {4, -9, 17}, {-8, 28, 11},
										   {-10, 12, 13}, {2, -5, 21}, {14, 10, 29}, {-7, 11, 2}, {2, -6, 25}};
double exact_result{131.6141273880082};
double max_deviation_in_percent{10.0};
double minimal_temperature{0.1};
double cooling_rate{0.99};
double initial_temperature{100.0};
int tries{10};
int count_exact{};
auto perturbation_function = TravelingSalesmanPerturbationFunction<int, std::vector, std::vector>();
auto object_function = TravelingSalesmanObjectFunction<int, std::vector, std::vector>();

while (tries) {
double
	approximate_result = simulated_annealing_algorithm(locations,
													   object_function,
													   perturbation_function,
													   initial_temperature,
													   cooling_rate,
													   minimal_temperature);

tries--;
double deviation = std::abs(1.0 - approximate_result / exact_result);
double deviation_in_percent = deviation * 100.0;
EXPECT_TRUE(deviation_in_percent < max_deviation_in_percent);
if (deviation < EPSILON)
count_exact++;
}
EXPECT_TRUE(count_exact > 0);
}
