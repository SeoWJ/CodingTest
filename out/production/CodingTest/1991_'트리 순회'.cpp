#include <iostream>

#define endl '\n'

using namespace std;

class Node {
public:
	char Data;

	Node* Left = NULL;
	Node* Right = NULL;

	Node(char _Data, Node* _Left, Node* _Right) {
		Data = _Data;
		Left = _Left;
		Right = _Right;
	}
};

void preorder(Node* n);
void inorder(Node* n);
void postorder(Node* n);

int main(int argc, char* argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N; cin >> N;

	Node* Tree[26] = { NULL };

	for (int i = 0; i < N; i++) {
		char parent, left, right;
		cin >> parent >> left >> right;

		if (Tree[parent - 'A'] == NULL) {
			if (left != '.' && Tree[left - 'A'] == NULL)
				Tree[left - 'A'] = new Node(left, NULL, NULL);
			if (right != '.' && Tree[right - 'A'] == NULL)
				Tree[right - 'A'] = new Node(right, NULL, NULL);
			
			Tree[parent - 'A'] = new Node(parent, NULL, NULL);
			if (left != '.')
				Tree[parent - 'A']->Left = Tree[left - 'A'];
			if (right != '.')
				Tree[parent - 'A']->Right = Tree[right - 'A'];
		}
		else {
			if (left != '.' && Tree[left - 'A'] == NULL)
				Tree[left - 'A'] = new Node(left, NULL, NULL);
			if (right != '.' && Tree[right - 'A'] == NULL)
				Tree[right - 'A'] = new Node(right, NULL, NULL);

			if(left != '.') Tree[parent - 'A']->Left = Tree[left - 'A'];
			if(right != '.') Tree[parent - 'A']->Right = Tree[right - 'A'];
		}
	}

	preorder(Tree[0]); cout << endl;
	inorder(Tree[0]); cout << endl;
	postorder(Tree[0]); cout << endl;

	return 0;
}

void preorder(Node* n) {
	cout << n->Data;
	if (n->Left != NULL) preorder(n->Left);
	if (n->Right != NULL) preorder(n->Right);
}

void inorder(Node* n) {
	if (n->Left != NULL) inorder(n->Left);
	cout << n->Data;
	if (n->Right != NULL) inorder(n->Right);
}

void postorder(Node* n) {
	if (n->Left != NULL) postorder(n->Left);
	if (n->Right != NULL) postorder(n->Right);
	cout << n->Data;
}