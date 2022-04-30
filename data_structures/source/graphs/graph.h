//
// Created by andreas on 13.04.22.
//

#ifndef GRAPH_H
#define GRAPH_H
#include <cstddef>
#include <list>

template<typename data_T>
class Vertex;


template<typename data_T>
struct UndirectedEdge
{
	UndirectedEdge(Vertex<data_T> * vertex1, Vertex<data_T> * vertex2, size_t weight)
	{
		vertex1_ = vertex1;
		vertex2_ = vertex2;
		weight_ = weight;
	}
	Vertex<data_T> * vertex1_;
	Vertex<data_T> * vertex2_;
	size_t weight_;
};



template<typename data_T>
class Vertex
{
	explicit Vertex(data_T value){
		value_ = value;
		vertex_id_ = vertex_count_;
		vertex_count_++;

	}

	void connect_to_vertex(Vertex<data_T> * vertex, size_t weight)
	{
		edges_.insert(new UndirectedEdge<data_T>(this, vertex, weight));
	}

	std::list<UndirectedEdge<data_T>> edges()
	{
		return edges_;
	}

	size_t id()
	{
		return vertex_id_;
	}
	data_T value()
	{
		return value_;
	}
	~Vertex()
	{
		for(auto connection : edges_)
		{
			delete connection;
		}
	}

private:
	data_T value_;
	std::list<UndirectedEdge<data_T> * > edges_;
	size_t vertex_id_{};
	static size_t vertex_count_;
};

template <typename  data_T>
size_t Vertex<data_T>::vertex_count_ = 0;


#endif //GRAPH_H
