//
// Created by andreas on 10.04.23.
//
#include "gtest/gtest.h"
#include "graphs/clone_graph.h"

class SetupCloneGraphTests : public testing::Test {
public:
    SetupCloneGraphTests() = default;

protected:
    Node<int> *sample_graph() {
        auto node = new Node<int>(1);
        auto neighbor1_1 = new Node<int>(2);
        auto neighbor1_2 = new Node<int>(3);
        auto neighbor2_1 = new Node<int>(4);
        node->neighbors.push_back(neighbor1_1);
        node->neighbors.push_back(neighbor1_2);
        neighbor1_1->neighbors.push_back(neighbor2_1);
        neighbor1_1->neighbors.push_back(node);
        neighbor1_2->neighbors.push_back(neighbor2_1);
        neighbor1_2->neighbors.push_back(node);
        return node;
    }

    bool is_node_in_graph(Node<int> *graph, Node<int> *node, std::vector<bool> &visited) {
        if (node == graph)
            return true;
        visited[graph->value] = true;
        for (const auto &neighbor: graph->neighbors) {
            if (!visited[neighbor->value])
                is_node_in_graph(neighbor, node, visited);
        }
        return false;
    }
};


TEST_F(SetupCloneGraphTests, first_try) {
    auto node = sample_graph();
    auto copy = node;
    EXPECT_EQ(copy, node);
    auto new_node = clone_graph(node);
    EXPECT_NE(new_node, node);
    EXPECT_EQ(new_node->neighbors[0]->value, node->neighbors[0]->value);
    EXPECT_EQ(new_node->neighbors[1]->value, node->neighbors[1]->value);
    EXPECT_NE(new_node->neighbors[1], node->neighbors[1]);
    EXPECT_NE(new_node->neighbors[0], node->neighbors[0]);
}

TEST_F(SetupCloneGraphTests, with_is_node_in_graph) {
    auto node = sample_graph();
    auto copy = node;
    std::vector<bool> default_visited(5);
    auto visited = default_visited;
    EXPECT_TRUE(is_node_in_graph(node, copy, visited));
    auto new_node = clone_graph(node);
    visited = default_visited;
    EXPECT_FALSE(is_node_in_graph(new_node, node, visited));
    EXPECT_FALSE(is_node_in_graph(node, new_node, visited));
}
