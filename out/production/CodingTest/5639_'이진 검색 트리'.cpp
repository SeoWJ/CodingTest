#include <iostream>

#define endl '\n'

using namespace std;

struct Node {
	int Data;

	Node* Left;
	Node* Right;
};

class BinarySearchTree {
public:
	Node* Root;

	BinarySearchTree() { Root = NULL; }
	void insert(int data, Node* pos);
	void postOrder(Node* n);
};

int main(int argc, char* argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	BinarySearchTree* bst = new BinarySearchTree();

	int input;
	while (cin >> input) bst->insert(input, bst->Root);

	bst->postOrder(bst->Root);

	return 0;
}

void BinarySearchTree::insert(int data, Node* pos) {
	if (Root == NULL) {
		Root = new Node();
		Root->Data = data;
		return;
	}
	
	if (pos->Data > data && pos->Left != NULL) {
		insert(data, pos->Left);
	}
	else if (pos->Data > data && pos->Left == NULL) {
		pos->Left = new Node();
		pos->Left->Data = data;
		return;
	}
	else if (pos->Data < data && pos->Right != NULL) {
		insert(data, pos->Right);
	}
	else if(pos->Data < data && pos->Right == NULL) {
		pos->Right = new Node();
		pos->Right->Data = data;
		return;
	}
}

void BinarySearchTree::postOrder(Node* n) {
	if (n->Left != NULL)
		postOrder(n->Left);
	if (n->Right != NULL)
		postOrder(n->Right);

	cout << n->Data << endl;
}