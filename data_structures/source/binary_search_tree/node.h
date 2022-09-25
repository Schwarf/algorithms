//
// Created by andreas on 22.01.22.
//

#ifndef NODE_H
#define NODE_H
template<typename T>
struct Node{
public:
	explicit Node(const T & val){
		value = val;
	}
	Node * left = nullptr;
	Node * right = nullptr;
	int height{0};
	T value{};
};

#endif //NODE_H
