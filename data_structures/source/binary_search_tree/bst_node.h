//
// Created by andreas on 22.01.22.
//

#ifndef BST_NODE_H
#define BST_NODE_H
template<typename Key, typename Value>
class BSTNode{
public:
	BSTNode(const Key & key, const Value &value){
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
	BSTNode * left()const
	{
		return left_;
	}
	BSTNode * right()const
	{
		return right_;
	}

private:
	Key key_;
	Value value_;
	BSTNode * left_;
	BSTNode * right_;
};

#endif //BST_NODE_H
