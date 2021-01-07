#include <iostream>
#include <queue>
#include <vector>

#define endl '\n'
#define INFINITY 101

using namespace std;

struct Edge {
	int destination;
	int weight;

	Edge(int d, int w) {
		destination = d;
		weight = w;
	}
};

vector<Edge> edges[10001];
int dist[10001];
bool isLeaf[10001] = { false };

void dijkstra(int start_vertex, int dist[]);

int main(int argc, char* argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	int input;
	vector<int> temp;

	while (cin >> input) {
		temp.push_back(input);

		if (temp.size() == 3) {
			edges[temp[0]].push_back(Edge(temp[1], temp[2]));
			edges[temp[1]].push_back(Edge(temp[0], temp[2]));

			temp.clear();
		}
	}

	/*while (1) {
		cin >> input;
		if (input == -1) break;

		temp.push_back(input);

		if (temp.size() == 3) {
			edges[temp[0]].push_back(Edge(temp[1], temp[2]));
			edges[temp[1]].push_back(Edge(temp[0], temp[2]));

			temp.clear();
		}
	}*/

	int tree_diameter = 0;

	for (int i = 1; i <= n; i++) {
		dijkstra(i, dist);

		for (int j = 1; j <= n; j++)
			tree_diameter = tree_diameter > dist[j] ? tree_diameter : dist[j];
	}

	cout << tree_diameter << endl;

	return 0;
}

void dijkstra(int start_vertex, int dist[]) {
	for (int i = 0; i < 10001; i++)
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