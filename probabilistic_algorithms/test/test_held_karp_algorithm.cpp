//
// Created by andreas on 11.03.23.
//
#include "gtest/gtest.h"
#include "held_karp_algorithm.h"

#define EPSILON 1.e-15

TEST(held_karp, test_with_10_x_y_integers)
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
	double expected_result = 80.27812116117478; // From computer algebra program
	double result = held_karp_algorithm(locations);
	double deviation = std::abs(1.0 - result / expected_result);
	EXPECT_TRUE(deviation < EPSILON);
}

TEST(held_karp, test_with_10_x_y_z_integers)
{
	std::vector<std::vector<int>> locations = {{14, 12, 24}, {-1, -10, 11}, {-5, 5, 18}, {4, -9, 17}, {-8, 28, 11},
											   {-10, 12, 13}, {2, -5, 21}, {14, 10, 29}, {-7, 11, 2}, {2, -6, 25}};
	double expected_result = 131.6141273880082; // From computer algebra program
	double result = held_karp_algorithm(locations);
	double deviation = std::abs(1.0 - result / expected_result);
	EXPECT_TRUE(deviation < EPSILON);
}

TEST(held_karp, test_with_10_x_y_z_double)
{
	std::vector<std::vector<double>> locations = {{12.00339292908527, 13.21781579188577, 11.60599011013123},
												  {-29.40505379491233, 7.822462287565841, 16.76093398865211},
												  {24.23918076157662, -10.68978073091624, -29.69329530932502},
												  {2.458762523730186, -17.40523077151457, 6.009819943067384},
												  {2.637169239995572, -13.77824403492551, -2.921822581071240},
												  {16.77135694187223, -0.6907291510974005,-25.06317425631435},
												  {-15.22345033409893, -23.12880387623814, 0.8382145270777528},
												  {27.01199130776070, -14.54132522449646, 7.321287565951167},
												  {-23.64074563844771, 4.072545705232386, -10.04329857017606},
												  {13.65691760625165, 2.979758819145019, 18.50914511947816}};
	double expected_result = 246.3066585349684; // From computer algebra program
	double result = held_karp_algorithm(locations);
	double deviation = std::abs(1.0 - result / expected_result);
	EXPECT_TRUE(deviation < EPSILON);
}
