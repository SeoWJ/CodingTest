// Sol 1. Prim

/*#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

#define endl '\n'

using namespace std;

typedef pair<int, int> Edge;

class Network {
protected:
	int N, M;
	vector<Edge> edges[1001];
	bool visit[1001];
	
	int answer;

public:
	Network(int n, int m) {
		answer = 0;
		N = n; M = m;
		memset(visit, false, sizeof(visit));

		for (int i = 0; i < M; i++) {
			int start, destination, weight;
			cin >> start >> destination >> weight;

			edges[start].push_back({ weight, destination });
			edges[destination].push_back({ weight, start });
		}
	}
	void prim(int startNode) {
		priority_queue<Edge, vector<Edge>, greater<Edge>> PQ;

		visit[startNode] = true;
		for (auto e : edges[startNode]) PQ.push(e);

		while (!PQ.empty()) {
			int destination = PQ.top().second;
			int weight = PQ.top().first;

			PQ.pop();

			if (visit[destination] == false) {
				visit[destination] = true;
				answer += weight;

				for (auto e : edges[destination]) PQ.push(e);
			}
		}
	}
	void solution() {
		prim(1);

		cout << answer << endl;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;

	Network* n = new Network(N, M);
	n->solution();

	delete n;

	return 0;
}*/

// Sol 2. ũ�罺Į

#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

#define endl '\n'

using namespace std;

typedef pair<int, pair<int, int>> Edge;

class Network {
protected:
	int N, M;
	priority_queue<Edge, vector<Edge>, greater<Edge>> edges;
	int unionHead[1001];
	int answer;

public:
	Network(int n, int m) {
		answer = 0;
		N = n; M = m;
		
		for (int i = 0; i <= N; i++) unionHead[i] = i;

		for (int i = 0; i < M; i++) {
			int start, destination, weight;
			cin >> start >> destination >> weight;

			edges.push({ weight, {start, destination} });
		}
	}
	int getUnionHead(int node) {
		if (unionHead[node] == node) return node;
		else return getUnionHead(unionHead[node]);
	}
	void setUnionHead(int node, int setValue) {
		int prevUnionHead = getUnionHead(node);

		unionHead[prevUnionHead] = setValue;
	}
	void kruskal() {
		while (!edges.empty()) {
			int weight = edges.top().first;
			int node1 = edges.top().second.first;
			int node2 = edges.top().second.second;

			int unionHead1 = getUnionHead(node1);
			int unionHead2 = getUnionHead(node2);

			edges.pop();

			if(unionHead1 == unionHead2)
				continue;
			else {
				answer += weight;

				if (unionHead1 < unionHead2)
					setUnionHead(unionHead2, unionHead1);
				else
					setUnionHead(unionHead1, unionHead2);
			}
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

	Network* n = new Network(N, M);
	n->solution();

	delete n;

	return 0;
}