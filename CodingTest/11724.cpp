#include <iostream>
#include <queue>

#define endl '\n'

using namespace std;

bool graph[1001][1001] = { false };
bool visit[1001] = { false };
int N, M;
int connected_component_count = 0;
queue<int> q;

void connectedComponent();
void bfs(int _node);

int main(int argc, char* argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	connectedComponent();

	return 0;
}

void connectedComponent() {
	cin >> N >> M;

	for (int loop1 = 0; loop1 < M; loop1++) {
		int input1, input2; cin >> input1 >> input2;
		graph[input1][input2] = true;
		graph[input2][input1] = true;
	}

	for (int loop1 = 1; loop1 <= N; loop1++)
		bfs(loop1);

	cout << connected_component_count << endl;
}

void bfs(int _node) {
	if (visit[_node] == true)
		return;
	else {
		connected_component_count++;
		q.push(_node);
		visit[q.front()] = true;

		while (!q.empty()) {
			for (int loop1 = 1; loop1 <= N; loop1++) {
				if (graph[q.front()][loop1] == true && visit[loop1] == false) {
					q.push(loop1);
					visit[loop1] = true;
				}
			}
			q.pop();
		}
	}
}