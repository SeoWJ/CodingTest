#include <string>
#include <vector>
#include <iostream>
#include <queue>

#define INFINITY 0x7FFFFFFF

using namespace std;

deque<int> edges[20001];
int distanceArr[20001] = { 0 };

void clear() {
	for (int i = 0; i < 20001; i++) distanceArr[i] = INFINITY;
}

void DFS(int startNode, int dist) {
	distanceArr[startNode] = dist;

	for (unsigned int i = 0; i < edges[startNode].size(); i++) {
		if (distanceArr[edges[startNode][i]] > dist + 1)
			DFS(edges[startNode][i], dist + 1);
	}
}

int solution(int n, vector<vector<int>> edge) {
	clear();

	int answer = 0;

	for (unsigned int i = 0; i < edge.size(); i++) {
		int start = edge[i][0];
		int end = edge[i][1];

		edges[start].push_back(end);
		edges[end].push_back(start);
	}

	DFS(1, 0);

	int maxDistance = 0;
	for (int i = 1; i <= n; i++) {
		if (distanceArr[i] != INFINITY)
			maxDistance = maxDistance > distanceArr[i] ? maxDistance : distanceArr[i];
	}

	for (int i = 1; i <= n; i++) {
		if (distanceArr[i] == maxDistance)
			answer++;
	}

	return answer;
}

int main() {
	cout << solution(6, {{3, 6}, {4, 3}, {3, 2}, {1, 3}, {1, 2}, {2, 4}, {5, 2}} ) << endl;
}