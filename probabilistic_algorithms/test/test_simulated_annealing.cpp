//
// Created by andreas on 12.03.23.
//
#include "gtest/gtest.h"
#include "simulated_annealing.h"
#include "held_karp_algorithm.h"

#define EPSILON 1.e-15


TEST(TestSimulatedAnnealing, simple)
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
		double
			approximate_result = simulated_annealing(locations, initial_temperature, cooling_rate, minimal_temperature);
		tries--;
		double deviation = std::abs(1.0 - approximate_result / exact_result);
		double deviation_in_percent = deviation * 100.0;
		EXPECT_TRUE(deviation_in_percent < max_deviation_in_percent);
		if (deviation < EPSILON)
			count_exact++;
	}
	EXPECT_TRUE(count_exact > 0);
}


TEST(TestSimulatedAnnealing, simple2)
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
	while (tries) {
		double
			approximate_result = simulated_annealing(locations, initial_temperature, cooling_rate, minimal_temperature);
		tries--;
		double deviation = std::abs(1.0 - approximate_result / exact_result);
		double deviation_in_percent = deviation * 100.0;
		EXPECT_TRUE(deviation_in_percent < max_deviation_in_percent);
		if (deviation < EPSILON)
			count_exact++;
	}
	EXPECT_TRUE(count_exact > 0);
}


TEST(TestSimulatedAnnealing, simple3)
{
	std::vector<std::vector<double>> locations = {{12.00339292908527, 13.21781579188577, 11.60599011013123},
												  {-29.40505379491233, 7.822462287565841, 16.76093398865211},
												  {24.23918076157662, -10.68978073091624, -29.69329530932502},
												  {2.458762523730186, -17.40523077151457, 6.009819943067384},
												  {2.637169239995572, -13.77824403492551, -2.921822581071240},
												  {16.77135694187223, -0.6907291510974005, -25.06317425631435},
												  {-15.22345033409893, -23.12880387623814, 0.8382145270777528},
												  {27.01199130776070, -14.54132522449646, 7.321287565951167},
												  {-23.64074563844771, 4.072545705232386, -10.04329857017606},
												  {13.65691760625165, 2.979758819145019, 18.50914511947816}};
	double exact_result{246.3066585349684};
	double max_deviation_in_percent{10.0};
	double minimal_temperature{0.1};
	double cooling_rate{0.99};
	double initial_temperature{100.0};
	int tries{10};
	int count_exact{};
	while (tries) {
		double
			approximate_result = simulated_annealing(locations, initial_temperature, cooling_rate, minimal_temperature);
		tries--;
		double deviation = std::abs(1.0 - approximate_result / exact_result);
		double deviation_in_percent = deviation * 100.0;
		EXPECT_TRUE(deviation_in_percent < max_deviation_in_percent);
		if (deviation < EPSILON)
			count_exact++;
	}
	EXPECT_TRUE(count_exact > 0);
}
TEST(TestSimulatedAnnealing, difficult)
{
	std::vector<std::vector<double>> locations = {{42.48666101836389, 16.18246423104821, 37.19792176607905},
												  {-7.166254873280280, 25.24187972494587, 43.51182283209846},
												  {-10.80313396129739, -33.19032140025450, -8.372872137237806},
												  {-37.28280169229853, -34.77670948701683, 49.98899635150025},
												  {-2.257150979316293, -2.833797992194633, 1.202158246705096},
												  {48.06653229485326, 4.331301016536884, -36.36395343444927},
												  {-42.04150805323883, 44.61473495600973, 9.411348963539865},
												  {2.960377573832943, 2.338884551037353, 40.19184731887731},
												  {3.368401957094477, 28.84437124810415, 41.10049160557875},
												  {24.87885475437773, 43.52209133620144, 22.41058114449010},
												  {8.377558176810481, 5.308663342416935, 27.91950427134989},
												  {-18.31934846471580, 14.72925081150100, -17.92735358135224},
												  {-35.19597131428442, -44.10170116417574, -49.09616645696188},
												  {-45.46470515698937, 25.77130294119343, -16.49065758484929},
												  {-10.04646371885934, 26.18204825674303, 15.51115609772035},
												  {-14.85013927930638, 25.50746512123820, 30.47207199721291},
												  {-25.87940031176660, -47.84465190901388, -27.84895351427032},
												  {1.743272593308234, -9.124801939736386, -1.387030172101561},
												  {-40.47012385039430, 0.8627777410297028, -40.49350452116605},
												  {-6.197460316854034, 49.57092472156796, 42.61050915477912},
												  {22.59787028037948, -16.10776172290565, 17.28264318194485},
												  {-10.47004677622704, 17.76962717038251, 28.33084869861489},
												  {-30.48538897149027, 26.73413038671356, -26.69904326655559},
												  {-32.07438928125134, 16.25844225347515, -30.98852565093249},
												  {-30.22656933455845, -1.924129919607253, -36.32728701606310},
												  {29.23425210237446, -1.666348502990814, 15.83374866819423},
												  {21.58362898282576, 45.90710639809461, -3.046606223975772},
												  {24.12220773620234, -30.71458696350182, -42.09164359517763},
												  {-29.63113468704464, -11.20842696153460, 22.15390544948178},
												  {6.230598008349119, -33.52107872770915, -31.06915450778756}};
	double exact_result{807.22976479499}; // From Computer algebra program
	double minimal_temperature{0.001};
	double cooling_rate{0.99999};
	double initial_temperature{100.0};
	int tries{3};
	std::vector<double> approximate_results;
	std::vector<double> deviation_results;
	while (tries) {

		double
			approximate_result = simulated_annealing(locations, initial_temperature, cooling_rate, minimal_temperature);
		approximate_results.push_back(approximate_result);
		tries--;
	}
	auto mean =
		std::accumulate(approximate_results.cbegin(), approximate_results.cend(), 0.0) / approximate_results.size();
	auto mean_deviations =
		std::accumulate(deviation_results.cbegin(), deviation_results.cend(), 0.0) / approximate_results.size();
	auto sum_of_squared_difference = std::transform_reduce(approximate_results.begin(), approximate_results.end(), 0.0,
														   std::plus<>(), [mean](double x)
														   { return (x - mean) * (x - mean); });

	auto standard_deviation = std::sqrt(sum_of_squared_difference / approximate_results.size());
	std::cout << mean << " +/- " << standard_deviation << std::endl;
	std::cout << "Deviation of mean from exact result: "  << std::abs(1.0 -mean/exact_result) << std::endl;
	// Best result in this setup: 12.03.2023
	// double minimal_temperature{0.001};
	// double cooling_rate{0.99999};
	// double initial_temperature{100.0};
	// int tries{3};
	// mena = 826.97 +/- 9.64319
	// Deviation of mean from exact result: 0.0244545

}