#include <iostream>
#include <queue>

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
	ListNode* reverseKGroup(ListNode* head, int k) {
		deque<deque<ListNode*>> DQ;
		ListNode* current = head;
		deque<ListNode*> grp;

		while (1) {
			if (current == NULL) {
				if (!grp.empty()) {
					deque<ListNode*> finalGrp;

					while (!grp.empty()) {
						finalGrp.push_back(grp.back());
						grp.pop_back();
					}

					DQ.push_back(finalGrp);
				}

				break;
			}
			else {
				grp.push_front(current);
				current = current->next;

				if (grp.size() == k) {
					DQ.push_back(grp);
					grp.clear();
				}
			}
		}

		ListNode* newHead = DQ[0][0];
		current = newHead;
		DQ[0].pop_front();

		for (unsigned int i = 0; i < DQ.size(); i++) {
			while (!DQ[i].empty()) {
				current->next = DQ[i].front();
				DQ[i].pop_front();
				current = current->next;
			}
		}

		return newHead;
	}
};

int main() {
	Solution s;
	ListNode* l1 = new ListNode(1);
	ListNode* l2 = new ListNode(2);
	//ListNode* l3 = new ListNode(3);
	//ListNode* l4 = new ListNode(4);
	//ListNode* l5 = new ListNode(5);
	l1->next = l2;
	//l2->next = l3;
	//l3->next = l4;
	//l4->next = l5;

	s.reverseKGroup(l1, 2);
}