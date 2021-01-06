#include <iostream>
#include <queue>
#include <vector>

#define endl '\n'
#define INFINITY 0x7FFFFFFF

using namespace std;

struct edge {
	int start;
	int destination;
	int weight;

	edge(int s, int d, int w) {
		start = s;
		destination = d;
		weight = w;
	}
};

struct vertex {
	bool visit = false;
	int dist = INFINITY;
	vector<edge> edge_list;
};

struct compare {
	bool operator() (edge& e1, edge& e2) {
		return e1.weight > e2.weight;
	}
};

int V, E, start;
vertex graph[20001];
int visit_count = 0;

void dijkstra(int start_point);

int main(int argc, char* argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> V >> E >> start;

	for (int i = 0; i < E; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		
		graph[u].edge_list.push_back(edge(u, v, w));
	}

	dijkstra(start);

	for (int i = 1; i <= V; i++) {
		if (graph[i].dist != INFINITY)
			cout << graph[i].dist << endl;
		else
			cout << "INF" << endl;
	}

	return 0;
}

void dijkstra(int start_point) {
	graph[start].dist = 0;
	graph[start].visit = true;
	visit_count++;

	priority_queue<edge, vector<edge>, compare> pq;

	for (unsigned int i = 0; i < graph[start_point].edge_list.size(); i++) {
		pq.push(graph[start_point].edge_list[i]);
	}

	while (!pq.empty() || visit_count == V) {
		int start = pq.top().start;
		int destination = pq.top().destination;
		int weight = pq.top().weight;

		pq.pop();

		if (graph[destination].visit == true)
			continue;
		else {
			graph[destination].visit = true;
			visit_count++;
			graph[destination].dist = graph[start].dist + weight;

			for (unsigned int i = 0; i < graph[destination].edge_list.size(); i++)
				pq.push(graph[destination].edge_list[i]);
		}
	}
}