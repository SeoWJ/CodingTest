#include <iostream>
#include <queue>

#define endl '\n'

using namespace std;

int V, E;
vector<pair<int, int>> connection[10001];
bool visit[10001] = { false };

int prim(int start);

int main(int argc, char* argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> V >> E;

	for (int i = 0; i < E; i++) {
		int from, to, weight;
		cin >> from >> to >> weight;
		connection[from].push_back(make_pair(weight, to));
		connection[to].push_back(make_pair(weight, from));
	}

	cout << prim(1) << endl;

	return 0;
}

int prim(int start) {
	priority_queue< pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
	int total_weight = 0;

	visit[1] = true;

	for (unsigned int i = 0; i < connection[1].size(); i++)
		pq.push(connection[1][i]);

	while (1) {
		if (visit[pq.top().second] == true) {
			pq.pop();
			continue;
		}
		else {
			int destination = pq.top().second;
			int weight = pq.top().first;
			pq.pop();

			visit[destination] = true;
			total_weight += weight;

			for (unsigned int i = 0; i < connection[destination].size(); i++)
				pq.push(connection[destination][i]);

			bool finish = true;
			for (int i = 1; i <= V; i++) {
				if (visit[i] == false)
					finish = false;
			}

			if (finish)
				break;
		}
	}

	return total_weight;
}