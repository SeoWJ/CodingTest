#include <iostream>
#include <queue>
#include <vector>

#define endl '\n'

using namespace std;

typedef pair<int, pair<int, int>> Edge;

class Village {
protected:
	int N, M;
	int unionHead[100001];
	priority_queue<Edge, vector<Edge>, greater<Edge>> edges;

	int answer;

public:
	Village(int n, int m) {
		N = n; M = m;
		answer = 0;

		for (int i = 0; i < 100001; i++) unionHead[i] = i;

		for (int i = 0; i < M; i++) {
			int start, destination, weight;
			cin >> start >> destination >> weight;

			edges.push({ weight, {start, destination} });
		}
	}
	int getUnionHead(int node) {
		if (unionHead[node] == node)
			return unionHead[node];
		else
			return getUnionHead(unionHead[node]);
	}
	void setUnionHead(int node, int setValue) {
		int prevUnionHead = getUnionHead(node);

		unionHead[prevUnionHead] = setValue;
	}
	void kruskal() {
		priority_queue<int, vector<int>, less<int>> MST;

		while (!edges.empty()) {
			int weight = edges.top().first;
			int node1 = edges.top().second.first;
			int node2 = edges.top().second.second;

			int unionHead1 = getUnionHead(node1);
			int unionHead2 = getUnionHead(node2);

			edges.pop();

			if (unionHead1 == unionHead2)
				continue;
			else {
				MST.push(weight);

				if (unionHead1 < unionHead2)
					setUnionHead(unionHead2, unionHead1);
				else
					setUnionHead(unionHead1, unionHead2);
			}
		}

		MST.pop();

		while (!MST.empty()) {
			answer += MST.top();
			MST.pop();
		}
	}
	void solution() {
		kruskal();

		cout << answer << endl;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;

	Village* v = new Village(N, M);
	v->solution();

	delete v;

	return 0;
}