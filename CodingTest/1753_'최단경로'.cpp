#include <iostream>
#include <queue>
#include <vector>

#define endl '\n'
#define INFINITY 0x1FFFFFFF

using namespace std;

struct Edge {
	int destination;
	int weight;

	Edge(int d, int w) {
		destination = d;
		weight = w;
	}
};

int V, E, start_vertex;

vector<Edge> edges[20001];
int dist[20001] = { 0 };

void dijkstra(int start_vertex);

int main(int argc, char* argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> V >> E >> start_vertex;

	for (int i = 0; i < E; i++) {
		int start, destination, weight;
		cin >> start >> destination >> weight;

		edges[start].push_back(Edge(destination, weight));
	}

	for (int i = 1; i <= V; i++)
		dist[i] = INFINITY;

	dijkstra(start_vertex);

	for (int i = 1; i <= V; i++) {
		if (dist[i] != INFINITY)
			cout << dist[i] << endl;
		else
			cout << "INF" << endl;
	}

	return 0;
}

void dijkstra(int start_vertex) {
	dist[start_vertex] = 0;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0, start_vertex });

	while (!pq.empty()) {
		int current_node = pq.top().second;
		int cost = pq.top().first;

		pq.pop();

		for (unsigned int i = 0; i < edges[current_node].size(); i++) {
			int new_distance = dist[current_node] + edges[current_node][i].weight;
			int before_distance = dist[edges[current_node][i].destination];

			if (new_distance < before_distance) {
				dist[edges[current_node][i].destination] = new_distance;
				pq.push({ new_distance, edges[current_node][i].destination });
			}
		}
	}
}