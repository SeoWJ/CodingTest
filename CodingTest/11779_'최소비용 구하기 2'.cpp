#include <iostream>
#include <queue>
#include <vector>

#define endl '\n'
#define INF 0x0FFFFFFF

using namespace std;

typedef pair<int, int> Edge;
typedef pair<int, int> Node;
typedef pair<vector<int>, int> Distance;

int N, M;
vector<Edge> edges[1001];
Distance dist[1001];

void dijkstra(int startPoint);

int main(int argc, char* argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int start, destination, weight;
		cin >> start >> destination >> weight;

		edges[start].push_back({ weight, destination });
	}

	int start, destination;
	cin >> start >> destination;

	dijkstra(start);

	cout << dist[destination].second << endl;
	cout << dist[destination].first.size() << endl;
	
	for (unsigned int i = 0; i < dist[destination].first.size(); i++)
		cout << dist[destination].first[i] << " ";
	cout << endl;

	return 0;
}

void dijkstra(int startPoint) {
	for (int i = 0; i < 1001; i++) dist[i].second = INF;
	dist[startPoint].first.push_back(startPoint);
	dist[startPoint].second = 0;

	priority_queue<Node, vector<Node>, greater<Node>> PQ;

	PQ.push({ 0, startPoint });

	while (!PQ.empty()) {
		int currentCity = PQ.top().second;
		int currentCost = PQ.top().first;

		PQ.pop();

		for (unsigned int i = 0; i < edges[currentCity].size(); i++) {
			int nextCity = edges[currentCity][i].second;
			int cost = edges[currentCity][i].first;

			int beforeDistance = dist[nextCity].second;
			int newDistance = currentCost + cost;

			if (newDistance < beforeDistance) {
				dist[nextCity].first.clear();
				dist[nextCity].first = dist[currentCity].first;
				dist[nextCity].first.push_back(nextCity);
				dist[nextCity].second = newDistance;

				PQ.push({ newDistance, nextCity });
			}
		}
	}
}

