// Sol 1.

/*#include <string>
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
}*/

// Sol. 2

#include <string>
#include <vector>
#include <queue>
#include <iostream>

#define INF 0x0FFFFFFF

using namespace std;

typedef pair<int, int> Node;

vector<int> edges[20001];
int distanceArray[20001];

void dijkstra(int startPoint);

int solution(int n, vector<vector<int>> edge) {
	int answer = 0;

	for (unsigned int i = 0; i < edge.size(); i++) {
		int start = edge[i][0];
		int destination = edge[i][1];

		edges[start].push_back(destination);
		edges[destination].push_back(start);
	}

	dijkstra(1);

	int maxDistance = 0;
	for (int i = 0; i < 20001; i++)
		maxDistance = distanceArray[i] > maxDistance && distanceArray[i] != INF ? distanceArray[i] : maxDistance;

	for (int i = 0; i < 20001; i++) {
		if (distanceArray[i] == maxDistance) answer++;
	}

	return answer;
}

void dijkstra(int startPoint) {
	for (int i = 0; i < 20001; i++) distanceArray[i] = INF;
	distanceArray[startPoint] = 0;

	priority_queue<Node, vector<Node>, greater<Node>> PQ;
	PQ.push({ 0, startPoint });

	while (!PQ.empty()) {
		int currentNode = PQ.top().second;
		int currentCost = PQ.top().first;

		PQ.pop();

		for (unsigned int i = 0; i < edges[currentNode].size(); i++) {
			int nextNode = edges[currentNode][i];

			if (currentCost + 1 < distanceArray[nextNode]) {
				distanceArray[nextNode] = currentCost + 1;
				PQ.push({ currentCost + 1, nextNode });
			}
		}
	}
}