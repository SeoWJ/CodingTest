#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

vector<vector<int>> graph;
vector<pair<int, int>> dist;
bool visit[20001] = { false };

bool compare(pair<int, int> p1, pair<int, int> p2) { return p1.second > p2.second; }

int solution(int n, vector<vector<int>> edge) {
	int answer = 0;
	vector<int> temp;
	temp.assign(n + 1, 0);
	for (int y = 0; y <= n; y++) graph.push_back(temp);
	for (int x = 0; x <= n; x++) dist.push_back(make_pair(x, 0));
	queue<int> q;


	for (unsigned int y = 0; y < edge.size(); y++) {
		graph[edge[y][0]][edge[y][1]] = 1;
		graph[edge[y][1]][edge[y][0]] = 1;
	}

	q.push(1);
	visit[1] = true;
	while (!q.empty()) {
		for (unsigned int x = 0; x <= n; x++) {
			if (graph[q.front()][x] == 1 && visit[x] == false) {
				q.push(x);
				dist[x].second = dist[q.front()].second + 1;
				visit[x] = true;
			}
		}
		q.pop();
	}

	sort(dist.begin(), dist.end(), compare);

	if (dist[0].second == 0)
		return answer;

	int cnt = 1;
	for (unsigned int x = 1; x < dist.size(); x++) {
		if (dist[x].second == dist[x - 1].second) cnt++;
		else break;
	}

	answer = cnt;
	return answer;
}

int main() {
	int n = 2;
	vector<vector<int>> edge = {
		{1,2}
	};

	std::cout << solution(n, edge) << endl;

	return 0;
}