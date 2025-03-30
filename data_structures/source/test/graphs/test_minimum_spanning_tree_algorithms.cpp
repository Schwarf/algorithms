//
// Created by andreas on 04.01.24.
//
#include "gtest/gtest.h"
#include "graphs/minimum_spanning_tree_algorithms.h"

class SetupMSTGraphTests : public testing::Test
{
public:
    SetupMSTGraphTests() = default;
    static constexpr auto max_uint = std::numeric_limits<unsigned int>::max();
    static constexpr auto max_int = std::numeric_limits<int>::max();
    static constexpr auto max_float = std::numeric_limits<float>::max();

    static std::tuple<std::vector<std::vector<std::pair<unsigned int, float>>>,
                      std::vector<std::vector<float>>,
                      std::vector<std::vector<float>>,
                      std::vector<std::vector<unsigned int>>> case1()
    {
        std::vector<std::vector<float>> adjacency_matrix = {
            {0.0, 2.5, 1.8, max_float, max_float},
            {2.5, 0.0, 2.0, 3.1, max_float},
            {1.8, 2.0, 0.0, max_float, 1.6},
            {max_float, 3.1, max_float, 0.0, 2.3},
            {max_float, max_float, 1.6, 2.3, 0.0}
        };
        std::vector<std::vector<std::pair<unsigned int, float>>> adjacency_list = {
            {{1, 2.5}, {2, 1.8}},
            {{0, 2.5}, {2, 2.0}, {3, 3.1}},
            {{0, 1.8}, {1, 2.0}, {4, 1.6}},
            {{1, 3.1}, {4, 2.3}},
            {{2, 1.6}, {3, 2.3}}
        };
        std::vector<std::vector<float>> weight_vectors_per_start_vertex = {
            {0.0, 2.0, 1.8, 2.3, 1.6},
            {1.8, 0.0, 2.0, 2.3, 1.6},
            {1.8, 2.0, 0.0, 2.3, 1.6},
            {1.8, 2.0, 1.6, 0.0, 2.3},
            {1.8, 2.0, 1.6, 2.3, 0.0},
        };
        std::vector<std::vector<unsigned int>> parent_vectors_per_start_vertex = {
            {max_uint, 2, 0, 4, 2},
            {2, max_uint, 1, 4, 2},
            {2, 2, max_uint, 4, 2},
            {2, 2, 4, max_uint, 3},
            {2, 2, 4, 4, max_uint},
        };

        return std::make_tuple(adjacency_list,
                               adjacency_matrix,
                               weight_vectors_per_start_vertex,
                               parent_vectors_per_start_vertex);
    }

    static std::tuple<std::vector<std::vector<std::pair<unsigned int, int>>>,
                      std::vector<std::vector<int>>,
                      std::vector<std::vector<int>>,
                      std::vector<std::vector<unsigned int>>> case2()
    {
        std::vector<std::vector<int>> adjacency_matrix = {
            {0, 4, max_int, 6, max_int, max_int, max_int, max_int, max_int, max_int},
            {4, 0, 3, max_int, max_int, 8, 4, max_int, max_int, max_int},
            {max_int, 3, 0, 2, max_int, max_int, 2, max_int, max_int, max_int},
            {6, max_int, 2, 0, 4, max_int, max_int, max_int, max_int, max_int},
            {max_int, max_int, max_int, 4, 0, max_int, max_int, 12, max_int, 7},
            {max_int, 8, max_int, max_int, max_int, 0, max_int, max_int, 5, 3},
            {max_int, 4, 2, max_int, max_int, max_int, 0, max_int, max_int, max_int},
            {max_int, max_int, max_int, max_int, 12, max_int, max_int, 0, 4, max_int},
            {max_int, max_int, max_int, max_int, max_int, 5, max_int, 4, 0, max_int},
            {max_int, max_int, max_int, max_int, 7, 3, max_int, max_int, max_int, 0}
        };
        std::vector<std::vector<std::pair<unsigned int, int>>> adjacency_list = {
            {{1, 4}, {3, 6}},
            {{0, 4}, {2, 3}, {5, 8}, {6, 4}},
            {{1, 3}, {3, 2}, {6, 2}},
            {{0, 6}, {2, 2}, {4, 4}},
            {{3, 4}, {7, 12}, {9, 7}},
            {{1, 8}, {8, 5}, {9, 3}},
            {{1, 4}, {2, 2}},
            {{4, 12}, {8, 4}},
            {{5, 5}, {7, 4}},
            {{4, 7}, {5, 3}}
        };
        std::vector<std::vector<int>> weight_vectors_per_start_vertex = {
            {0, 4, 3, 2, 4, 3, 2, 4, 5, 7},
            {4, 0, 3, 2, 4, 3, 2, 4, 5, 7},
            {4, 3, 0, 2, 4, 3, 2, 4, 5, 7},
            {4, 3, 2, 0, 4, 3, 2, 4, 5, 7},
            {4, 3, 2, 4, 0, 3, 2, 4, 5, 7},
            {4, 3, 2, 4, 7, 0, 2, 4, 5, 3},
            {4, 3, 2, 2, 4, 3, 0, 4, 5, 7},
            {4, 3, 2, 4, 7, 5, 2, 0, 4, 3},
            {4, 3, 2, 4, 7, 5, 2, 4, 0, 3},
            {4, 3, 2, 4, 7, 3, 2, 4, 5, 0},
        };
        std::vector<std::vector<unsigned int>> parent_vectors_per_start_vertex = {
            {max_uint, 0, 1, 2, 3, 9, 2, 8, 5, 4},
            {1, max_uint, 1, 2, 3, 9, 2, 8, 5, 4},
            {1, 2, max_uint, 2, 3, 9, 2, 8, 5, 4},
            {1, 2, 3, max_uint, 3, 9, 2, 8, 5, 4},
            {1, 2, 3, 4, max_uint, 9, 2, 8, 5, 4},
            {1, 2, 3, 4, 9, max_uint, 2, 8, 5, 5},
            {1, 2, 6, 2, 3, 9, max_uint, 8, 5, 4},
            {1, 2, 3, 4, 9, 8, 2, max_uint, 7, 5},
            {1, 2, 3, 4, 9, 8, 2, 8, max_uint, 5},
            {1, 2, 3, 4, 9, 9, 2, 8, 5, max_uint},
        };


        return std::make_tuple(adjacency_list,
                               adjacency_matrix,
                               weight_vectors_per_start_vertex,
                               parent_vectors_per_start_vertex);
    }
};


TEST_F(SetupMSTGraphTests, TestPrimsAdjacencyListCase1)
{
    auto tuple = case1();
    auto adjacency_list = std::get<0>(tuple);
    auto expected_weight_lists = std::get<2>(tuple);
    auto expected_mst_lists = std::get<3>(tuple);
    constexpr unsigned int number_of_vertices{5U};
    for (unsigned int start_vertex{}; start_vertex < number_of_vertices; ++start_vertex)
    {
        auto result = minimum_spanning_tree_prim(start_vertex, adjacency_list);
        auto result_weights = std::get<1>(result);
        auto result_mst = std::get<0>(result);
        for (unsigned int i{}; i < number_of_vertices; ++i)
        {
            EXPECT_FLOAT_EQ(result_weights[i], expected_weight_lists[start_vertex][i]);
            EXPECT_FLOAT_EQ(result_mst[i], expected_mst_lists[start_vertex][i]);
        }
    }
}

TEST_F(SetupMSTGraphTests, TestPrimsAdjacencyMatrixCase1)
{
    auto tuple = case1();
    auto adjacency_matrix = std::get<1>(tuple);
    auto expected_weight_lists = std::get<2>(tuple);
    auto expected_mst_lists = std::get<3>(tuple);
    constexpr unsigned int number_of_vertices{5U};
    for (unsigned int start_vertex{}; start_vertex < number_of_vertices; ++start_vertex)
    {
        auto result = minimum_spanning_tree_prim_matrix(start_vertex, adjacency_matrix);
        auto result_weights = std::get<1>(result);
        auto result_mst = std::get<0>(result);
        for (unsigned int i{}; i < number_of_vertices; ++i)
        {
            EXPECT_FLOAT_EQ(result_weights[i], expected_weight_lists[start_vertex][i]);
            EXPECT_FLOAT_EQ(result_mst[i], expected_mst_lists[start_vertex][i]);
        }
    }
}

TEST_F(SetupMSTGraphTests, TestPrimsAdjacencyListCase2)
{
    auto tuple = case2();
    auto adjacency_list = std::get<0>(tuple);
    auto expected_weight_lists = std::get<2>(tuple);
    auto expected_mst_lists = std::get<3>(tuple);
    constexpr unsigned int number_of_vertices{10U};
    for (unsigned int start_vertex{}; start_vertex < number_of_vertices; ++start_vertex)
    {
        auto result = minimum_spanning_tree_prim(start_vertex, adjacency_list);
        auto result_weights = std::get<1>(result);
        auto result_mst = std::get<0>(result);
        for (unsigned int i{}; i < number_of_vertices; ++i)
        {
            EXPECT_FLOAT_EQ(result_weights[i], expected_weight_lists[start_vertex][i]);
            EXPECT_FLOAT_EQ(result_mst[i], expected_mst_lists[start_vertex][i]);
        }
    }
}

TEST_F(SetupMSTGraphTests, TestPrimsAdjacencyMatrixCase2)
{
    auto tuple = case2();
    auto adjacency_matrix = std::get<1>(tuple);
    auto expected_weight_lists = std::get<2>(tuple);
    auto expected_mst_lists = std::get<3>(tuple);
    constexpr unsigned int number_of_vertices{10U};
    for (unsigned int start_vertex{}; start_vertex < number_of_vertices; ++start_vertex)
    {
        auto result = minimum_spanning_tree_prim_matrix(start_vertex, adjacency_matrix);
        auto result_weights = std::get<1>(result);
        auto result_mst = std::get<0>(result);
        for (unsigned int i{}; i < number_of_vertices; ++i)
        {
            EXPECT_FLOAT_EQ(result_weights[i], expected_weight_lists[start_vertex][i]);
            EXPECT_FLOAT_EQ(result_mst[i], expected_mst_lists[start_vertex][i]);
        }
    }
}
