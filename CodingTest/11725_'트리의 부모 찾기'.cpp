#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define endl '\n'

using namespace std;

struct Node {
	int Data;
	Node* Parent = NULL;
	vector<Node*> Child;
};

class Tree {
public:
	Node* Root;

	Tree() { Root = NULL; }
	void insert(int i1, int i2);
	Node* find(int data, Node* current);
	void preOrder(Node* current);
};

deque<pair<int, int>> Exception;
vector<int> answer;

int main(int argc, char* argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N; 
	vector<pair<int, int>> input;
	Tree* T = new Tree();

	cin >> N;

	answer.assign(N + 1, -1);

	for (int i = 0; i < N - 1; i++) {
		int in1, in2;
		cin >> in1 >> in2;
		input.push_back(make_pair(in1, in2));
	}

	sort(input.begin(), input.end());

	for (int i = 0; i < N - 1; i++)
		T->insert(input[i].first, input[i].second);

	while (!Exception.empty()) {
		T->insert(Exception[0].first, Exception[0].second);
		Exception.pop_front();
	}

	T->preOrder(T->Root);

	for (int i = 2; i <= N; i++)
		cout << answer[i] << endl;

	return 0;
}

void Tree::insert(int i1, int i2) {
	if (Root == NULL) {
		if (i1 == 1) {
			Root = new Node();
			Node* n = new Node();
			
			Root->Data = i1;
			n->Data = i2;
			n->Parent = Root;
			Root->Child.push_back(n);
		}
		if(i2 == 1) {
			Root = new Node();
			Node* n = new Node();

			Root->Data = i2;
			n->Data = i1;
			n->Parent = Root;
			Root->Child.push_back(n);
		}
		if (i1 != 1 && i2 != 1)
			Exception.push_back(make_pair(i1, i2));
		return;
	}

	Node* target = find(i1, Root);
	if (target == NULL) target = find(i2, Root);
	if (target == NULL) {
		Exception.push_back(make_pair(i1, i2));
		return;
	}

	Node* n = new Node();
	n->Data = target->Data == i1 ? i2 : i1;
	n->Parent = target;
	target->Child.push_back(n);
}

Node* Tree::find(int data, Node* current) {
	if (current->Data == data)
		return current;
	else {
		Node* n = NULL;
		for (int i = 0; i < current->Child.size(); i++) {
			if (n == NULL)
				n = find(data, current->Child[i]);
		}
		return n;
	}
}

void Tree::preOrder(Node* current) {
	if(current != Root)
		answer[current->Data] = current->Parent->Data;

	for (unsigned int i = 0; i < current->Child.size(); i++)
		preOrder(current->Child[i]);
}