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
Node<T> *merge(Node<T> *&head1, Node<T> *&head2)
{
	if (!head1)
		return head2;
	if (!head2)
		return head1;
	Node<T> *new_head = nullptr;
	if (head1->data < head2->data) {
		new_head = head1;
		new_head->next = merge(head1->next, head2);
	}
	else {
		new_head = head2;
		new_head->next = merge(head1, head2->next);
	}
	return new_head;
}

template<typename T>
void merge_sort(Node<T> *&head)
{
	if (head->next == nullptr)
		return;

	Node<T> *head1 = nullptr;
	Node<T> *head2 = head;
	auto list_length = get_list_length(head);
	for (int i{}; i < list_length / 2; ++i) {
		head1 = head2;
		head2 = head2->next;
	}
	head1->next = nullptr;
	head1 = head;
	merge_sort(head1);
	merge_sort(head2);
	head = merge(head1, head2);

}

#endif //MERGE_SORT_LINKED_LISTS_H
