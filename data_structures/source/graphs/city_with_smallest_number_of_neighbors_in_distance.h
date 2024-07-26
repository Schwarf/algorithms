//
// Created by andreas on 26.07.24.
//

#ifndef DATA_STRUCTURES_CITY_WITH_SMALLEST_NUMBER_OF_NEIGHBORS_IN_DISTANCE_H
#define DATA_STRUCTURES_CITY_WITH_SMALLEST_NUMBER_OF_NEIGHBORS_IN_DISTANCE_H

// There are n cities numbered from 0 to n-1. Given the array edges where edges[i] = [from_i, to_i, weight_i]
// represents a bidirectional and weighted edge between cities fromi and toi, and given the integer distanceThreshold.
// Return the city with the smallest number of cities that are reachable through some path and whose distance is at
// most distanceThreshold, If there are multiple such cities, return the city with the greatest number.
// Notice that the distance of a path connecting cities i and j is equal to the sum of the edges' weights along that path.
#include <vector>
#include <queue>
#include <limits>
#include <iostream>

void
dijkstra(int n, const std::vector<std::vector<std::pair<int, int>>> &graph, std::vector<int> &shortest_path_distances,
         int start) {
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> q;
    q.emplace(start, 0);
    std::fill(shortest_path_distances.begin(), shortest_path_distances.end(), std::numeric_limits<int>::max());
    shortest_path_distances[start] = 0;
    while (!q.empty()) {
        auto [current_city, current_distance] = q.top();
        q.pop();
        if (current_distance > shortest_path_distances[current_city])
            continue;
        for (const auto &[neighbor, distance]: graph[current_city]) {
            if (shortest_path_distances[neighbor] > distance + current_distance) {
                shortest_path_distances[neighbor] = distance + current_distance;
                q.emplace(neighbor, shortest_path_distances[neighbor]);
            }
        }
    }
}

void bellman_ford(int n, const std::vector<std::vector<int>> &edges,
                  std::vector<int> &shortest_path_distances, int start) {
    std::fill(shortest_path_distances.begin(), shortest_path_distances.end(), std::numeric_limits<int>::max());
    shortest_path_distances[start] = 0;
    for (int city{1}; city < n; ++city) {
        for (const auto &edge: edges) {
            auto start = edge[0];
            auto end = edge[1];
            auto weight = edge[2];
            if (shortest_path_distances[start] != std::numeric_limits<int>::max() &&
                shortest_path_distances[start] + weight < shortest_path_distances[end]) {
                shortest_path_distances[end] = shortest_path_distances[start] + weight;
            }
            // Since we have undirected graph we have to update both directions
            if (shortest_path_distances[end] != std::numeric_limits<int>::max() &&
                shortest_path_distances[end] + weight < shortest_path_distances[start]) {
                shortest_path_distances[start] = shortest_path_distances[end] + weight;
            }

        }
    }
}


int
city_with_smallest_number_of_neighbors_dijkstra(int n, std::vector<std::vector<int>> &edges, int max_allowed_distance) {
    std::vector<std::vector<std::pair<int, int>>> graph(n);
    for (const auto &edge: edges) {
        graph[edge[0]].emplace_back(edge[1], edge[2]);
        graph[edge[1]].emplace_back(edge[0], edge[2]);
    }
    std::vector<std::vector<int>> shortest_paths(n, std::vector<int>(n, std::numeric_limits<int>::max()));
    for (int i{}; i < n; ++i) {
        shortest_paths[i][i] = 0;
    }

    for (int city{}; city < n; ++city) {
        dijkstra(n, graph, shortest_paths[city], city);
    }

    // get city with the fewest number of reachable cities given max_allowed_distance constraint
    int result_city{-1};
    int count{n};
    for (int city1{}; city1 < n; ++city1) {
        int reachable_count{};
        for (int city2{}; city2 < n; ++city2) {
            if (city2 == city1)
                continue;
            if (shortest_paths[city1][city2] <= max_allowed_distance) {
                reachable_count++;
            }
        }
        if (reachable_count <= count) {
            count = reachable_count;
            result_city = city1;
        }
    }
    return result_city;
}


int
city_with_smallest_number_of_neighbors_bellman_ford(int n, std::vector<std::vector<int>> &edges,
                                                    int max_allowed_distance) {
    std::vector<std::vector<int>> shortest_paths(n, std::vector<int>(n, std::numeric_limits<int>::max()));
    for (int i{}; i < n; ++i) {
        shortest_paths[i][i] = 0;
    }

    for (int city{}; city < n; ++city) {
        bellman_ford(n, edges, shortest_paths[city], city);
    }

    // get city with the fewest number of reachable cities given max_allowed_distance constraint
    int result_city{-1};
    int count{n};
    for (int city1{}; city1 < n; ++city1) {
        int reachable_count{};
        for (int city2{}; city2 < n; ++city2) {
            if (city2 == city1)
                continue;
            if (shortest_paths[city1][city2] <= max_allowed_distance) {
                reachable_count++;
            }
        }
        if (reachable_count <= count) {
            count = reachable_count;
            result_city = city1;
        }
    }
    return result_city;
}

void floyd_warshall(int n, std::vector<std::vector<int>> &distance_matrix) {
    for (int transition_city{}; transition_city < n; ++transition_city) {
        for (int start_city{}; start_city < n; ++start_city) {
            for (int end_city{}; end_city < n; ++end_city) {
                if (distance_matrix[start_city][transition_city] != std::numeric_limits<int>::max() &&
                    distance_matrix[transition_city][end_city] != std::numeric_limits<int>::max())
                    distance_matrix[start_city][end_city] = std::min(distance_matrix[start_city][end_city],
                                                                     distance_matrix[start_city][transition_city] +
                                                                     distance_matrix[transition_city][end_city]);
            }
        }
    }
}

int
city_with_smallest_number_of_neighbors_floyd_warshall(int n, std::vector<std::vector<int>> &edges,
                                                      int max_allowed_distance) {
    std::vector<std::vector<int>> distance_matrix(n, std::vector<int>(n, std::numeric_limits<int>::max()));
    for (int city{}; city < n; ++city) {
        distance_matrix[city][city] = 0;
    }
    for (const auto &edge: edges) {
        distance_matrix[edge[0]][edge[1]] = edge[2];
        distance_matrix[edge[1]][edge[0]] = edge[2];
    }

    floyd_warshall(n, distance_matrix);
    // get city with the fewest number of reachable cities given max_allowed_distance constraint
    int result_city{-1};
    int count{n};
    for (int city1{}; city1 < n; ++city1) {
        int reachable_count{};
        for (int city2{}; city2 < n; ++city2) {
            if (city2 == city1)
                continue;
            if (distance_matrix[city1][city2] <= max_allowed_distance) {
                reachable_count++;
            }
        }
        if (reachable_count <= count) {
            count = reachable_count;
            result_city = city1;
        }
    }
    return result_city;
}

void shortest_path_first(int n, const std::vector<std::vector<std::pair<int, int>>> &graph,
                         std::vector<int> &shortest_path_distances,
                         int start) {
    std::queue<int> q;
    std::vector<int> update_count(n);
    q.push(start);
    std::fill(shortest_path_distances.begin(), shortest_path_distances.end(), std::numeric_limits<int>::max());
    shortest_path_distances[start] = 0;

    while (!q.empty()) {
        int current_city = q.front();
        q.pop();
        for (const auto &[neighbor_city, distance]: graph[current_city]) {
            if (shortest_path_distances[neighbor_city] > shortest_path_distances[current_city] + distance) {
                shortest_path_distances[neighbor_city] = shortest_path_distances[current_city] + distance;
                update_count[neighbor_city]++;
                q.push(neighbor_city);
                if (update_count[neighbor_city] > n) // Should not happen here but to see the algo is working.
                    std::cerr << "Negative weight cycle detected" << std::endl;
            }
        }

    }
}

int
city_with_smallest_number_of_neighbors_shortest_path_first(int n, std::vector<std::vector<int>> &edges,
                                                           int max_allowed_distance) {
    std::vector<std::vector<std::pair<int, int>>> graph(n);
    for (const auto &edge: edges) {
        graph[edge[0]].emplace_back(edge[1], edge[2]);
        graph[edge[1]].emplace_back(edge[0], edge[2]);
    }
    std::vector<std::vector<int>> shortest_paths(n, std::vector<int>(n, std::numeric_limits<int>::max()));
    for (int i{}; i < n; ++i) {
        shortest_paths[i][i] = 0;
    }
    for (int city{}; city < n; ++city)
        shortest_path_first(n, graph, shortest_paths[city], city);

    // get city with the fewest number of reachable cities given max_allowed_distance constraint
    int result_city{-1};
    int count{n};
    for (int city1{}; city1 < n; ++city1) {
        int reachable_count{};
        for (int city2{}; city2 < n; ++city2) {
            if (city2 == city1)
                continue;
            if (shortest_paths[city1][city2] <= max_allowed_distance) {
                reachable_count++;
            }
        }
        if (reachable_count <= count) {
            count = reachable_count;
            result_city = city1;
        }
    }
    return result_city;
}

#endif //DATA_STRUCTURES_CITY_WITH_SMALLEST_NUMBER_OF_NEIGHBORS_IN_DISTANCE_H
