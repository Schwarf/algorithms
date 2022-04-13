//
// Created by andreas on 13.04.22.
//

#ifndef GRAPH_H
#define GRAPH_H
#include <cstddef>
#include <list>

template<typename T>
class Vertex
{
	explicit Vertex(){
		label_ = Vertex<T>::label_counter_++;
		Vertex<T>::label_counter_++;
	}
	void add_vertex(const Vertex<T> & vertex)
	{
		connected_vertices_.insert(vertex);
	}

	size_t label()
	{
		return label_;
	}

private:
	static size_t label_counter_;
	size_t label_{};
	T value_;
	std::list<Vertex> connected_vertices_;

};

template<typename T>
size_t Vertex<T>::label_counter_ = 0;


#endif //GRAPH_H
