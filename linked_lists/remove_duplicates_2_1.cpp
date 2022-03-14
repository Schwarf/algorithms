#include <iostream>
#include "singly_linked_list.h"



int main()
{
	auto single = SinglyLinkedList<int>();
	single.push_back(1);
	single.push_back(2);
	single.push_front(13);
	single.push_front(2);
	single.push_back(12);
	single.push_back(13);
	single.push_back(178);
}
