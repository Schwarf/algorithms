//
// Created by andreas on 21.09.22.
//
#include "basics.h"


int main()
{
	constexpr int number_of_vertices = 10;
	constexpr int probability_to_create_edge = 15; // percent
	auto graph = DirectedGraph<int>(number_of_vertices);
	create_edges_in_graph(graph, probability_to_create_edge);


	return 0;
}
