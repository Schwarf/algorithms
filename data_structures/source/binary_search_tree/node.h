//
// Created by andreas on 22.01.22.
//

#ifndef NODE_H
#define NODE_H
template<typename Key, typename Value>
class Node{
public:
	Node(const Key & key, const Value &value){
		key_ = key;
		value_ = value;
	}
	Key key() const
	{
		return key_;
	}
	Value value() const
	{
		return value_;
	}
	void reset_value(const Value & value)
	{
		value_ = value;
	}
	Node * left()const
	{
		return left_;
	}
	Node * right()const
	{
		return right_;
	}

private:
	Key key_;
	Value value_;
	Node * left_;
	Node * right_;
};

#endif //NODE_H
