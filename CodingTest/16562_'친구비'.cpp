#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>

#define endl '\n'

using namespace std;

int N, M, K;
bool visit[10001];
vector<int> friendCost;
vector<int> edges[10001];

vector<vector<int>> makeGroup();
vector<int> BFS(int startPoint);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M >> K;

	friendCost.assign(N + 1, 0);
	memset(visit, false, sizeof(visit));

	for (int i = 1; i <= N; i++) cin >> friendCost[i];

	for (int i = 0; i < M; i++) {
		int v, w; cin >> v >> w;
		
		edges[v].push_back(w);
		edges[w].push_back(v);
	}

	vector<vector<int>> friendGroup = makeGroup();

	int totalCost = 0;
	for (unsigned int i = 0; i < friendGroup.size(); i++) {
		totalCost += friendGroup[i][0];
	}

	if (totalCost > K)
		cout << "Oh no" << endl;
	else
		cout << totalCost << endl;
	
	return 0;
}

vector<vector<int>> makeGroup() {
	vector<vector<int>> result;

	for (int i = 1; i <= N; i++) {
		if (visit[i] == false) {
			vector<int> group = BFS(i);
			result.push_back(group);
		}
	}

	return result;
}

vector<int> BFS(int startPoint) {
	vector<int> result;
	queue<int> Q;
	
	Q.push(startPoint);

	while (!Q.empty()) {
		int currentNode = Q.front();

		Q.pop();

		visit[currentNode] = true;
		result.push_back(friendCost[currentNode]);

		for (unsigned int i = 0; i < edges[currentNode].size(); i++) {
			if (visit[edges[currentNode][i]] == false)
				Q.push(edges[currentNode][i]);
		}
	}

	sort(result.begin(), result.end());

	return result;
}