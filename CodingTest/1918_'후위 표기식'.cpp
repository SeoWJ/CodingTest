#include <iostream>
#include <string>
#include <queue>
#include <stack>

#define endl '\n'

using namespace std;

struct Node {
	char data;
	Node* left_child = NULL;
	Node* right_child = NULL;
};

string original;
int idx = 0;

Node* parsing(string formula);
Node* parsing(Node* _operand1, string formula);
void postorder(Node* n);

int main(int argc, char* argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> original;

	Node* root = parsing(original);
	while (idx != original.size())
		root = parsing(root, original);

	postorder(root);
	cout << endl;

	return 0;
}

Node* parsing(string formula) {
	Node* operand1, * operand2, * symbol;

	if (formula[idx] == '(') {
		idx++;
		operand1 = parsing(formula);
	}
	else {
		operand1 = new Node;
		operand1->data = formula[idx];
		idx++;
	}

	symbol = new Node;
	while (formula[idx] == ')') idx++;
	if (formula[idx] == '\0') return operand1;
	symbol->data = formula[idx];
	symbol->left_child = operand1;
	idx++;

	if (formula[idx] == '(') {
		idx++;
		operand2 = parsing(formula);
	}
	else {
		operand2 = new Node;
		operand2->data = formula[idx];
		idx++;
	}
	symbol->right_child = operand2;

	return symbol;
}

Node* parsing(Node* _operand1, string formula) {
	Node* operand1, * operand2, * symbol;

	operand1 = _operand1;

	symbol = new Node;
	while (formula[idx] == ')') idx++;
	if (formula[idx] == '\0') return operand1;
	symbol->data = formula[idx];
	symbol->left_child = operand1;
	idx++;

	if (formula[idx] == '(') {
		idx++;
		operand2 = parsing(formula);
	}
	else {
		operand2 = new Node;
		operand2->data = formula[idx];
		idx++;
	}
	symbol->right_child = operand2;

	return symbol;
}

void postorder(Node* n) {
	if (n->left_child != NULL) postorder(n->left_child);
	if (n->right_child != NULL) postorder(n->right_child);

	cout << n->data;
}