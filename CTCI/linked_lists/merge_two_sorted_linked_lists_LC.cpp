//
// Created by andreas on 18.04.22.
//
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class RecursiveSolution {
public:
	ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
		if(list2 ==nullptr)
			return list1;
		if(list1 ==nullptr)
			return list2;
		ListNode *head = nullptr;
		if(list1->val <= list2->val)
		{
			head = list1;
			list1->next = mergeTwoLists(list1->next, list2);
		}
		else
		{
			head = list2;
			list2->next = mergeTwoLists(list1, list2->next);
		}
		return head;

	}
};


class IterativeSolution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

		if(l1 == nullptr && l2 == nullptr)
			return nullptr;
		if(l1 == nullptr)
			return l2;
		if(l2 == nullptr)
			return l1;

		ListNode * current1 = l1;
		ListNode * current2 = l2;
		ListNode *head =nullptr;
		if(current1->val <= current2->val)
		{
			head = current1;
			current1 = current1->next;
		}
		else
		{
			head = current2;
			current2 = current2->next;
		}

		ListNode * step = head;

		while(true)
		{
			if(current1 == nullptr)
			{
				step->next = current2;
				break;
			}
			if(current2 == nullptr)
			{
				step->next = current1;
				break;
			}

			if (current1->val <= current2->val )
			{
				step->next = current1;
				current1 = current1->next;
			}
			else
			{
				step->next = current2;
				current2 = current2->next;
			}
			step = step->next;
		}

		return head;

	}
};