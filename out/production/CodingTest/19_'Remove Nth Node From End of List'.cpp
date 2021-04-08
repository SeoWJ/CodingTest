#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		int size = 0;

		ListNode* idx = head;
		while (1) {
			size++;
			idx = idx->next;

			if (idx == NULL) {
				break;
			}
		}

		if (size == 1) return NULL;

		ListNode* target = NULL;
		idx = head;
		for (int i = 0; i < size; i++) {
			if (i == size - n) {
				target = idx;
				break;
			}
			idx = idx->next;
		}

		if (target == head) return head->next;

		idx = head;
		while (1) {
			if (idx->next == target) {
				if (idx->next->next != NULL)
					idx->next = idx->next->next;
				else
					idx->next = NULL;
			}
			idx = idx->next;

			if (idx == NULL) break;
		}

		return head;
	}
};

int main() {
	ListNode* h = new ListNode(1);
	//ListNode* n1 = new ListNode(2);
	//ListNode* n2 = new ListNode(3);
	//ListNode* n3 = new ListNode(4);
	//ListNode* n4 = new ListNode(5);
	//h->next = n1;
	//n1->next = n2;
	//n2->next = n3;
	//n3->next = n4;

	Solution().removeNthFromEnd(h, 1);
}