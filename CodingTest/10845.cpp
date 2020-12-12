#include <iostream>

#define endl '\n'

using namespace std;

struct Node {
	int data;
	Node* next = NULL;
};

class Queue {
public:
	Node* frontNode = NULL;
	Node* backNode = NULL;
	int qsize = 0;

	void push(int data);
	void pop();
	int size();
	bool empty();
	int front();
	int back();
};

void Queue::push(int _data) {
	qsize++;

	if (frontNode == NULL) {
		Node* n = new Node;
		n->data = _data;

		frontNode = backNode = n;

		return;
	}
	else {
		Node* n = new Node;
		n->data = _data;

		backNode->next = n;
		backNode = n;

		return;
	}
}

void Queue::pop() {
	if (qsize <= 0) return;
	else if (qsize == 1) {
		qsize--;
		delete frontNode;
		frontNode = backNode = NULL;
	}
	else {
		qsize--;
		Node* temp = frontNode->next;
		delete frontNode;
		frontNode = temp;
	}

}

int Queue::size() { return qsize; }

bool Queue::empty() { return qsize == 0; }

int Queue::front() {
	if (qsize == 0)
		return -1;
	return frontNode->data;
}

int Queue::back() {
	if (qsize == 0)
		return -1;
	return backNode->data;
}

int main(int argc, char* argv[]) {
	Queue q;

	int N; cin >> N;
	while (N--) {
		string command; cin >> command;

		if (command == "push") {
			int input; cin >> input;
			q.push(input);
		}
		else if (command == "pop") {
			cout << q.front() << endl;
			q.pop();
		}
		else if (command == "size")
			cout << q.size() << endl;
		else if (command == "empty")
			cout << q.empty() << endl;
		else if (command == "front")
			cout << q.front() << endl;
		else if (command == "back")
			cout << q.back() << endl;
	}
}