//
// Created by andreas on 14.09.23.
//

#include "gtest/gtest.h"
#include "graphs/reconstruct_flight_itinerary.h"

TEST(ReconstructItinerary, simple1)
{
    const std::vector<std::vector<std::string>> input{{"MUC", "LHR"}, {"JFK", "MUC"}, {"SFO", "SJC"}, {"LHR", "SFO"}};
    const std::vector<std::string> expected_output{"JFK", "MUC", "LHR", "SFO", "SJC"};
    EXPECT_EQ(expected_output, reconstruct_itinerary(input));
}

TEST(ReconstructItinerary, simple2)
{
    const std::vector<std::vector<std::string>>
        input{{"JFK", "SFO"}, {"JFK", "ATL"}, {"SFO", "ATL"}, {"ATL", "JFK"}, {"ATL", "SFO"}};
    const std::vector<std::string> expected_output{"JFK", "ATL", "JFK", "SFO", "ATL", "SFO"};
    EXPECT_EQ(expected_output, reconstruct_itinerary(input));
}

TEST(ReconstructItinerary, complex1)
{
    const std::vector<std::vector<std::string>>
        input
        {
            {"EZE", "TIA"}, {"EZE", "AXA"}, {"AUA", "EZE"}, {"EZE", "JFK"}, {"JFK", "ANU"}, {"JFK", "ANU"},
            {"AXA", "TIA"},
            {"JFK", "AUA"}, {"TIA", "JFK"}, {"ANU", "EZE"}, {"ANU", "EZE"}, {"TIA", "AUA"}
        };
    const std::vector<std::string>
        expected_output{"JFK", "ANU", "EZE", "AXA", "TIA", "AUA", "EZE", "JFK", "ANU", "EZE", "TIA", "JFK", "AUA"};
    EXPECT_EQ(expected_output, reconstruct_itinerary(input));
}
