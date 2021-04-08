#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define endl '\n'

using namespace std;

struct Node {
	int num;
	vector<int> edge;
	bool visit = false;
};

int N, M, V;
Node* nodelist[1001] = { NULL };
queue<int> q;

void DFS(int _V);
void BFS(int _V);
void makeGraph();
void clearVisit();

int main(int argc, char* argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	makeGraph();

	DFS(V);
	cout << endl;

	clearVisit();

	BFS(V);
	cout << endl;

	return 0;
}

void makeGraph() {
	cin >> N >> M >> V;

	for (int loop1 = 1; loop1 <= N; loop1++) {
		nodelist[loop1] = new Node();
		nodelist[loop1]->num = loop1;
	}

	for (int loop1 = 0; loop1 < M; loop1++) {
		int input1, input2;
		cin >> input1 >> input2;

		nodelist[input1]->edge.push_back(input2);
		nodelist[input2]->edge.push_back(input1);
	}

	for (int loop1 = 1; loop1 <= N; loop1++)
		sort(nodelist[loop1]->edge.begin(), nodelist[loop1]->edge.end());
}

void clearVisit() {
	for (int loop1 = 1; loop1 <= N; loop1++) {
		nodelist[loop1]->visit = false;
	}
}

void DFS(int _V) {
	if (nodelist[_V]->visit == false) {
		cout << nodelist[_V]->num << " ";
		nodelist[_V]->visit = true;
	}

	for (unsigned int loop1 = 0; loop1 < nodelist[_V]->edge.size(); loop1++) {
		if (nodelist[nodelist[_V]->edge[loop1]]->visit == false)
			DFS(nodelist[_V]->edge[loop1]);
	}
}

void BFS(int _V) {
	q.push(_V);

	while (!q.empty()) {
		if (nodelist[q.front()]->visit == false) {
			cout << nodelist[q.front()]->num << " ";
			nodelist[q.front()]->visit = true;
		}

		for (unsigned int loop1 = 0; loop1 < nodelist[q.front()]->edge.size(); loop1++) {
			if (nodelist[nodelist[q.front()]->edge[loop1]]->visit == false)
				q.push(nodelist[q.front()]->edge[loop1]);
		}
		q.pop();
	}
}