#include <iostream>
#include <vector>

#define endl '\n'

using namespace std;

struct Node {
	int num;
	int edge;
	vector<Node*> child;
};

class Tree {
public:
	Node* root;

	void insert(vector<int> input);
	Node* find(Node*n, int target);
	void preOrder(int current_length, Node* n);
};

int answer = 0;

int main(int argc, char* argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N; cin >> N;

	Tree* tree = new Tree();

	int input;
	vector<int> input_3;

	/*while (cin >> input) {
		input_3.push_back(input);

		if (input_3.size() == 3) {
			tree->insert(input_3);
		}
	}*/

	while (1) {
		cin >> input;
		
		if (input == -1) break;

		input_3.push_back(input);

		if (input_3.size() == 3) {
			tree->insert(input_3);
			input_3.clear();
		}
	}

	tree->preOrder(0, tree->root);

	cout << answer << endl;

	return 0;
}

Node* Tree::find(Node* n, int target) {
	if (n->num == target)
		return n;
	else {
		Node* nn = NULL;

		for (unsigned int i = 0; i < n->child.size(); i++) {
			if (nn == NULL)
				nn = find(n->child[i], target);
		}

		return nn;
	}
}

void Tree::insert(vector<int> input) {
	if (root == NULL) {
		root = new Node();
		Node* n = new Node();
		
		root->num = input[0];
		root->edge = 0;
		n->num = input[1];
		n->edge = input[2];

		root->child.push_back(n);
	}
	else {
		Node* parent = find(root, input[0]);
		Node* child = new Node();

		child->num = input[1];
		child->edge = input[2];

		parent->child.push_back(child);
	}
}

void Tree::preOrder(int current_length, Node* n) {
	if (current_length > answer)
		answer = current_length;

	for (unsigned int i = 0; i < n->child.size(); i++) {
		preOrder(current_length + n->child[i]->edge, n->child[i]);
	}
}