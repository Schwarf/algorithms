//
// Created by andreas on 28.12.24.
//
#include "graphs/topological_sort/kahns_algorithm.h"
#include "gtest/gtest.h"


class SetupTopologicalSortTesting : public testing::Test
{
public:
    SetupTopologicalSortTesting() = default;

protected:
    template <typename NodeType>
    void verify_topological_order(const DirectedGraph<NodeType>& graph, std::vector<NodeType>& order)
    {
        std::unordered_map<NodeType, int> position;
        for (int i{}; i < order.size(); ++i)
        {
            position[order[i]] = i;
        }

        EXPECT_EQ(order.size(), graph.get_all_nodes().size());
        auto nodes = graph.get_all_nodes();
        for (const auto node : nodes)
        {
            for (const auto neighbor : graph.get_neighbors(node))
            {
                EXPECT_TRUE(position[node] < position[neighbor]);
            }
        }
    }
};


TEST_F(SetupTopologicalSortTesting, simple1)
{
    DirectedGraph<int> digraph{
        {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, {
            {1, 3}, {1, 4}, {1, 5}, {1, 6}, {1, 7},
            {1, 8}, {1, 9}, {1, 10}, {2, 3}, {2, 4},
            {2, 9}, {2, 10}, {3, 4}, {3, 6}, {3, 8},
            {3, 9}, {3, 10}, {4, 5}, {4, 6}, {4, 7},
            {4, 8}, {4, 9}, {5, 6}, {5, 7}, {5, 8},
            {5, 9}, {6, 7}, {6, 8}, {6, 9}, {6, 10},
            {7, 8}, {7, 10}, {8, 9}
        }
    };
    std::vector<int> expected_result{1, 2, 3, 4, 5, 6, 7, 10, 8, 9};
    auto computed_order = kahns_algorithm(digraph);
    EXPECT_EQ(kahns_algorithm(digraph), expected_result);
    verify_topological_order(digraph, computed_order);
}

TEST_F(SetupTopologicalSortTesting, simple2)
{
    DirectedGraph<int> digraph{
        {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20}, {
            {1, 3}, {1, 5}, {1, 7}, {1, 9}, {1, 11}, {1, 15}, {1, 18}, {2, 3}, {
                2, 6
            },
            {2, 7}, {2, 9}, {2, 11}, {2, 12}, {2, 13}, {2, 14}, {2, 17}, {
                2, 20
            },
            {3, 5}, {3, 8}, {3, 9}, {3, 17}, {3, 19}, {4, 5}, {4, 9}, {
                4, 10
            },
            {4, 11}, {4, 16}, {4, 20}, {5, 7}, {5, 10}, {5, 11}, {
                5, 16
            },
            {6, 8}, {6, 12}, {7, 8}, {7, 9}, {7, 13}, {7, 14}, {7, 15}, {
                7, 16
            },
            {7, 17}, {8, 9}, {8, 10}, {8, 14}, {8, 15}, {8, 20}, {
                9, 10
            },
            {9, 12}, {9, 18}, {11, 12}, {11, 13}, {11, 14}, {11, 16}, {
                11, 17
            },
            {11, 19}, {11, 20}, {12, 13}, {12, 15}, {12, 16}, {12, 17}, {
                12, 19
            },
            {13, 16}, {13, 20}, {14, 20}, {15, 18}, {16, 19}
        }
    };
    auto computed_order = kahns_algorithm(digraph);
    verify_topological_order(digraph, computed_order);
}


TEST_F(SetupTopologicalSortTesting, medium1)
{
    DirectedGraph<int> digraph{
        {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30},
        {
            {1, 2}, {1, 5}, {1, 6}, {1, 8}, {1, 11}, {1, 13}, {1, 14}, {1, 15}, {1, 18}, {1, 20}, {1, 22}, {1, 23},
            {1, 25}, {1, 29}, {1, 30}, {2, 3}, {\
                2, 4
            },
            {2, 5}, {2, 6}, {2, 7}, {2, 10}, {2, 11}, {2, 14}, {2, 15}, {2, 17}, {2, 20}, {2, 21}, {2, 22}, {2, 24},
            {2, 27}, {2, 28}, {3, 5}, {\
                3, 11
            },
            {3, 12}, {3, 20}, {3, 22}, {3, 23}, {3, 24}, {3, 25}, {
                3,\
                26
            },
            {3, 27}, {3, 29}, {3, 30}, {4, 6}, {4, 8}, {4, 9}, {4, 11}, {
                4,\
                12
            },
            {4, 14}, {4, 15}, {4, 17}, {4, 18}, {4, 19}, {4, 20}, {4, 22}, {4, 23}, {4, 25}, {4, 27}, {4, 29}, {5, 6},
            {5, 10}, {5, 17}, {5, 22}, {\
                5, 24
            },
            {5, 29}, {6, 8}, {6, 14}, {6, 17}, {6, 18}, {6, 19}, {
                6,\
                22
            },
            {6, 23}, {6, 26}, {6, 28}, {6, 29}, {7, 8}, {7, 10}, {7, 14}, {7, 15}, {7, 16}, {7, 17}, {7, 20}, {7, 22},
            {7, 26}, {7, 29}, {8, 9}, {\
                8, 10
            },
            {8, 11}, {8, 13}, {8, 15}, {8, 20}, {8, 23}, {8, 25}, {
                8,\
                26
            },
            {8, 27}, {8, 29}, {8, 30}, {9, 12}, {9, 13}, {9, 14}, {9, 18}, {9, 19}, {9, 20}, {9, 21}, {9, 22}, {9, 25},
            {9, 26}, {9, 27}, {9, 29}, {\
                9, 30
            },
            {10, 11}, {10, 12}, {10, 13}, {10, 18}, {10, 20}, {10, 23}, {\
                10, 24
            },
            {10, 26}, {10, 28}, {10, 30}, {11, 13}, {11, 15}, {11, 20}, {\
                11, 22
            },
            {11, 23}, {11, 25}, {11, 26}, {11, 27}, {11, 29}, {12, 14}, {\
                12, 15
            },
            {12, 24}, {12, 25}, {12, 30}, {13, 15}, {13, 18}, {13, 19}, {\
                13, 21
            },
            {13, 25}, {13, 28}, {13, 29}, {13, 30}, {14, 16}, {14, 18}, {\
                14, 22
            },
            {14, 25}, {14, 29}, {14, 30}, {15, 17}, {15, 18}, {15, 20}, {\
                15, 25
            },
            {15, 26}, {15, 27}, {15, 28}, {15, 30}, {16, 17}, {16, 19}, {\
                16, 20
            },
            {16, 21}, {16, 22}, {16, 24}, {16, 29}, {17, 19}, {17, 21}, {\
                17, 23
            },
            {17, 25}, {17, 27}, {17, 28}, {17, 30}, {18, 20}, {18, 22}, {\
                18, 23
            },
            {18, 24}, {18, 25}, {18, 27}, {18, 28}, {19, 20}, {19, 21}, {\
                19, 22
            },
            {19, 24}, {19, 25}, {19, 26}, {19, 30}, {20, 21}, {20, 23}, {\
                20, 24
            },
            {20, 26}, {20, 28}, {20, 29}, {20, 30}, {21, 22}, {21, 24}, {\
                21, 26
            },
            {21, 27}, {21, 28}, {21, 30}, {22, 23}, {22, 25}, {22, 27}, {\
                22, 28
            },
            {23, 25}, {23, 27}, {23, 28}, {23, 29}, {24, 28}, {24, 29}, {\
                24, 30
            },
            {25, 26}, {25, 28}, {25, 29}, {27, 28}, {28, 29}, {28, 30}
        }
    };
    auto computed_order = kahns_algorithm(digraph);
    verify_topological_order(digraph, computed_order);
}


TEST_F(SetupTopologicalSortTesting, complex1)
{
    DirectedGraph<int> digraph{
        {
            1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19,
            20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36,
            37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53,
            54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70,
            71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87,
            88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100
        },
        {
            {1, 11}, {1, 15}, {1, 20}, {1, 22}, {1, 28}, {1, 35}, {1, 38}, {
                1, 45
            },
            {1, 48}, {1, 51}, {1, 67}, {1, 71}, {1, 73}, {1, 75}, {
                1, 78
            },
            {1, 82}, {1, 86}, {1, 92}, {1, 98}, {2, 5}, {2, 7}, {2, 10}, {
                2, 11
            },
            {2, 15}, {2, 26}, {2, 34}, {2, 36}, {2, 38}, {2, 39}, {
                2, 41
            },
            {2, 47}, {2, 51}, {2, 59}, {2, 66}, {2, 70}, {2, 77}, {
                2, 79
            },
            {2, 82}, {2, 84}, {2, 88}, {2, 93}, {2, 97}, {2, 98}, {
                3, 10
            },
            {3, 17}, {3, 28}, {3, 30}, {3, 31}, {3, 39}, {3, 42}, {
                3, 49
            },
            {3, 50}, {3, 53}, {3, 57}, {3, 66}, {3, 74}, {3, 77}, {
                3, 81
            },
            {3, 95}, {4, 5}, {4, 10}, {4, 11}, {4, 13}, {4, 14}, {
                4, 22
            },
            {4, 28}, {4, 34}, {4, 37}, {4, 41}, {4, 42}, {4, 44}, {
                4, 46
            },
            {4, 47}, {4, 64}, {4, 70}, {4, 71}, {4, 72}, {4, 75}, {
                4, 76
            },
            {4, 80}, {4, 81}, {4, 86}, {4, 89}, {4, 90}, {4, 91}, {
                4, 97
            },
            {4, 100}, {5, 9}, {5, 21}, {5, 28}, {5, 30}, {5, 31}, {
                5, 35
            },
            {5, 42}, {5, 52}, {5, 56}, {5, 57}, {5, 59}, {5, 60}, {
                5, 61
            },
            {5, 64}, {5, 66}, {5, 73}, {5, 75}, {5, 83}, {5, 88}, {
                5, 92
            },
            {6, 9}, {6, 12}, {6, 17}, {6, 20}, {6, 23}, {6, 25}, {
                6, 26
            },
            {6, 28}, {6, 29}, {6, 33}, {6, 35}, {6, 40}, {6, 45}, {
                6, 61
            },
            {6, 69}, {6, 71}, {6, 74}, {6, 79}, {6, 80}, {6, 83}, {
                6, 84
            },
            {6, 88}, {6, 94}, {6, 96}, {7, 8}, {7, 15}, {7, 16}, {
                7, 23
            },
            {7, 26}, {7, 27}, {7, 31}, {7, 44}, {7, 48}, {7, 52}, {
                7, 53
            },
            {7, 62}, {7, 64}, {7, 66}, {7, 75}, {7, 76}, {7, 79}, {
                7, 89
            },
            {7, 93}, {7, 95}, {7, 98}, {7, 99}, {8, 13}, {8, 22}, {
                8, 25
            },
            {8, 30}, {8, 32}, {8, 34}, {8, 35}, {8, 37}, {8, 39}, {
                8, 45
            },
            {8, 47}, {8, 63}, {8, 68}, {8, 87}, {8, 97}, {9, 14}, {
                9, 15
            },
            {9, 17}, {9, 23}, {9, 25}, {9, 26}, {9, 27}, {9, 32}, {
                9, 33
            },
            {9, 38}, {9, 39}, {9, 45}, {9, 46}, {9, 48}, {9, 69}, {
                9, 71
            },
            {9, 74}, {9, 79}, {9, 83}, {10, 31}, {10, 34}, {10, 35}, {
                10, 36
            },
            {10, 42}, {10, 61}, {10, 63}, {10, 73}, {10, 78}, {10, 81}, {
                10, 90
            },
            {10, 97}, {11, 13}, {11, 19}, {11, 21}, {11, 26}, {
                11, 33
            },
            {11, 39}, {11, 40}, {11, 44}, {11, 52}, {11, 55}, {11, 59}, {
                11, 61
            },
            {11, 62}, {11, 63}, {11, 64}, {11, 66}, {11, 73}, {
                11, 74
            },
            {11, 87}, {11, 91}, {12, 16}, {12, 17}, {12, 23}, {12, 33}, {
                12, 37
            },
            {12, 40}, {12, 62}, {12, 65}, {12, 70}, {12, 74}, {
                12, 86
            },
            {13, 16}, {13, 20}, {13, 23}, {13, 24}, {13, 26}, {13, 27}, {
                13, 38
            },
            {13, 39}, {13, 44}, {13, 45}, {13, 53}, {13, 54}, {
                13, 55
            },
            {13, 61}, {13, 62}, {13, 64}, {13, 66}, {13, 67}, {13, 70}, {
                13, 73
            },
            {13, 75}, {13, 79}, {13, 93}, {13, 100}, {14, 15}, {
                14, 26
            },
            {14, 27}, {14, 40}, {14, 45}, {14, 48}, {14, 54}, {14, 56}, {
                14, 66
            },
            {14, 69}, {14, 71}, {14, 73}, {14, 77}, {14, 81}, {
                14, 82
            },
            {14, 85}, {15, 21}, {15, 23}, {15, 26}, {15, 28}, {15, 30}, {
                15, 43
            },
            {15, 45}, {15, 54}, {15, 55}, {15, 70}, {15, 73}, {
                15, 76
            },
            {15, 79}, {15, 81}, {15, 82}, {15, 92}, {15, 96}, {15, 98}, {
                15, 99
            },
            {16, 19}, {16, 32}, {16, 34}, {16, 35}, {16, 37}, {
                16, 42
            },
            {16, 47}, {16, 48}, {16, 53}, {16, 60}, {16, 63}, {16, 68}, {
                16, 70
            },
            {16, 80}, {16, 92}, {16, 96}, {17, 22}, {17, 24}, {
                17, 27
            },
            {17, 35}, {17, 42}, {17, 44}, {17, 48}, {17, 49}, {17, 50}, {
                17, 70
            },
            {17, 76}, {17, 79}, {17, 82}, {18, 19}, {18, 24}, {
                18, 27
            },
            {18, 36}, {18, 39}, {18, 41}, {18, 44}, {18, 45}, {18, 49}, {
                18, 55
            },
            {18, 59}, {18, 66}, {18, 72}, {18, 80}, {18, 83}, {
                18, 87
            },
            {18, 97}, {19, 36}, {19, 40}, {19, 54}, {19, 58}, {19, 64}, {
                19, 69
            },
            {19, 71}, {19, 73}, {19, 74}, {19, 82}, {19, 95}, {
                19, 99
            },
            {19, 100}, {20, 26}, {20, 29}, {20, 30}, {20, 33}, {
                20, 39
            },
            {20, 41}, {20, 54}, {20, 74}, {20, 77}, {20, 83}, {20, 85}, {
                20, 92
            },
            {20, 95}, {20, 98}, {21, 34}, {21, 35}, {21, 45}, {
                21, 51
            },
            {21, 56}, {21, 61}, {21, 69}, {21, 87}, {21, 93}, {
                21, 100
            },
            {22, 23}, {22, 27}, {22, 31}, {22, 39}, {22, 46}, {
                22, 54
            },
            {22, 62}, {22, 63}, {22, 65}, {22, 70}, {22, 73}, {22, 76}, {
                22, 78
            },
            {22, 98}, {22, 99}, {23, 25}, {23, 31}, {23, 42}, {
                23, 50
            },
            {23, 54}, {23, 61}, {23, 63}, {23, 69}, {23, 74}, {23, 82}, {
                23, 92
            },
            {23, 93}, {23, 99}, {23, 100}, {24, 38}, {24, 42}, {
                24, 51
            },
            {24, 71}, {24, 86}, {24, 87}, {24, 90}, {24, 91}, {24, 93}, {
                25, 29
            },
            {25, 42}, {25, 47}, {25, 53}, {25, 58}, {25, 64}, {
                25, 68
            },
            {25, 72}, {25, 75}, {25, 77}, {25, 79}, {25, 80}, {25, 86}, {
                25, 94
            },
            {25, 95}, {26, 32}, {26, 35}, {26, 36}, {26, 38}, {
                26, 39
            },
            {26, 45}, {26, 46}, {26, 49}, {26, 55}, {26, 61}, {26, 64}, {
                26, 76
            },
            {26, 80}, {26, 81}, {26, 84}, {26, 85}, {26, 89}, {
                26, 90
            },
            {26, 94}, {27, 32}, {27, 34}, {27, 37}, {27, 38}, {27, 44}, {
                27, 45
            },
            {27, 57}, {27, 58}, {27, 66}, {27, 69}, {27, 71}, {
                27, 80
            },
            {27, 92}, {27, 97}, {28, 32}, {28, 42}, {28, 54}, {28, 55}, {
                28, 57
            },
            {28, 58}, {28, 60}, {28, 62}, {28, 77}, {28, 78}, {
                28, 79
            },
            {28, 80}, {28, 83}, {28, 84}, {28, 88}, {28, 97}, {28, 98}, {
                28, 100
            },
            {29, 31}, {29, 43}, {29, 49}, {29, 50}, {29, 52}, {
                29, 53
            },
            {29, 69}, {29, 73}, {29, 83}, {29, 87}, {29, 88}, {29, 98}, {
                30, 44
            },
            {30, 46}, {30, 52}, {30, 61}, {30, 73}, {30, 74}, {
                30, 80
            },
            {30, 90}, {30, 94}, {31, 33}, {31, 34}, {31, 39}, {31, 44}, {
                31, 46
            },
            {31, 48}, {31, 71}, {31, 76}, {31, 80}, {31, 83}, {
                31, 95
            },
            {31, 99}, {31, 100}, {32, 45}, {32, 47}, {32, 50}, {
                32, 51
            },
            {32, 57}, {32, 59}, {32, 67}, {32, 70}, {32, 71}, {32, 73}, {
                32, 75
            },
            {32, 78}, {32, 84}, {32, 88}, {32, 92}, {32, 95}, {
                32, 100
            },
            {33, 40}, {33, 45}, {33, 47}, {33, 51}, {33, 53}, {
                33, 54
            },
            {33, 59}, {33, 62}, {33, 70}, {33, 75}, {33, 78}, {33, 85}, {
                33, 91
            },
            {33, 93}, {33, 96}, {34, 41}, {34, 46}, {34, 49}, {
                34, 51
            },
            {34, 52}, {34, 53}, {34, 62}, {34, 65}, {34, 87}, {34, 94}, {
                35, 38
            },
            {35, 41}, {35, 42}, {35, 59}, {35, 63}, {35, 68}, {
                35, 74
            },
            {36, 39}, {36, 40}, {36, 41}, {36, 45}, {36, 49}, {36, 51}, {
                36, 57
            },
            {36, 73}, {36, 76}, {36, 77}, {36, 89}, {36, 98}, {
                36, 99
            },
            {36, 100}, {37, 38}, {37, 41}, {37, 43}, {37, 44}, {
                37, 47
            },
            {37, 57}, {37, 61}, {37, 66}, {37, 67}, {37, 72}, {37, 76}, {
                37, 77
            },
            {37, 80}, {37, 82}, {37, 93}, {37, 99}, {38, 42}, {
                38, 49
            },
            {38, 50}, {38, 59}, {38, 69}, {38, 70}, {38, 75}, {38, 81}, {
                38, 84
            },
            {38, 86}, {38, 89}, {38, 90}, {38, 91}, {38, 92}, {
                38, 95
            },
            {38, 96}, {38, 99}, {39, 44}, {39, 48}, {39, 50}, {39, 51}, {
                39, 54
            },
            {39, 56}, {39, 71}, {39, 75}, {39, 76}, {39, 87}, {
                39, 93
            },
            {39, 94}, {39, 98}, {40, 45}, {40, 47}, {40, 52}, {40, 56}, {
                40, 60
            },
            {40, 62}, {40, 79}, {40, 80}, {40, 84}, {40, 95}, {
                40, 100
            },
            {41, 42}, {41, 51}, {41, 55}, {41, 57}, {41, 64}, {
                41, 65
            },
            {41, 67}, {41, 77}, {41, 85}, {41, 91}, {41, 94}, {42, 46}, {
                42, 47
            },
            {42, 54}, {42, 57}, {42, 62}, {42, 84}, {42, 88}, {
                42, 90
            },
            {42, 91}, {42, 97}, {42, 99}, {43, 44}, {43, 55}, {43, 56}, {
                43, 59
            },
            {43, 66}, {43, 86}, {43, 99}, {43, 100}, {44, 47}, {
                44, 53
            },
            {44, 57}, {44, 60}, {44, 62}, {44, 67}, {44, 78}, {44, 84}, {
                44, 89
            },
            {44, 92}, {45, 46}, {45, 47}, {45, 48}, {45, 54}, {
                45, 69
            },
            {45, 70}, {45, 72}, {45, 83}, {45, 92}, {45, 94}, {45, 96}, {
                45, 100
            },
            {46, 53}, {46, 54}, {46, 57}, {46, 64}, {46, 67}, {
                46, 69
            },
            {46, 72}, {46, 75}, {46, 84}, {46, 87}, {46, 89}, {46, 94}, {
                46, 96
            },
            {46, 99}, {47, 50}, {47, 54}, {47, 58}, {47, 66}, {
                47, 68
            },
            {47, 78}, {47, 80}, {47, 84}, {47, 89}, {47, 93}, {47, 96}, {
                47, 99
            },
            {48, 49}, {48, 51}, {48, 53}, {48, 54}, {48, 67}, {
                48, 70
            },
            {48, 71}, {48, 73}, {48, 75}, {48, 78}, {48, 82}, {48, 84}, {
                49, 51
            },
            {49, 65}, {49, 70}, {49, 72}, {49, 73}, {49, 74}, {
                49, 79
            },
            {49, 81}, {49, 84}, {49, 85}, {49, 86}, {49, 96}, {50, 51}, {
                50, 53
            },
            {50, 58}, {50, 59}, {50, 62}, {50, 69}, {50, 72}, {
                50, 79
            },
            {50, 89}, {50, 90}, {50, 93}, {50, 96}, {51, 54}, {51, 62}, {
                51, 65
            },
            {51, 67}, {51, 75}, {51, 76}, {51, 83}, {51, 89}, {
                51, 91
            },
            {51, 94}, {51, 98}, {51, 100}, {52, 54}, {52, 56}, {
                52, 58
            },
            {52, 63}, {52, 65}, {52, 66}, {52, 70}, {52, 71}, {52, 77}, {
                52, 79
            },
            {52, 80}, {52, 81}, {52, 82}, {52, 85}, {52, 93}, {
                52, 96
            },
            {52, 97}, {52, 98}, {53, 54}, {53, 56}, {53, 70}, {53, 81}, {
                53, 87
            },
            {53, 92}, {53, 93}, {54, 58}, {54, 62}, {54, 63}, {
                54, 77
            },
            {54, 79}, {54, 80}, {54, 94}, {54, 98}, {55, 56}, {55, 58}, {
                55, 61
            },
            {55, 64}, {55, 66}, {55, 69}, {55, 73}, {55, 74}, {
                55, 84
            },
            {55, 91}, {55, 93}, {55, 97}, {55, 98}, {56, 58}, {56, 59}, {
                56, 60
            },
            {56, 65}, {56, 99}, {57, 59}, {57, 61}, {57, 74}, {
                57, 75
            },
            {57, 76}, {57, 81}, {57, 84}, {57, 87}, {57, 89}, {57, 95}, {
                58, 65
            },
            {58, 67}, {58, 70}, {58, 72}, {58, 82}, {58, 83}, {
                58, 94
            },
            {59, 71}, {59, 73}, {59, 75}, {59, 83}, {59, 94}, {60, 70}, {
                60, 73
            },
            {60, 84}, {60, 87}, {60, 88}, {60, 92}, {60, 95}, {
                60, 97
            },
            {60, 100}, {61, 62}, {61, 65}, {61, 77}, {61, 83}, {
                61, 84
            },
            {61, 92}, {62, 63}, {62, 66}, {62, 76}, {62, 82}, {62, 83}, {
                62, 84
            },
            {62, 89}, {62, 90}, {62, 93}, {62, 94}, {63, 75}, {
                63, 80
            },
            {63, 81}, {63, 87}, {63, 94}, {63, 95}, {63, 97}, {64, 71}, {
                64, 72
            },
            {64, 78}, {64, 83}, {64, 87}, {64, 94}, {64, 99}, {
                65, 70
            },
            {65, 72}, {65, 80}, {65, 81}, {65, 82}, {65, 90}, {65, 95}, {
                66, 68
            },
            {66, 75}, {66, 87}, {66, 90}, {67, 69}, {67, 73}, {
                67, 90
            },
            {67, 96}, {68, 71}, {68, 78}, {68, 80}, {68, 84}, {68, 91}, {
                68, 93
            },
            {68, 99}, {69, 74}, {69, 78}, {69, 84}, {69, 89}, {
                69, 100
            },
            {70, 72}, {70, 77}, {70, 78}, {70, 81}, {70, 83}, {
                70, 88
            },
            {70, 89}, {70, 93}, {70, 95}, {70, 96}, {71, 75}, {71, 89}, {
                71, 90
            },
            {71, 91}, {71, 94}, {72, 79}, {72, 84}, {72, 87}, {
                72, 95
            },
            {72, 98}, {73, 77}, {73, 79}, {73, 88}, {73, 89}, {73, 97}, {
                74, 76
            },
            {74, 77}, {74, 82}, {74, 84}, {74, 95}, {74, 96}, {
                74, 97
            },
            {75, 79}, {75, 83}, {75, 95}, {75, 98}, {76, 77}, {76, 80}, {
                76, 84
            },
            {76, 87}, {76, 89}, {76, 94}, {76, 96}, {76, 100}, {
                77, 86
            },
            {77, 93}, {77, 96}, {77, 98}, {78, 80}, {78, 85}, {78, 90}, {
                78, 95
            },
            {78, 100}, {79, 81}, {79, 82}, {79, 89}, {79, 96}, {
                79, 100
            },
            {80, 81}, {80, 94}, {80, 97}, {81, 82}, {81, 85}, {
                81, 90
            },
            {81, 91}, {82, 92}, {83, 84}, {83, 87}, {83, 88}, {83, 96}, {
                83, 97
            },
            {83, 99}, {83, 100}, {84, 86}, {84, 91}, {84, 95}, {
                84, 99
            },
            {85, 88}, {85, 94}, {85, 95}, {86, 89}, {86, 93}, {86, 95}, {
                87, 93
            },
            {88, 90}, {88, 93}, {88, 94}, {89, 96}, {90, 94}, {
                90, 99
            },
            {90, 100}, {91, 99}, {92, 99}, {93, 97}, {95, 97}, {
                95, 98
            }
        }
    };
    auto computed_order = kahns_algorithm(digraph);
    // for (const auto& elem : computed_order) {
    //     std::cout << elem << " ";
    // }
    // std::cout << std::endl;
    verify_topological_order(digraph, computed_order);
}
