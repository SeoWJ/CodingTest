#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

struct Player {
	deque<int> lose;
	deque<int> win;
};

int answer = 0;
Player playerArr[101];
bool visit[101] = { false };

void clear() { for (int i = 0; i < 101; i++) visit[i] = false; }

void DFS_up(int startNode) {
	visit[startNode] = true;

	for (unsigned int i = 0; i < playerArr[startNode].lose.size(); i++) {
		if (visit[playerArr[startNode].lose[i]] == false)
			DFS_up(playerArr[startNode].lose[i]);
	}
}

void DFS_down(int startNode) {
	visit[startNode] = true;

	for (unsigned int i = 0; i < playerArr[startNode].win.size(); i++) {
		if (visit[playerArr[startNode].win[i]] == false)
			DFS_down(playerArr[startNode].win[i]);
	}
}

int solution(int n, vector<vector<int>> results) {
	for (unsigned int i = 0; i < results.size(); i++) {
		int winner = results[i][0];
		int loser = results[i][1];

		playerArr[winner].win.push_back(loser);
		playerArr[loser].lose.push_back(winner);
	}

	for (int i = 1; i <= n; i++) {
		clear();
		DFS_up(i);
		DFS_down(i);

		bool allVisit = true;
		for (int i = 1; i <= n; i++) {
			if (visit[i] == false)
				allVisit = false;
		}

		if (allVisit) answer++;
	}

	return answer;
}

int main() {
	cout << solution(5, { {4,3}, {4,2}, {3,2} , {1,2}, {2,5} }) << endl;
}