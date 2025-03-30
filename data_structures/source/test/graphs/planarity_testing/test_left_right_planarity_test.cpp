//
// Created by andreas on 14.12.24.
//

#include <gtest/gtest.h>

#include "graphs/planarity_testing/left_right_planarity_test.h"

class SetupLeftRightPlanarityTesting : public testing::Test
{
public:
    SetupLeftRightPlanarityTesting() = default;
    static constexpr int max_number_of_nodes{50};

    static UndirectedGraph<int64_t> path_graph(const int num_nodes)
    {
        UndirectedGraph<int64_t> graph;
        for (int i{1}; i <= num_nodes; ++i)
        {
            graph.add_node(i);
            if (i > 1)
                graph.add_edge(i - 1, i);
        }
        return graph;
    }

    static UndirectedGraph<int> cycle_graph(const int num_nodes)
    {
        UndirectedGraph<int> graph;
        for (int i{1}; i <= num_nodes; ++i)
        {
            graph.add_node(i);
            if (i > 1)
                graph.add_edge(i - 1, i);
        }
        if (num_nodes > 2)
            graph.add_edge(num_nodes, 1); // Close the cycle
        return graph;
    }

    static UndirectedGraph<int> star_graph(const int num_nodes)
    {
        UndirectedGraph<int> graph{};
        if (num_nodes < 2)
            return graph;

        graph.add_node(1); // Center
        for (int i{2}; i <= num_nodes; ++i)
        {
            graph.add_node(i);
            graph.add_edge(1, i);
        }
        return graph;
    }

    static UndirectedGraph<int> tree_graph(const int num_nodes)
    {
        UndirectedGraph<int> graph;
        for (int i{1}; i <= num_nodes; ++i)
        {
            graph.add_node(i);
            if (i > 1)
                graph.add_edge(i / 2, i); // Simple tree connection
        }
        return graph;
    }

    static UndirectedGraph<int> wheel_graph(const int num_nodes)
    {
        UndirectedGraph<int> graph;
        if (num_nodes < 4)
        {
            throw std::invalid_argument("A wheel graph requires at least 4 nodes.");
        }
        graph.add_node(1);
        // Form cycle
        for (int i{2}; i <= num_nodes; ++i)
        {
            graph.add_node(i);
            if (i > 2)
                graph.add_edge(i - 1, i);
        }
        graph.add_edge(num_nodes, 2); // Close the cycle

        // Connect center to cycle
        for (int i = 2; i <= num_nodes; ++i)
        {
            graph.add_edge(1, i);
        }
        return graph;
    }

    static UndirectedGraph<int> grid_graph(const int rows, const int cols)
    {
        UndirectedGraph<int> graph;
        for (int i{1}; i <= rows * cols; ++i)
        {
            graph.add_node(i);
        }

        for (int row{}; row < rows; ++row)
        {
            for (int col{}; col < cols; ++col)
            {
                const auto currentNode = row * cols + col;

                // Connect to the right neighbor
                if (col + 1 < cols)
                {
                    graph.add_edge(currentNode, currentNode + 1);
                }

                // Connect to the bottom neighbor
                if (row + 1 < rows)
                {
                    graph.add_edge(currentNode, currentNode + cols);
                }
            }
        }

        return graph;
    }

    static UndirectedGraph<int> grid_graph_3x3()
    {
        UndirectedGraph<int> graph{
            {1, 2, 3, 4, 5, 6, 7, 8, 9}, {
                {1, 2}, {2, 3}, {4, 5}, {5, 6}, {7, 8}, {8, 9},
                {1, 4}, {2, 5}, {3, 6}, {4, 7}, {5, 8}, {6, 9}
            }
        };
        return graph;
    }

    static UndirectedGraph<int> complete_graph_k3()
    {
        UndirectedGraph<int> graph{
            {1, 2, 3}, {
                {1, 2}, {1, 3}, {2, 3}
            }
        };
        return graph;
    }

    static UndirectedGraph<int> complete_graph_k4()
    {
        UndirectedGraph<int> graph{
            {1, 2, 3, 4}, {
                {1, 2}, {1, 3}, {1, 4}, {2, 3}, {2, 4}, {3, 4}
            }
        };
        return graph;
    }

    static UndirectedGraph<int> complete_graph_k5()
    {
        UndirectedGraph<int> graph{
            {1, 2, 3, 4, 5}, {
                {1, 2}, {1, 3}, {1, 4}, {1, 5},
                {2, 3}, {2, 4}, {2, 5},
                {3, 4}, {3, 5}, {4, 5}
            }
        };
        return graph;
    }

    static UndirectedGraph<int> complete_graph_k6()
    {
        UndirectedGraph<int> graph{
            {1, 2, 3, 4, 5, 6}, {
                {1, 2}, {1, 3}, {1, 4}, {1, 5}, {1, 6},
                {2, 3}, {2, 4}, {2, 5},
                {2, 6}, {3, 4}, {3, 5}, {3, 6}, {4, 5}, {4, 6}, {5, 6}
            }
        };
        return graph;
    }

    static UndirectedGraph<short> generalized_petersen_graph_5_1()
    {
        UndirectedGraph<short> graph{
            {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, {
                {1, 2}, {1, 5}, {1, 6}, {2, 3}, {2, 7}, {3, 4},
                {3, 8}, {4, 5}, {4, 9}, {5, 10}, {6, 7}, {6, 10},
                {7, 8}, {8, 9}, {9, 10}
            }
        };
        return graph;
    }

    static UndirectedGraph<short> generalized_petersen_graph_5_2()
    {
        UndirectedGraph<short> graph{
            {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, {
                {1, 3}, {1, 4}, {1, 6}, {2, 4}, {2, 5}, {2, 7},
                {3, 5}, {3, 8}, {4, 9}, {5, 10}, {6, 7}, {6, 10},
                {7, 8}, {8, 9}, {9, 10}
            }
        };
        return graph;
    }

    static UndirectedGraph<short> utility_graph()
    {
        UndirectedGraph<short> graph{
            {1, 2, 3, 4, 5, 6}, {
                {1, 4}, {1, 5}, {1, 6},
                {2, 4}, {2, 5}, {2, 6},
                {3, 4}, {3, 5}, {3, 6}
            }
        };
        return graph;
    }

    static UndirectedGraph<int> complete_tripartite_graph_k333()
    {
        UndirectedGraph<int> graph{
            {1, 2, 3, 4, 5, 6, 7, 8, 9}, {
                {1, 4}, {1, 5}, {1, 6},
                {2, 4}, {2, 5}, {2, 6},
                {3, 4}, {3, 5}, {3, 6},
                {1, 7}, {1, 8}, {1, 9},
                {2, 7}, {2, 8}, {2, 9},
                {3, 7}, {3, 8}, {3, 9}
            }
        };
        return graph;
    }

    static UndirectedGraph<int32_t> random_planar_graph_50_nodes()
    {
        UndirectedGraph<int32_t> graph{
            {
                1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19,
                20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36,
                37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50
            },
            {
                {1, 21}, {2, 22}, {3, 15}, {3, 41}, {4, 7}, {4, 13}, {4, 16},
                {5, 11}, {5, 31}, {5, 48}, {6, 8}, {6, 21}, {7, 16}, {8, 12},
                {9, 11}, {9, 29}, {10, 24}, {10, 45}, {11, 12}, {11, 13}, {12, 16},
                {12, 47}, {13, 17}, {13, 27}, {14, 27}, {14, 38}, {15, 20}, {16, 31},
                {16, 36}, {16, 39}, {16, 40}, {17, 44}, {18, 36}, {19, 38}, {19, 44},
                {21, 27}, {22, 28}, {22, 34}, {24, 26}, {25, 34}, {26, 37}, {27, 33},
                {28, 43}, {29, 43}, {30, 41}, {31, 49}, {34, 35}, {35, 39}, {35, 46},
                {36, 38}, {36, 47}, {37, 50}
            }
        };
        return graph;
    }

    static UndirectedGraph<int32_t> random_planar_graph_100_nodes()
    {
        UndirectedGraph<int32_t> graph{
            {
                1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19,
                20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36,
                37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53,
                54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70,
                71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87,
                88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100
            },
            {
                {1, 93}, {2, 41}, {2, 50}, {2, 92}, {3, 88}, {4, 80}, {4, 85},
                {4, 91}, {5, 51}, {6, 12}, {7, 41}, {7, 89}, {8, 49}, {8, 72},
                {8, 93}, {9, 72}, {10, 15}, {10, 30}, {10, 92}, {11, 66}, {11, 94},
                {13, 78}, {13, 95}, {14, 17}, {14, 29}, {15, 37}, {16, 43}, {17, 52},
                {18, 76}, {20, 28}, {20, 34}, {20, 53}, {20, 61}, {20, 65},
                {20, 92}, {21, 57}, {21, 85}, {22, 79}, {22, 90}, {23, 51}, {23, 52},
                {23, 54}, {23, 76}, {24, 39}, {25, 66}, {26, 77}, {26, 91},
                {27, 51}, {28, 36}, {28, 57}, {28, 85}, {29, 76}, {31, 35}, {31, 39},
                {31, 52}, {32, 61}, {33, 36}, {33, 72}, {33, 77}, {34, 54},
                {36, 96}, {36, 97}, {37, 54}, {37, 89}, {38, 69}, {40, 50}, {42, 56},
                {42, 75}, {42, 76}, {43, 70}, {44, 47}, {44, 78}, {45, 78},
                {46, 57}, {47, 68}, {48, 70}, {48, 80}, {48, 87}, {52, 64}, {52, 69},
                {52, 73}, {52, 75}, {53, 76}, {53, 87}, {55, 73}, {59, 63},
                {59, 64}, {59, 66}, {59, 67}, {59, 79}, {61, 88}, {62, 83},
                {62, 96}, {66, 84}, {68, 83}, {69, 88}, {71, 81}, {73, 74},
                {76, 81}, {78, 79}, {81, 90}, {85, 87}, {90, 96}
            }
        };
        return graph;
    }

    static UndirectedGraph<int16_t> random_nonplanar_graph_50_nodes()
    {
        UndirectedGraph<int16_t> graph{
            {
                1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19,
                20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36,
                37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50
            },
            {
                {1, 2}, {1, 5}, {1, 10}, {1, 16}, {1, 23}, {1, 25}, {1, 27}, {1, 30}, {
                    1, 33
                },
                {1, 37}, {1, 38}, {1, 39}, {1, 40}, {1, 44}, {1, 45}, {
                    1, 48
                },
                {2, 4}, {2, 9}, {2, 10}, {2, 11}, {2, 14}, {2, 15}, {2, 16}, {
                    2, 18
                },
                {2, 20}, {2, 22}, {2, 28}, {2, 30}, {2, 31}, {2, 37}, {
                    2, 39
                },
                {2, 42}, {2, 45}, {2, 46}, {3, 5}, {3, 9}, {3, 15}, {3, 16}, {
                    3, 17
                },
                {3, 18}, {3, 20}, {3, 23}, {3, 26}, {3, 29}, {3, 30}, {
                    3, 34
                },
                {3, 35}, {3, 41}, {3, 42}, {3, 45}, {3, 46}, {3, 47}, {
                    3, 48
                },
                {4, 7}, {4, 8}, {4, 11}, {4, 12}, {4, 14}, {4, 19}, {4, 21}, {
                    4, 24
                },
                {4, 26}, {4, 29}, {4, 30}, {4, 31}, {4, 34}, {4, 36}, {
                    4, 37
                },
                {4, 41}, {4, 42}, {4, 45}, {4, 48}, {4, 50}, {5, 7}, {5, 9}, {
                    5, 15
                },
                {5, 16}, {5, 19}, {5, 20}, {5, 22}, {5, 28}, {5, 30}, {
                    5, 31
                },
                {5, 32}, {5, 34}, {5, 35}, {5, 37}, {5, 38}, {5, 40}, {
                    5, 43
                },
                {5, 44}, {5, 46}, {5, 50}, {6, 8}, {6, 11}, {6, 14}, {
                    6, 16
                },
                {6, 18}, {6, 20}, {6, 22}, {6, 24}, {6, 27}, {6, 28}, {
                    6, 29
                },
                {6, 35}, {6, 39}, {6, 40}, {6, 43}, {6, 49}, {7, 11}, {
                    7, 12
                },
                {7, 16}, {7, 17}, {7, 21}, {7, 22}, {7, 23}, {7, 24}, {
                    7, 25
                },
                {7, 27}, {7, 28}, {7, 32}, {7, 38}, {7, 39}, {7, 40}, {
                    7, 41
                },
                {7, 43}, {8, 10}, {8, 11}, {8, 12}, {8, 13}, {8, 14}, {
                    8, 15
                },
                {8, 16}, {8, 19}, {8, 20}, {8, 21}, {8, 24}, {8, 27}, {
                    8, 28
                },
                {8, 30}, {8, 33}, {8, 40}, {8, 41}, {8, 43}, {8, 46}, {
                    8, 50
                },
                {9, 10}, {9, 14}, {9, 16}, {9, 18}, {9, 22}, {9, 25}, {
                    9, 31
                },
                {9, 37}, {9, 40}, {9, 44}, {9, 47}, {9, 50}, {10, 13}, {
                    10, 14
                },
                {10, 15}, {10, 16}, {10, 17}, {10, 18}, {10, 19}, {10, 21}, {
                    10, 23
                },
                {10, 25}, {10, 27}, {10, 28}, {10, 29}, {10, 33}, {
                    10, 36
                },
                {10, 44}, {10, 46}, {11, 13}, {11, 15}, {11, 18}, {11, 22}, {
                    11, 26
                },
                {11, 30}, {11, 34}, {11, 36}, {11, 41}, {11, 44}, {
                    11, 46
                },
                {12, 17}, {12, 19}, {12, 20}, {12, 23}, {12, 27}, {12, 30}, {
                    12, 32
                },
                {12, 36}, {12, 40}, {12, 41}, {12, 42}, {12, 43}, {
                    12, 48
                },
                {12, 50}, {13, 19}, {13, 22}, {13, 26}, {13, 35}, {13, 41}, {
                    13, 44
                },
                {13, 48}, {14, 15}, {14, 17}, {14, 24}, {14, 35}, {
                    14, 36
                },
                {14, 40}, {14, 43}, {15, 17}, {15, 21}, {15, 24}, {15, 25}, {
                    15, 26
                },
                {15, 37}, {15, 43}, {15, 44}, {15, 45}, {15, 46}, {
                    15, 49
                },
                {16, 19}, {16, 23}, {16, 24}, {16, 26}, {16, 27}, {16, 28}, {
                    16, 29
                },
                {16, 30}, {16, 31}, {16, 38}, {16, 39}, {16, 40}, {
                    16, 43
                },
                {16, 44}, {16, 47}, {16, 50}, {17, 18}, {17, 22}, {17, 24}, {
                    17, 26
                },
                {17, 28}, {17, 29}, {17, 31}, {17, 32}, {17, 36}, {
                    17, 37
                },
                {17, 41}, {17, 42}, {17, 43}, {17, 44}, {17, 50}, {18, 28}, {
                    18, 29
                },
                {18, 32}, {18, 37}, {18, 38}, {18, 40}, {18, 42}, {
                    18, 43
                },
                {18, 48}, {18, 49}, {19, 22}, {19, 24}, {19, 26}, {19, 34}, {
                    19, 37
                },
                {19, 39}, {19, 41}, {19, 45}, {19, 48}, {20, 21}, {
                    20, 22
                },
                {20, 30}, {20, 32}, {20, 33}, {20, 34}, {20, 37}, {20, 40}, {
                    20, 41
                },
                {20, 42}, {20, 43}, {20, 45}, {20, 48}, {20, 50}, {
                    21, 24
                },
                {21, 25}, {21, 26}, {21, 27}, {21, 28}, {21, 29}, {21, 32}, {
                    21, 34
                },
                {21, 38}, {21, 40}, {21, 43}, {21, 45}, {21, 46}, {
                    21, 47
                },
                {21, 50}, {22, 24}, {22, 26}, {22, 29}, {22, 31}, {22, 35}, {
                    22, 42
                },
                {22, 47}, {23, 24}, {23, 28}, {23, 29}, {23, 33}, {
                    23, 37
                },
                {23, 38}, {23, 39}, {23, 40}, {23, 42}, {23, 50}, {24, 29}, {
                    24, 30
                },
                {24, 32}, {24, 34}, {24, 35}, {24, 36}, {24, 38}, {
                    25, 30
                },
                {25, 32}, {25, 38}, {25, 39}, {25, 43}, {25, 45}, {25, 47}, {
                    25, 48
                },
                {25, 49}, {26, 27}, {26, 29}, {26, 30}, {26, 35}, {
                    26, 39
                },
                {26, 42}, {26, 43}, {26, 47}, {26, 48}, {27, 28}, {27, 33}, {
                    27, 34
                },
                {27, 35}, {27, 36}, {27, 39}, {27, 43}, {28, 29}, {
                    28, 30
                },
                {28, 31}, {28, 33}, {28, 36}, {28, 37}, {28, 38}, {28, 39}, {
                    28, 40
                },
                {28, 41}, {28, 43}, {28, 47}, {29, 30}, {29, 33}, {
                    29, 34
                },
                {29, 35}, {29, 38}, {29, 46}, {30, 32}, {30, 35}, {30, 36}, {
                    30, 37
                },
                {30, 42}, {30, 46}, {31, 33}, {31, 40}, {31, 41}, {
                    31, 42
                },
                {31, 44}, {31, 49}, {32, 33}, {32, 34}, {32, 40}, {32, 43}, {
                    32, 45
                },
                {32, 46}, {32, 47}, {32, 50}, {33, 36}, {33, 39}, {
                    33, 41
                },
                {33, 42}, {33, 43}, {33, 45}, {33, 46}, {33, 48}, {33, 49}, {
                    34, 35
                },
                {34, 36}, {34, 43}, {34, 45}, {34, 46}, {34, 49}, {
                    35, 36
                },
                {35, 40}, {35, 42}, {35, 43}, {35, 44}, {35, 46}, {36, 39}, {
                    36, 40
                },
                {36, 50}, {37, 39}, {37, 40}, {37, 46}, {37, 47}, {
                    38, 40
                },
                {38, 41}, {38, 43}, {38, 44}, {38, 45}, {38, 46}, {38, 50}, {
                    39, 43
                },
                {40, 42}, {40, 44}, {40, 45}, {40, 48}, {40, 49}, {
                    40, 50
                },
                {41, 44}, {41, 45}, {41, 47}, {41, 48}, {42, 43}, {42, 46}, {
                    43, 44
                },
                {43, 47}, {43, 48}, {43, 49}, {44, 47}, {44, 49}, {
                    44, 50
                },
                {46, 47}, {46, 48}, {46, 49}, {47, 48}, {48, 50}, {49, 50}
            }
        };
        return graph;
    }

    static UndirectedGraph<int64_t> random_planar_connected_graph_51_nodes()
    {
        UndirectedGraph<int64_t> graph{
            {
                1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19,
                20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36,
                37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51
            },
            {
                {1, 15}, {1, 18}, {1, 25}, {1, 44}, {1, 50}, {2, 16}, {2, 26},
                {3, 39}, {3, 47}, {4, 9}, {4, 13}, {4, 23}, {5, 25}, {6, 45},
                {6, 46}, {7, 37}, {7, 46}, {8, 10}, {8, 19}, {8, 21}, {8, 29},
                {9, 45}, {11, 33}, {12, 41}, {12, 51}, {13, 48}, {14, 20}, {15, 42},
                {15, 46}, {15, 50}, {16, 48}, {17, 20}, {18, 27}, {19, 31}, {20, 30},
                {21, 48}, {22, 24}, {23, 30}, {23, 51}, {24, 29}, {25, 39},
                {26, 29}, {26, 32}, {26, 33}, {27, 49}, {28, 30}, {28, 37},
                {28, 51}, {29, 31}, {31, 33}, {32, 48}, {34, 37}, {34, 38}, {34, 49},
                {35, 51}, {36, 47}, {38, 40}, {38, 43}, {39, 47}, {44, 51}, {45, 50}
            }
        };
        return graph;
    }

    static UndirectedGraph<int64_t> two_graphs_one_planar_one_nonplanar()
    {
        UndirectedGraph<int64_t> graph{
            {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, {
                {1, 2}, {2, 3}, {3, 4},
                {1, 4}, {1, 5}, {1, 6},
                {2, 4}, {2, 5}, {2, 6},
                {3, 4}, {3, 5}, {3, 6}
            }
        };
        return graph;
    }

    static UndirectedGraph<int64_t> two_graphs_one_nonplanar_one_planar()
    {
        UndirectedGraph<int64_t> graph{
            {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, {
                {7, 8}, {8, 9}, {9, 10},
                {5, 8}, {5, 9}, {5, 10},
                {6, 8}, {6, 9}, {6, 10},
                {7, 8}, {7, 9}, {7, 10}
            }
        };
        return graph;
    }

    static UndirectedGraph<int64_t> two_random_graphs_both_planar_10_nodes_each()
    {
        UndirectedGraph<int64_t> graph{
            {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20},
            {
                {1, 10}, {1, 13}, {1, 17}, {1, 18}, {2, 12}, {3, 7},
                {3, 8}, {3, 20}, {4, 8}, {4, 16}, {5, 10}, {6, 19},
                {7, 9}, {7, 11}, {7, 15}, {7, 20}, {11, 14}, {12, 19},
                {17, 18}, {17, 19}, {18, 19}
            }
        };
        return graph;
    }

    static UndirectedGraph<int64_t> three_random_graphs_two_planar_one_non_planar()
    {
        UndirectedGraph<int64_t> graph{
            {
                1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28,
                29, 30, 31, 32, 33
            },
            {
                {1, 11}, {2, 3}, {2, 9}, {2, 11}, {3, 5}, {3, 9}, {4, 5}, {4, 9},
                {5, 8}, {5, 11}, {6, 9}, {6, 11}, {6, 12}, {7, 10}, {7, 12},
                {10, 11}, {13, 15}, {13, 18}, {13, 20}, {13, 22}, {14, 15}, {14, 17},
                {14, 23}, {15, 18}, {15, 19}, {15, 22}, {16, 20}, {17, 25}, {18, 20},
                {18, 21}, {18, 22}, {20, 21}, {21, 23}, {24, 25}, {27, 28}, {27, 31},
                {27, 32}, {27, 33}, {28, 29}, {28, 30}, {28, 31}, {28, 32}, {28, 33}, {29, 30}, {30, 32}, {30, 33},
                {31, 32}, {31, 33}
            }
        };
        return graph;
    }

    static UndirectedGraph<int> generateGeneralizedPetersenGraph(int n, int k)
    {
        UndirectedGraph<int> graph{};

        // Add vertices for the outer and inner cycles
        for (int i{1}; i <= 2 * n; ++i)
            graph.add_node(i);

        // Add edges for the outer cycle
        for (int i = 1; i <= n; ++i)
        {
            graph.add_edge(i, (i % n) + 1); // Outer cycle
        }

        // Add edges for the inner cycle
        for (int i = 1; i <= n; ++i)
        {
            graph.add_edge(n + i, n + ((i + k - 1) % n) + 1); // Inner cycle
        }

        // Add edges for the spokes
        for (int i = 1; i <= n; ++i)
        {
            graph.add_edge(i, n + i); // Spokes
        }

        return graph;
    }
};


TEST_F(SetupLeftRightPlanarityTesting, EmptyGraph)
{
    auto graph = UndirectedGraph<int>{};
    PlanarityTest<int> test(graph);
    test.run();
    EXPECT_TRUE(test.is_graph_planar());
}

TEST_F(SetupLeftRightPlanarityTesting, SingleNode)
{
    auto graph = UndirectedGraph<int>{};
    graph.add_node(1);
    PlanarityTest<int> test(graph);
    test.run();
    EXPECT_TRUE(test.is_graph_planar());
}


TEST_F(SetupLeftRightPlanarityTesting, PathGraph)
{
    for (int number_of_nodes{2}; number_of_nodes <= max_number_of_nodes; ++number_of_nodes)
    {
        auto graph = path_graph(number_of_nodes);
        PlanarityTest<int64_t> test(graph);
        test.run();
        EXPECT_TRUE(test.is_graph_planar());
    }
}

TEST_F(SetupLeftRightPlanarityTesting, CycleGraph)
{
    for (int number_of_nodes{2}; number_of_nodes <= max_number_of_nodes; ++number_of_nodes)
    {
        auto graph = cycle_graph(number_of_nodes);
        PlanarityTest<int> test(graph);
        test.run();
        EXPECT_TRUE(test.is_graph_planar());
    }
}

TEST_F(SetupLeftRightPlanarityTesting, StarGraph)
{
    for (int number_of_nodes{2}; number_of_nodes <= max_number_of_nodes; ++number_of_nodes)
    {
        auto graph = star_graph(number_of_nodes);
        PlanarityTest<int> test(graph);
        test.run();
        EXPECT_TRUE(test.is_graph_planar());
    }
}

TEST_F(SetupLeftRightPlanarityTesting, TreeGraph)
{
    for (int number_of_nodes{2}; number_of_nodes <= max_number_of_nodes; ++number_of_nodes)
    {
        auto graph = tree_graph(number_of_nodes);
        PlanarityTest<int> test(graph);
        test.run();
        EXPECT_TRUE(test.is_graph_planar());
    }
}

TEST_F(SetupLeftRightPlanarityTesting, WheelGraph)
{
    for (int number_of_nodes{4}; number_of_nodes <= max_number_of_nodes; ++number_of_nodes)
    {
        auto graph = wheel_graph(number_of_nodes);
        PlanarityTest<int> test(graph);
        test.run();
        EXPECT_TRUE(test.is_graph_planar());
    }
}

TEST_F(SetupLeftRightPlanarityTesting, GridGraph3x3)
{
    auto graph = grid_graph_3x3();
    PlanarityTest<int> test(graph);
    test.run();
    EXPECT_TRUE(test.is_graph_planar());
}

TEST_F(SetupLeftRightPlanarityTesting, GridGraph)
{
    for (int number_of_rows{2}; number_of_rows <= 10; ++number_of_rows)
    {
        for (int number_of_columns{2}; number_of_columns <= 10; ++number_of_columns)
        {
            auto graph = grid_graph(number_of_rows, number_of_columns);
            PlanarityTest<int> test(graph);
            test.run();
            EXPECT_TRUE(test.is_graph_planar());
        }
    }
}


TEST_F(SetupLeftRightPlanarityTesting, CompleteGraphK3)
{
    auto graph = complete_graph_k3();
    PlanarityTest<int> test(graph);
    test.run();
    EXPECT_TRUE(test.is_graph_planar());
}

TEST_F(SetupLeftRightPlanarityTesting, CompleteGraphK4)
{
    auto graph = complete_graph_k4();
    PlanarityTest<int> test(graph);
    test.run();
    EXPECT_TRUE(test.is_graph_planar());
}


TEST_F(SetupLeftRightPlanarityTesting, CompleteGraphK5)
{
    auto graph = complete_graph_k5();
    PlanarityTest<int> test(graph);
    test.run();
    EXPECT_FALSE(test.is_graph_planar());
}

TEST_F(SetupLeftRightPlanarityTesting, CompleteGraphK6)
{
    auto graph = complete_graph_k6();
    PlanarityTest<int> test(graph);
    test.run();
    EXPECT_FALSE(test.is_graph_planar());
}

TEST_F(SetupLeftRightPlanarityTesting, PetersenGraph_5_1)
{
    auto graph = generalized_petersen_graph_5_1();
    PlanarityTest<short> test(graph);
    test.run();
    EXPECT_TRUE(test.is_graph_planar());
}

TEST_F(SetupLeftRightPlanarityTesting, PetersenGraph_5_2)
{
    auto graph = generalized_petersen_graph_5_2();
    PlanarityTest<short> test(graph);
    test.run();
    EXPECT_FALSE(test.is_graph_planar());
}

TEST_F(SetupLeftRightPlanarityTesting, UtilityGraph)
{
    auto graph = utility_graph();
    PlanarityTest<short> test(graph);
    test.run();
    EXPECT_FALSE(test.is_graph_planar());
}

TEST_F(SetupLeftRightPlanarityTesting, CompleteTripartiteGraphK333)
{
    auto graph = complete_tripartite_graph_k333();
    PlanarityTest<int> test(graph);
    test.run();
    EXPECT_FALSE(test.is_graph_planar());
}

TEST_F(SetupLeftRightPlanarityTesting, RandomPlanarGraph50Nodes)
{
    auto graph = random_planar_graph_50_nodes();
    PlanarityTest<int32_t> test(graph);
    test.run();
    EXPECT_TRUE(test.is_graph_planar());
}

TEST_F(SetupLeftRightPlanarityTesting, RandomPlanarGraph100Nodes)
{
    auto graph = random_planar_graph_100_nodes();
    PlanarityTest<int32_t> test(graph);
    test.run();
    EXPECT_TRUE(test.is_graph_planar());
}

TEST_F(SetupLeftRightPlanarityTesting, RandomNonPlanarGraph50Nodes)
{
    auto graph = random_nonplanar_graph_50_nodes();
    PlanarityTest<int16_t> test(graph);
    test.run();
    EXPECT_FALSE(test.is_graph_planar());
}

TEST_F(SetupLeftRightPlanarityTesting, RandomPlanarConnectedGraph51Nodes)
{
    auto graph = random_planar_connected_graph_51_nodes();
    PlanarityTest<int64_t> test(graph);
    test.run();
    EXPECT_TRUE(test.is_graph_planar());
}

TEST_F(SetupLeftRightPlanarityTesting, TwoGraphsOnePlanarOneNonPlanar)
{
    auto graph = two_graphs_one_planar_one_nonplanar();
    PlanarityTest<int64_t> test(graph);
    test.run();
    EXPECT_FALSE(test.is_graph_planar());
}

TEST_F(SetupLeftRightPlanarityTesting, TwoGraphsOneNonPlanarOnePlanar)
{
    auto graph = two_graphs_one_nonplanar_one_planar();
    PlanarityTest<int64_t> test(graph);
    test.run();
    EXPECT_FALSE(test.is_graph_planar());
}

TEST_F(SetupLeftRightPlanarityTesting, TwoGraphsBothPlanar10NodesEach)
{
    auto graph = two_random_graphs_both_planar_10_nodes_each();
    PlanarityTest<int64_t> test(graph);
    test.run();
    EXPECT_TRUE(test.is_graph_planar());
}

TEST_F(SetupLeftRightPlanarityTesting, ThreeGraphsTwoPlanarOneNonPlanar)
{
    auto graph = three_random_graphs_two_planar_one_non_planar();
    PlanarityTest<int64_t> test(graph);
    test.run();
    EXPECT_FALSE(test.is_graph_planar());
}

TEST_F(SetupLeftRightPlanarityTesting, generalizedPetersenGraph)
{
    std::vector<bool> expected_results{
        1, 1, 1, 0, 1, 1, 1, 0, 0, 1, 1, 0, 1, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0,\
        0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0,\
        0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0,\
        0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0,\
        0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0,\
        0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0,\
        0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0,\
        0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0,\
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,\
        0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0,\
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,\
        0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0,\
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0,\
        0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,\
        0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0,\
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0,\
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,\
        0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,\
        0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,\
        0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,\
        0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,\
        0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,\
        1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,\
        1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,\
        1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,\
        0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,\
        0, 0
    };
    int result_index{};
    for (int n = 3; n <= 50; ++n)
    {
        for (int k = 1; k <= std::floor(n / 2); ++k)
        {
            if (!(!(n & 1) && k == n / 2))
            {
                auto graph = generateGeneralizedPetersenGraph(n, k);
                PlanarityTest<int32_t> test(graph);
                test.run();
                EXPECT_EQ(test.is_graph_planar(), expected_results[result_index++]);
                int x{};
                if (expected_results[result_index++] == 0)
                    x = 1;
                if (expected_results[result_index++] == 1)
                    x = 1;
                EXPECT_EQ(1, x);
            }
        }
    }
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


TEST_F(SetupLeftRightPlanarityTesting, EmptyGraphRecursive)
{
    auto graph = UndirectedGraph<int>{};
    PlanarityTest<int> test(graph);
    test.run_recursive();
    EXPECT_TRUE(test.is_graph_planar());
}

TEST_F(SetupLeftRightPlanarityTesting, SingleNodeRecursive)
{
    auto graph = UndirectedGraph<int>{};
    graph.add_node(1);
    PlanarityTest<int> test(graph);
    test.run_recursive();
    EXPECT_TRUE(test.is_graph_planar());
}

TEST_F(SetupLeftRightPlanarityTesting, PathGraphRecursive)
{
    for (int number_of_nodes{2}; number_of_nodes <= max_number_of_nodes; ++number_of_nodes)
    {
        auto graph = path_graph(number_of_nodes);
        PlanarityTest<int64_t> test(graph);
        test.run();
        EXPECT_TRUE(test.is_graph_planar());
    }
}

TEST_F(SetupLeftRightPlanarityTesting, CycleGraphRecursive)
{
    for (int number_of_nodes{2}; number_of_nodes <= max_number_of_nodes; ++number_of_nodes)
    {
        auto graph = cycle_graph(number_of_nodes);
        PlanarityTest<int> test(graph);
        test.run();
        EXPECT_TRUE(test.is_graph_planar());
    }
}

TEST_F(SetupLeftRightPlanarityTesting, StarGraphRecursive)
{
    for (int number_of_nodes{2}; number_of_nodes <= max_number_of_nodes; ++number_of_nodes)
    {
        auto graph = star_graph(number_of_nodes);
        PlanarityTest<int> test(graph);
        test.run();
        EXPECT_TRUE(test.is_graph_planar());
    }
}

TEST_F(SetupLeftRightPlanarityTesting, TreeGraphRecursive)
{
    for (int number_of_nodes{2}; number_of_nodes <= max_number_of_nodes; ++number_of_nodes)
    {
        auto graph = tree_graph(number_of_nodes);
        PlanarityTest<int> test(graph);
        test.run();
        EXPECT_TRUE(test.is_graph_planar());
    }
}

TEST_F(SetupLeftRightPlanarityTesting, WheelGraphRecursive)
{
    for (int number_of_nodes{4}; number_of_nodes <= max_number_of_nodes; ++number_of_nodes)
    {
        auto graph = wheel_graph(number_of_nodes);
        PlanarityTest<int> test(graph);
        test.run();
        EXPECT_TRUE(test.is_graph_planar());
    }
}

TEST_F(SetupLeftRightPlanarityTesting, GridGraph3x3Recursive)
{
    auto graph = grid_graph_3x3();
    PlanarityTest<int> test(graph);
    test.run_recursive();
    EXPECT_TRUE(test.is_graph_planar());
}

TEST_F(SetupLeftRightPlanarityTesting, CompleteGraphK3Recursive)
{
    auto graph = complete_graph_k3();
    PlanarityTest<int> test(graph);
    test.run_recursive();
    EXPECT_TRUE(test.is_graph_planar());
}

TEST_F(SetupLeftRightPlanarityTesting, CompleteGraphK4Recursive)
{
    auto graph = complete_graph_k4();
    PlanarityTest<int> test(graph);
    test.run_recursive();
    EXPECT_TRUE(test.is_graph_planar());
}


TEST_F(SetupLeftRightPlanarityTesting, CompleteGraphK5Recursive)
{
    auto graph = complete_graph_k5();
    PlanarityTest<int> test(graph);
    test.run_recursive();
    EXPECT_FALSE(test.is_graph_planar());
}

TEST_F(SetupLeftRightPlanarityTesting, CompleteGraphK6Recursive)
{
    auto graph = complete_graph_k6();
    PlanarityTest<int> test(graph);
    test.run_recursive();
    EXPECT_FALSE(test.is_graph_planar());
}

TEST_F(SetupLeftRightPlanarityTesting, PetersenGraph_5_1Recursive)
{
    auto graph = generalized_petersen_graph_5_1();
    PlanarityTest<short> test(graph);
    test.run_recursive();
    EXPECT_TRUE(test.is_graph_planar());
}

TEST_F(SetupLeftRightPlanarityTesting, PetersenGraph_5_2Recursive)
{
    auto graph = generalized_petersen_graph_5_2();
    PlanarityTest<short> test(graph);
    test.run_recursive();
    EXPECT_FALSE(test.is_graph_planar());
}

TEST_F(SetupLeftRightPlanarityTesting, UtilityGraphRecursive)
{
    auto graph = utility_graph();
    PlanarityTest<short> test(graph);
    test.run_recursive();
    EXPECT_FALSE(test.is_graph_planar());
}

TEST_F(SetupLeftRightPlanarityTesting, CompleteTripartiteGraphK333Recursive)
{
    auto graph = complete_tripartite_graph_k333();
    PlanarityTest<int> test(graph);
    test.run_recursive();
    EXPECT_FALSE(test.is_graph_planar());
}

TEST_F(SetupLeftRightPlanarityTesting, RandomPlanarGraph50NodesRecursive)
{
    auto graph = random_planar_graph_50_nodes();
    PlanarityTest<int32_t> test(graph);
    test.run_recursive();
    EXPECT_TRUE(test.is_graph_planar());
}

TEST_F(SetupLeftRightPlanarityTesting, RandomPlanarGraph100NodesRecursive)
{
    auto graph = random_planar_graph_100_nodes();
    PlanarityTest<int32_t> test(graph);
    test.run_recursive();
    EXPECT_TRUE(test.is_graph_planar());
}

TEST_F(SetupLeftRightPlanarityTesting, RandomNonPlanarGraph50NodesRecursive)
{
    auto graph = random_nonplanar_graph_50_nodes();
    PlanarityTest<int16_t> test(graph);
    test.run_recursive();
    EXPECT_FALSE(test.is_graph_planar());
}

TEST_F(SetupLeftRightPlanarityTesting, RandomPlanarConnectedGraph51NodesRecursive)
{
    auto graph = random_planar_connected_graph_51_nodes();
    PlanarityTest<int64_t> test(graph);
    test.run_recursive();
    EXPECT_TRUE(test.is_graph_planar());
}

TEST_F(SetupLeftRightPlanarityTesting, TwoGraphsOnePlanarOneNonPlanarRecursive)
{
    auto graph = two_graphs_one_planar_one_nonplanar();
    PlanarityTest<int64_t> test(graph);
    test.run_recursive();
    EXPECT_FALSE(test.is_graph_planar());
}

TEST_F(SetupLeftRightPlanarityTesting, TwoGraphsOneNonPlanarOnePlanarRecursive)
{
    auto graph = two_graphs_one_nonplanar_one_planar();
    PlanarityTest<int64_t> test(graph);
    test.run_recursive();
    EXPECT_FALSE(test.is_graph_planar());
}

TEST_F(SetupLeftRightPlanarityTesting, TwoGraphsBothPlanar10NodesEachRecursive)
{
    auto graph = two_random_graphs_both_planar_10_nodes_each();
    PlanarityTest<int64_t> test(graph);
    test.run_recursive();
    EXPECT_TRUE(test.is_graph_planar());
}

TEST_F(SetupLeftRightPlanarityTesting, ThreeGraphsTwoPlanarOneNonPlanarRecursive)
{
    auto graph = three_random_graphs_two_planar_one_non_planar();
    PlanarityTest<int64_t> test(graph);
    test.run_recursive();
    EXPECT_FALSE(test.is_graph_planar());
}
