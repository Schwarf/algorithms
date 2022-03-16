#include <iostream>
#include <map>

template <class T>
class LinkedList
{
	struct Node{
		explicit Node(T val)
		{
			value = val;
		}
		T value;
		Node * next;
	};

	Node * head_;

public:
	LinkedList():
	head_(nullptr)
	{}
	void push_back(T value)
	{
		if (head_ == nullptr) {
			head_ = new Node(value);
			return;
		}
		auto node = head_;
		while (node->next != nullptr) {
			node = node->next;
		}
		node->next = new Node(value);
	}

	void print_list()
	{
		auto node = head_;
		while(node->next != nullptr)
		{
			std::cout << node->value << ", ";
			node = node->next;
		}
		std::cout << node->value << std::endl;
	}

	void remove_duplicates()
	{
		if(head_ == nullptr || head_->next == nullptr)
			return;
		auto back_node = head_;
		auto front_node = head_->next;
		auto front_prev = head_;

		while(back_node->next != nullptr)
		{
			front_prev = back_node;
			front_node = back_node->next;

			while(front_node != nullptr)
			{
				if(front_node->value == back_node->value)
				{
					front_prev->next = front_node->next;
					front_node = front_node->next->next;
				}
				else
				{
					front_prev = front_node;
					front_node = front_node->next;
				}
			}
			back_node = back_node->next;
		}

	}
};



int main()
{
	auto single = LinkedList<int>();
	single.push_back(1);
	single.push_back(2);
	single.push_back(13);
	single.push_back(2);
	single.push_back(12);
	single.push_back(13);
	single.push_back(178);
	single.print_list();
	single.remove_duplicates();
	single.print_list();

}
