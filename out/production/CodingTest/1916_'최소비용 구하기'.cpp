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

int N, M;
int start_vertex, destination_vertex;
vector<Edge> edges[1001];
int dist[1001];

void dijkstra(int start_vertex);

int main(int argc, char* argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int start, destination, weight;
		cin >> start >> destination >> weight;

		edges[start].push_back(Edge(destination, weight));
	}

	cin >> start_vertex >> destination_vertex;

	dijkstra(start_vertex);

	cout << dist[destination_vertex] << endl;

	return 0;
}

void dijkstra(int start_vertex) {
	for (int i = 0; i < 1001; i++)
		dist[i] = INFINITY;

	dist[start_vertex] = 0;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	pq.push({ 0, start_vertex });

	while (!pq.empty()) {
		int next_vertex = pq.top().second;
		
		pq.pop();

		for (unsigned int i = 0; i < edges[next_vertex].size(); i++) {
			int before_distance = dist[edges[next_vertex][i].destination];
			int new_distance = dist[next_vertex] + edges[next_vertex][i].weight;

			if (before_distance > new_distance) {
				dist[edges[next_vertex][i].destination] = new_distance;
				pq.push({ new_distance, edges[next_vertex][i].destination });
			}
		}
	}
}