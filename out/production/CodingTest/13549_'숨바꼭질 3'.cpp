#include <iostream>
#include <queue>

#define endl '\n'
#define INFINITY 0x0FFFFFFF
#define MAX_SIZE 100001

using namespace std;

int N, K;
int dist[MAX_SIZE];

void bfs(int start);

int main(int argc, char* argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> K;

	bfs(N);

	cout << dist[K] << endl;

	return 0;
}

void bfs(int start) {
	int cnt = 1;
	for (int i = start + 1; i < MAX_SIZE; i++) dist[i] = cnt++;
	cnt = 1;
	for (int i = start - 1; i >= 0; i--) dist[i] = cnt++;

	queue<int> Q;

	dist[start] = 0;
	Q.push(start);

	while (!Q.empty()) {
		int current_position = Q.front();
		Q.pop();

		for (int teleport = current_position * 2; teleport < MAX_SIZE && teleport != 0; teleport *= 2) {
			if (dist[teleport] > dist[current_position]) {
				dist[teleport] = dist[current_position];
				Q.push(teleport);
			}
		}

		int walk_forward = current_position + 1;
		int walk_backward = current_position - 1;

		if (walk_backward >= 0 && dist[walk_backward] >= dist[current_position] + 1) {
			dist[walk_backward] = dist[current_position] + 1;
			Q.push(walk_backward);
		}
		if (walk_forward < MAX_SIZE && dist[walk_forward] >= dist[current_position] + 1) {
			dist[walk_forward] = dist[current_position] + 1;
			Q.push(walk_forward);
		}
	}
}