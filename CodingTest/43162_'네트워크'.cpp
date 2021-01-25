// Sol 1.

/*#include <string>
#include <vector>
#include <queue>

using namespace std;

int answer;
int N;
vector<vector<int>> computerConnection;
bool visit[200] = { false };

void BFS(int computerNumber) {
	if (visit[computerNumber] == true) return;
	
	answer++;

	queue<int> Q;
	Q.push(computerNumber);

	while (!Q.empty()) {
		int currentComputer = Q.front();
		visit[currentComputer] = true;
		Q.pop();

		for (int i = 0; i < N; i++) {
			if (computerConnection[currentComputer][i] == 1 && visit[i] == false)
				Q.push(i);
		}
	}
}

int solution(int n, vector<vector<int>> computers) {
	answer = 0;
	N = n;
	computerConnection = computers;

	for (int i = 0; i < n; i++)
		BFS(i);

	return answer;
}*/