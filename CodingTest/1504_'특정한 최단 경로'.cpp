#include <iostream>
#include <vector>
#include <queue>

#define endl '\n'
#define INF 0x0FFFFFFF

using namespace std;

typedef pair<int, int> Edge;
typedef pair<int, int> Node;

int N, E;
int dist[3][801];
int midPoint1, midPoint2;

vector<Edge> edges[801];

void dijkstra(int distNum, int startPoint);

int main(int argc, char* argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> E;

	for (int i = 0; i < E; i++) {
		int start, destination, weight;
		cin >> start >> destination >> weight;

		edges[start].push_back({ weight, destination });
		edges[destination].push_back({ weight, start });
	}

	cin >> midPoint1 >> midPoint2;

	dijkstra(0, 1);
	dijkstra(1, midPoint1);
	dijkstra(2, midPoint2);

	int route1, route2;
	
	if (dist[0][midPoint1] == INF || dist[1][midPoint2] == INF || dist[2][N] == INF)
		route1 = -1;
	else
		route1 = dist[0][midPoint1] + dist[1][midPoint2] + dist[2][N];

	if (dist[0][midPoint2] == INF || dist[2][midPoint1] == INF || dist[1][N] == INF)
		route2 = -1;
	else
		route2 = dist[0][midPoint2] + dist[2][midPoint1] + dist[1][N];

	if (route1 == -1 && route2 == -1) cout << -1 << endl;
	else if (route1 == -1 && route2 != -1) cout << route2 << endl;
	else if (route1 != -1 && route2 == -1) cout << route1 << endl;
	else cout << (route1 > route2 ? route2 : route1) << endl;

	return 0;
}

void dijkstra(int distNum, int startPoint) {
	for (int i = 0; i < 801; i++) dist[distNum][i] = INF;
	dist[distNum][startPoint] = 0;

	priority_queue<Node, vector<Node>, greater<Node>> PQ;
	PQ.push({ 0, startPoint });

	while (!PQ.empty()) {
		int currentCost = PQ.top().first;
		int currentNode = PQ.top().second;

		PQ.pop();

		for (unsigned int i = 0; i < edges[currentNode].size(); i++) {
			int beforeDistance = dist[distNum][edges[currentNode][i].second];
			int newDistance = currentCost + edges[currentNode][i].first;

			if (newDistance < beforeDistance) {
				dist[distNum][edges[currentNode][i].second] = newDistance;
				PQ.push({ newDistance, edges[currentNode][i].second });
			}
		}
	}
}