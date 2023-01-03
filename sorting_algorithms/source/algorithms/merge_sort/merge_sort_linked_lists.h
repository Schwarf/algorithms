//
// Created by andreas on 03.01.23.
//

#ifndef MERGE_SORT_LINKED_LISTS_H
#define MERGE_SORT_LINKED_LISTS_H
template<typename T>
struct Node
{
	Node<T> *next;
	T data;
};

template<typename T>
void merge_sort(Node<T> *&head)
{
	if (head->next == nullptr)
		return;

	Node<T> *head1;
	Node<T> *head2 = head;
}

template<typename T>
int get_list_length(Node<T> *head)
{
	int length{};
	while (head) {
		length++;
		head = head->next;
	}
	return length;
}

template<typename T>
Node<T> *merge(Node<T> *&head1, Node<T> *&head2);
#endif //MERGE_SORT_LINKED_LISTS_H
