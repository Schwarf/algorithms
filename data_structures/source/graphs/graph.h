//
// Created by andreas on 19.12.22.
//

#ifndef GRAPH_H
#define GRAPH_H
#include <unordered_map>
#include <vector>
#include <set>
#include <memory>
#include <algorithm>
#include <unordered_set>


template <typename id_T, typename data_T>
struct GraphNode
{
    GraphNode(const id_T& id, const data_T& data)
    {
        this->data = data;
        this->id = id;
    }

    data_T data;
    id_T id;
    bool discovered{};
    bool processed{};
};

template <typename id_T, typename data_T>
using GraphNodePtr = std::shared_ptr<GraphNode<id_T, data_T>>;

template <typename id_T, typename data_T, bool directed_ = false>
class Graph
{
public:
    void set_has_cycle()
    {
        has_cycle_ = true;
    }

    bool has_cycle()
    {
        return has_cycle_;
    }

    std::set<id_T> get_neighbors(const GraphNodePtr<id_T, data_T>& vertex)
    {
        return this->edges_[vertex->id];
    }

    std::set<id_T> get_neighbors(id_T id)
    {
        return this->edges_[id];
    }

    GraphNodePtr<id_T, data_T> get_vertex_by_id(id_T id)
    {
        return vertices_[id];
    }

    void add_edge(const GraphNodePtr<id_T, data_T>& source_vertex,
                  const GraphNodePtr<id_T, data_T>& destination_vertex)
    {
        if (vertices_.find(source_vertex->id) == vertices_.end())
            add_vertex(source_vertex);
        if (vertices_.find(destination_vertex->id) == vertices_.end())
            add_vertex(destination_vertex);
        add_edge(source_vertex->id, destination_vertex->id);
    }

    void add_edge(const id_T& source_vertex_id,
                  const id_T& destination_vertex_id)
    {
        if (vertices_.find(source_vertex_id) == vertices_.end())
            throw std::invalid_argument(
                "The source vertex id=" + std::to_string(source_vertex_id) + " does not exist in the graph!");
        if (vertices_.find(destination_vertex_id) == vertices_.end())
            throw std::invalid_argument(
                "The destination vertex id=" + std::to_string(destination_vertex_id) + " does not exist in the graph!");
        edges_[source_vertex_id].insert(destination_vertex_id);
        if (!directed_)
            edges_[destination_vertex_id].insert(source_vertex_id);
    }

    void reset_all_vertex_properties()
    {
        for (auto& [id, vertex] : vertices_)
        {
            vertex->discovered = false;
            vertex->processe = false;
        }
        has_cycle_ = false;
    }

    std::size_t number_of_vertices() const
    {
        return vertices_.size();
    }

    void add_vertex(const GraphNodePtr<id_T, data_T>& vertex)
    {
        vertices_[vertex->id] = vertex;
    }

    bool erase_edge(const id_T& source_vertex_id, const id_T& destination_vertex_id)
    {
        if (does_edge_exist(source_vertex_id, destination_vertex_id))
        {
            edges_[source_vertex_id].erase(destination_vertex_id);
            edges_[destination_vertex_id].erase(source_vertex_id);
            return true;
        }
        return false;
    }

    bool does_edge_exist(const id_T& source_vertex_id, const id_T& destination_vertex_id)
    {
        bool is_source_vertex_in_graph = edges_.find(source_vertex_id) != edges_.end();
        bool is_source_vertex_in_vertices = vertices_.find(source_vertex_id) != vertices_.end();

        bool is_destination_vertex_in_graph = edges_.find(destination_vertex_id) != edges_.end();
        bool is_destination_vertex_in_vertices = vertices_.find(destination_vertex_id) != vertices_.end();

        if (!is_source_vertex_in_vertices || !is_destination_vertex_in_vertices || !is_destination_vertex_in_graph
            || !is_source_vertex_in_graph)
            return false;

        return (edges_[source_vertex_id].find(destination_vertex_id) != edges_[source_vertex_id].end())
            && (edges_[destination_vertex_id].find(source_vertex_id) != edges_[destination_vertex_id].end());
    }

    bool erase_vertex(id_T id)
    {
        bool is_in_graph = edges_.find(id) != edges_.end();
        bool is_in_vertices = vertices_.find(id) != vertices_.end();
        if (!is_in_graph && !is_in_vertices)
            return false;

        if (is_in_vertices)
            vertices_.erase(id);

        if (is_in_graph)
        {
            auto affected_neighbors = get_neighbors(id);
            edges_.erase(id);
            for (const auto& neighbor_id : affected_neighbors)
            {
                auto iterator =
                    std::find_if(edges_[neighbor_id].begin(),
                                 edges_[neighbor_id].end(),
                                 [id](const id_T& vertex_id)
                                 {
                                     return vertex_id == id;
                                 });
                edges_[neighbor_id].erase(iterator);
            }
        }
        return true;
    }

private:
    // Here we store the relations between vertexs/vertices if they exist.
    std::unordered_map<id_T, std::set<id_T>> edges_;
    // Here we store all graph-vertexs (id, data) pairs, that can be retrieved using the id. A vertex might be isolated.
    // not participating in any relations with other vertexs
    std::unordered_map<id_T, GraphNodePtr<id_T, data_T>> vertices_;
    bool has_cycle_{};
};



template <typename NodeType>
requires std::is_signed_v<NodeType>
class DirectedGraph
{
public:

    DirectedGraph(const std::initializer_list<NodeType>& nodes, const std::initializer_list<std::pair<NodeType, NodeType>>& edges)
    {
        for(const auto& node : nodes)
            adjacency_list[node];
        for (const auto& edge : edges)
        {
            add_edge(edge.first, edge.second);
        }
    }

    // Add a directed edge from 'src' to 'dest'
    void add_edge(NodeType source_node, NodeType destination_node)
    {
        // Check if the edge is valid and does not already exist
        if (source_node != destination_node && adjacency_list[source_node].find(destination_node) == adjacency_list[source_node].end())
        {
            adjacency_list[source_node].insert(destination_node);

            ++edge_count; // Increment edge count for a new valid edge

            // Check if src or dest are new nodes
            if (!node_map.contains(source_node))
            {
                node_map[source_node] = true;
                ++node_count; // Increment node count
            }
            if (!node_map.contains(destination_node))
            {
                node_map[destination_node] = true;
                ++node_count; // Increment node count
            }
        }
    }

    // Get all nodes in the graph
    std::unordered_set<NodeType> get_all_nodes() const
    {
        std::unordered_set<NodeType> nodes;
        for (const auto& [node, neighbors] : adjacency_list)
        {
            nodes.insert(node);
        }
        return nodes;
    }

    // Get adjacent nodes of a given node
    const std::unordered_set<int>& get_neighbors(int node) const
    {
        return adjacency_list.at(node);
    }

    int get_node_count() const
    {
        return node_count;
    }

    // Get the total number of edges in the graph
    int get_edge_count() const
    {
        return edge_count;
    }

private:
    // Adjacency list: each node points to a set of nodes it has edges to
    std::unordered_map<NodeType, std::unordered_set<NodeType>> adjacency_list;
    std::unordered_map<NodeType, bool> node_map; // Tracks existing nodes to count only unique nodes
    int node_count{}; // Counter for unique nodes
    int edge_count{}; // Counter for unique edges
};


////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// UndirectedGraph
template <typename NodeType>
using Edge = std::pair<NodeType, NodeType>;

struct EdgeHash
{
    template <typename T>
    std::size_t operator()(const std::pair<T, T>& edge) const
    {
        return std::hash<T>()(edge.first) ^ std::hash<T>()(edge.second);
    }
};


template <typename NodeType>
std::pair<NodeType, NodeType> make_edge(NodeType u, NodeType v)
{
    return std::make_pair(u, v);
}


template <typename NodeType>
class UndirectedGraph
{
public:
    UndirectedGraph(const std::initializer_list<NodeType>& nodes, const std::initializer_list<std::pair<NodeType, NodeType>>& edges)
    {
        for(const auto& node : nodes)
            adjacency_list[node];
        for (const auto& edge : edges)
        {
            add_edge(edge.first, edge.second);
        }
    }

    // Add an undirected edge between 'source_node' and 'destination_node'
    void add_edge(NodeType source_node, NodeType destination_node)
    {
        // Check if the edge is valid and does not already exist in either direction
        // (since each edge is added bidirectional we check only one direction)
        edge_set.insert(make_edge(source_node, destination_node));
        edge_set.insert(make_edge(destination_node, source_node));
        if (source_node != destination_node && adjacency_list[source_node].find(destination_node) == adjacency_list[source_node].end())
        {
            adjacency_list[source_node].insert(destination_node);
            adjacency_list[destination_node].insert(source_node); // Make the edge bidirectional

            ++edge_count; // Increment edge count for a new valid edge

            // Check if nodes are new and update node count
            if (!node_map.contains(source_node))
            {
                node_map[source_node] = true;
                ++node_count;
            }
            if (!node_map.contains(destination_node))
            {
                node_map[destination_node] = true;
                ++node_count;
            }
        }
    }

    // Get all nodes in the graph
    std::unordered_set<NodeType> get_all_nodes() const
    {
        std::unordered_set<NodeType> nodes;
        for (const auto& [node, neighbors] : adjacency_list)
        {
            nodes.insert(node);
        }
        return nodes;
    }

    // Get adjacent nodes of a given node
    const std::unordered_set<int>& get_neighbors(int node) const
    {
        return adjacency_list.at(node);
    }

    // Get the total number of nodes in the graph
    int get_node_count() const
    {
        return node_count;
    }

    // Get the total number of edges in the graph
    int get_edge_count() const
    {
        return edge_count;
    }

private:
    std::unordered_map<NodeType, std::unordered_set<NodeType>> adjacency_list;
    std::unordered_map<NodeType, bool> node_map; // Tracks existing nodes to count only unique nodes
    std::unordered_set<Edge<NodeType>, EdgeHash> edge_set;
    int node_count{}; // Counter for unique nodes
    int edge_count{}; // Counter for unique edges
};


#endif //GRAPH_H
