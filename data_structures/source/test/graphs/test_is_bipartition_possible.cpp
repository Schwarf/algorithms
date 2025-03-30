//
// Created by andreas on 30.12.22.
//

#include "gtest/gtest.h"
#include "graphs/is_bipartition_possible.h"

class SetupBiPartitionPossible : public testing::Test
{
public:
    SetupBiPartitionPossible() = default;

protected:
    int id1 = 1, data1 = 1;
    int id2 = 2, data2 = 2;
    int id3 = 3, data3 = 3;
    int id4 = 4, data4 = 4;
    int id5 = 5, data5 = 5;
};


TEST_F(SetupBiPartitionPossible, test_positive_case)
{
    auto graph = Graph<int, int>();
    const std::shared_ptr<GraphNode<int, int>> vertex1(new GraphNode<int, int>(id1, data1));
    const std::shared_ptr<GraphNode<int, int>> vertex2(new GraphNode<int, int>(id2, data2));
    const std::shared_ptr<GraphNode<int, int>> vertex3(new GraphNode<int, int>(id3, data3));
    const std::shared_ptr<GraphNode<int, int>> vertex4(new GraphNode<int, int>(id4, data4));
    graph.add_edge(vertex1, vertex3);
    graph.add_edge(vertex1, vertex4);
    graph.add_edge(vertex2, vertex3);
    graph.add_edge(vertex2, vertex4);
    EXPECT_TRUE(is_bi_partition_possible(graph));
}


TEST_F(SetupBiPartitionPossible, test_negative_case)
{
    auto graph = Graph<int, int>();
    const std::shared_ptr<GraphNode<int, int>> vertex1(new GraphNode<int, int>(id1, data1));
    const std::shared_ptr<GraphNode<int, int>> vertex2(new GraphNode<int, int>(id2, data2));
    const std::shared_ptr<GraphNode<int, int>> vertex3(new GraphNode<int, int>(id3, data3));
    const std::shared_ptr<GraphNode<int, int>> vertex4(new GraphNode<int, int>(id4, data4));
    graph.add_edge(vertex1, vertex3);
    graph.add_edge(vertex1, vertex4);
    graph.add_edge(vertex2, vertex3);
    graph.add_edge(vertex2, vertex4);
    graph.add_edge(vertex1, vertex2);
    EXPECT_FALSE(is_bi_partition_possible(graph));
}

TEST_F(SetupBiPartitionPossible, test_negative_erase_positive)
{
    auto graph = Graph<int, int>();
    const std::shared_ptr<GraphNode<int, int>> vertex1(new GraphNode<int, int>(id1, data1));
    const std::shared_ptr<GraphNode<int, int>> vertex2(new GraphNode<int, int>(id2, data2));
    const std::shared_ptr<GraphNode<int, int>> vertex3(new GraphNode<int, int>(id3, data3));
    const std::shared_ptr<GraphNode<int, int>> vertex4(new GraphNode<int, int>(id4, data4));
    const std::shared_ptr<GraphNode<int, int>> vertex5(new GraphNode<int, int>(id5, data5));
    graph.add_edge(vertex1, vertex3);
    graph.add_edge(vertex1, vertex4);
    graph.add_edge(vertex2, vertex3);
    graph.add_edge(vertex2, vertex4);
    graph.add_edge(vertex5, vertex2);
    graph.add_edge(vertex5, vertex3);
    EXPECT_FALSE(is_bi_partition_possible(graph));
    graph.erase_vertex(id5);
    EXPECT_TRUE(is_bi_partition_possible(graph));
}


TEST(BiPartitionPossibleVectorInput, test_simple_false)
{
    std::vector<std::vector<unsigned short>> input{
        {1, 2, 3},
        {0, 2},
        {0, 1, 3},
        {0, 2}
    };
    EXPECT_FALSE(is_bi_partition_possible(input));
}

TEST(BiPartitionPossibleVectorInput, test_simple_true)
{
    std::vector<std::vector<unsigned short>> input{
        {1, 3},
        {0, 2},
        {1, 3},
        {0, 2}
    };
    EXPECT_TRUE(is_bi_partition_possible(input));
}
