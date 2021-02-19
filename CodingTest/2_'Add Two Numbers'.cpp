#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
	ListNode* listHead;
	ListNode* listTail;
	ListNode* currentNode;

	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		int sum = l1->val + l2->val;
		int nodeVal = sum % 10;
		int toNext = sum / 10;

		listHead = listTail = currentNode = new ListNode(nodeVal);
		l1 = l1->next;
		l2 = l2->next;

		while (1) {
			if (l1 == NULL && l2 == NULL) {
				if (toNext > 0) {
					listTail = new ListNode(toNext);
					currentNode->next = listTail;
				}
				break;
			}

			sum = toNext;
			if (l1 != NULL) { 
				sum += l1->val; 
				l1 = l1->next;
			}
			if (l2 != NULL) {
				sum += l2->val;
				l2 = l2->next;
			}

			nodeVal = sum % 10;
			listTail = new ListNode(nodeVal);
			currentNode->next = listTail;
			currentNode = listTail;

			toNext = sum / 10;
		}

		return listHead;
	}
};