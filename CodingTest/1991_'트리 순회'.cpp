#include <iostream>

#define endl '\n'

using namespace std;

struct Node {
	Node* Parent = NULL;
	Node* LeftChild = NULL;
	Node* RightChild = NULL;

	char Data = NULL;
};

class BinaryTree {
public:
	Node* Root;

	BinaryTree() { Root = NULL; }
	void insert(char parent, char left, char right);
	Node* find(Node* current, char data);
	void preorder(Node* current);
	void inorder(Node* current);
	void postorder(Node* current);
};

int main(int argc, char* argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	BinaryTree* bt = new BinaryTree();

	int n; cin >> n;

	for (int i = 0; i < n; i++) {
		char p, l, r;
		cin >> p >> l >> r;

		bt->insert(p, l, r);
	}

	bt->preorder(bt->Root);
	cout << endl;
	bt->inorder(bt->Root);
	cout << endl;
	bt->postorder(bt->Root);
	cout << endl;

	return 0;
}

void BinaryTree::insert(char _parent, char _left, char _right) {
	if (Root == NULL) {
		Root = new Node();
		Root->Data = _parent;
		Root->LeftChild = new Node();
		Root->LeftChild->Data = _left;
		Root->RightChild = new Node();
		Root->RightChild->Data = _right;
	}
	else {
		Node* parent = find(this->Root, _parent);
		
		if (_left != '.') {
			parent->LeftChild = new Node();
			parent->LeftChild->Data = _left;
		}
		if (_right != '.') {
			parent->RightChild = new Node();
			parent->RightChild->Data = _right;
		}
	}
}

Node* BinaryTree::find(Node* current, char data) {
	if (current->Data == data)
		return current;
	else {
		Node* result = NULL;

		if (current->LeftChild != NULL) {
			result = find(current->LeftChild, data);
			if (result != NULL)
				return result;
		}
		if(current->RightChild != NULL) {
			result = find(current->RightChild, data);
			if (result != NULL)
				return result;
		}
	}
}

void BinaryTree::preorder(Node* current) {
	cout << current->Data;
	if (current->LeftChild != NULL) preorder(current->LeftChild);
	if (current->RightChild != NULL) preorder(current->RightChild);
}

void BinaryTree::inorder(Node* current) {
	if (current->LeftChild != NULL) inorder(current->LeftChild);
	cout << current->Data;
	if (current->RightChild != NULL) inorder(current->RightChild);
}

void BinaryTree::postorder(Node* current) {
	if (current->LeftChild != NULL) postorder(current->LeftChild);
	if (current->RightChild != NULL) postorder(current->RightChild);

	cout << current->Data;
}