#include <string>
#include <vector>
#include <queue>

using namespace std;

bool visit[200] = { false };
int answer = 0;

void BFS(int computer, vector<vector<int>> computers) {
	if (visit[computer] == true)
		return;
	else {
		answer++;
		queue<int> q;
		q.push(computer);

		while (!q.empty()) {
			for (unsigned int x = 0; x < computers.size(); x++) {
				if (computers[q.front()][x] == 1 && visit[x] == false) {
					q.push(x);
					visit[x] = true;
				}
			}
			q.pop();
		}
	}
}

int solution(int n, vector<vector<int>> computers) {
	for (int x = 0; x < n; x++)
		BFS(x, computers);

	return answer;
}