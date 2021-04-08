#include <iostream>
#include <vector>
#include <queue>

#define endl '\n'
#define INF 5001

using namespace std;

typedef pair<int, int> Edge;
typedef pair<int, int> Node;

class MooTube {
protected:
	int N, Q;
	vector<Edge> edges[5001];

public:
	MooTube(int n, int q) {
		N = n; Q = q;

		for (int i = 0; i < N - 1; i++) {
			int p, q, r; cin >> p >> q >> r;

			edges[p].push_back({ r,q });
			edges[q].push_back({ r,q });
		}
	}
	vector<int> dijkstra(int startPoint) {
		vector<int> USADO(5001, INF);
		priority_queue<Node, vector<Node>, greater<Node>> pq;

		USADO[startPoint] = 0;
		pq.push({ 0, startPoint });

		while (!pq.empty()) {
			int currentDistance = pq.top().first;
			int currentNode = pq.top().second;
			
			pq.pop();

			for (auto e : edges[currentNode]) {
				int newDistance = USADO[currentNode] + e.first;
				int beforeDistance = USADO[e.second];

				if (newDistance < beforeDistance) {
					USADO[e.second] = newDistance;
					pq.push({ newDistance, e.second });
				}
			}
		}

		return USADO;
	}
	void query(int k, int v, vector<int>& USADO) {
		int answer = 0;

		for (int i = 1; i <= N; i++) {
			if (k <= USADO[i] && USADO[i] < INF) answer++;
		}

		cout << answer << endl;
	}
	void solution() {
		while (Q--) {
			int K, V; cin >> K >> V;

			vector<int> USADO = dijkstra(V);
			query(K, V, USADO);
		}
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, Q;
	cin >> N >> Q;

	MooTube* m = new MooTube(N, Q);
	m->solution();
	delete m;

	return 0;
}