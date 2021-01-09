#include <iostream>
#include <queue>

#define endl '\n'

using namespace std;

int N;

vector<int> connection[100001];
bool visit[100001] = { false };
int answer[100001] = { 0 };

void DFS(int start);

int main(int argc, char* argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;

	for (int i = 0; i < N-1; i++) {
		int inp1, inp2;
		cin >> inp1 >> inp2;

		connection[inp1].push_back(inp2);
		connection[inp2].push_back(inp1);
	}

	DFS(1);

	for (int i = 0; i < 100001; i++) {
		if (answer[i] != 0)
			cout << answer[i] << endl;
	}

	return 0;
}

void DFS(int start) {
	visit[start] = true;

	for (unsigned int i = 0; i < connection[start].size(); i++) {
		if (visit[connection[start][i]] == false) {
			answer[connection[start][i]] = start;
			DFS(connection[start][i]);
		}
	}
}