#include <string>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, pair<int, int>> Edge;

deque<Edge> edges[100];
deque<Edge> MST[100];

int solution(int n, vector<vector<int>> costs) {
	int answer = 0;

	priority_queue<Edge, vector<Edge>, greater<Edge>> PQ;
	bool visit[100] = { false };

	for (unsigned int i = 0; i < costs.size(); i++) {
		int start = costs[i][0];
		int end = costs[i][1];
		int weight = costs[i][2];

		edges[start].push_back({ weight, { start, end } });
		edges[end].push_back({ weight, { end, start } });
	}

	visit[0] = true;
	for (unsigned int i = 0; i < edges[0].size(); i++) {
		PQ.push(edges[0][i]);
	}

	while (!PQ.empty()) {
		int start = PQ.top().second.first;
		int destination = PQ.top().second.second;
		int weight = PQ.top().first;

		PQ.pop();

		if (visit[destination] == false) {
			visit[destination] = true;
			MST[start].push_back({ weight, {start, destination} });
			answer += weight;

			for (unsigned int i = 0; i < edges[destination].size(); i++)
				PQ.push(edges[destination][i]);
		}
	}

	return answer;
}