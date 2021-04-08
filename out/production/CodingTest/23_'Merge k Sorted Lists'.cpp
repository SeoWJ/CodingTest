#include <iostream>
#include <vector>

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
	ListNode* findMin(vector<ListNode*>& lists) {
		int min = 0x7FFFFFFF;
		ListNode* minNode = NULL;
		int modifiedList = -1;

		for (unsigned int i = 0; i < lists.size(); i++) {
			if (lists[i] == NULL) continue;
			else {
				if (lists[i]->val < min) {
					min = lists[i]->val;
					minNode = lists[i];
					modifiedList = i;
				}
			}
		}

		if(modifiedList != -1)
			lists[modifiedList] = lists[modifiedList]->next;

		return minNode;
	}
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		ListNode* resultHead;
		ListNode* current;

		resultHead = findMin(lists);
		if (resultHead == NULL) return resultHead;

		current = findMin(lists);
		if (current == NULL) return resultHead;
		else resultHead->next = current;

		while (1) {
			ListNode* next = findMin(lists);

			if (next == NULL) break;
			else {
				current->next = next;
				current = next;
			}
		}

		return resultHead;
	}
};

int main() {
	ListNode* n12 = new ListNode(5);
	ListNode* n11 = new ListNode(4, n12);
	ListNode* h1 = new ListNode(1, n11);

	ListNode* n22 = new ListNode(4);
	ListNode* n21 = new ListNode(3, n22);
	ListNode* h2 = new ListNode(1, n21);

	ListNode* n31 = new ListNode(6);
	ListNode* h3 = new ListNode(2, n31);

	vector<ListNode*> v = { h1, h2, h3 };

	Solution().mergeKLists(v);
}