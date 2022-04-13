//
// Created by andreas on 13.04.22.
//

#ifndef GRAPH_H
#define GRAPH_H
#include <cstddef>
#include <list>

template<typename data_T>
class Vertex;


template<typename data_T, typename weight_T>
struct UndirectedConnection
{
	UndirectedConnection(Vertex<data_T> * vertex1, Vertex<data_T> * vertex2, weight_T weight)
	{
		vertex1_ = vertex1;
		vertex2_ = vertex2;
		weight_ = weight;
	}
	Vertex<data_T> * vertex1_;
	Vertex<data_T> * vertex2_;
	weight_T weight_;
};



template<typename data_T>
class Vertex
{
	explicit Vertex(data_T value){
		value_ = value;
	}

	void connect_to_vertex(Vertex<data_T> * vertex)
	{
		connections_.insert(new UndirectedConnection<data_T, size_t>(this, vertex));
	}

	std::list<UndirectedConnection<data_T, size_t>> vertices()
	{
		return connections_;
	}

	data_T value()
	{
		return value_;
	}

private:
	data_T value_;
	std::list<UndirectedConnection<data_T, size_t> * > connections_;

};



#endif //GRAPH_H
