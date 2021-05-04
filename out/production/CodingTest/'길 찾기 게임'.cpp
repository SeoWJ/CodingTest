#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
	int nodeNumber;
	int x;
	int y;

	Node* leftChild;
	Node* rightChild;

	Node(int _nodeNumber, int _x, int _y) {
		nodeNumber = _nodeNumber;
		x = _x;
		y = _y;
		leftChild = rightChild = NULL;
	}
};

class BinarySearchTree {
public:
	Node* root = NULL;

	void insertNode(vector<vector<int>> nodeinfo) {
		for (unsigned int i = 0; i < nodeinfo.size(); i++)
			insertNode(nodeinfo[i]);
	}
	void insertNode(Node* n, vector<int> node) {
		if (node[0] < n->x) {
			if (n->leftChild == NULL) {
				n->leftChild = new Node(node[2], node[0], node[1]);
				return;
			}
			else
				insertNode(n->leftChild, node);
		}
		else {
			if (n->rightChild == NULL) {
				n->rightChild = new Node(node[2], node[0], node[1]);
				return;
			}
			else
				insertNode(n->rightChild, node);
		}
	}
	void insertNode(vector<int> node) {
		if (this->root == NULL)
			root = new Node(node[2], node[0], node[1]);
		else {
			insertNode(this->root, node);
		}
	}
	void preorder(Node* n, vector<int>& visited) {
		visited.push_back(n->nodeNumber);

		if (n->leftChild != NULL)
			preorder(n->leftChild, visited);
		if (n->rightChild != NULL)
			preorder(n->rightChild, visited);
	}
	void postorder(Node* n, vector<int>& visited) {
		if (n->leftChild != NULL)
			postorder(n->leftChild, visited);
		if (n->rightChild != NULL)
			postorder(n->rightChild, visited);

		visited.push_back(n->nodeNumber);
	}
};

bool compare(vector<int> v1, vector<int> v2) {
	if (v1[1] > v2[1])
		return true;
	else if (v1[1] < v2[1])
		return false;
	else {
		if (v1[0] < v2[0])
			return true;
		else
			return false;
	}
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
	vector<vector<int>> answer;

	for (unsigned int i = 0; i < nodeinfo.size(); i++)
		nodeinfo[i].push_back(i + 1);

	sort(nodeinfo.begin(), nodeinfo.end(), compare);

	BinarySearchTree* bst = new BinarySearchTree();
	answer.push_back({});
	answer.push_back({});

	bst->insertNode(nodeinfo);
	bst->preorder(bst->root, answer[0]);
	bst->postorder(bst->root, answer[1]);

	return answer;
}