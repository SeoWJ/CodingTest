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
	for (int i = 0; i < MAX_SIZE; i++)
		dist[i] = INFINITY;
	
	queue<int> Q;

	dist[start] = 0;
	Q.push(start);

	while (!Q.empty()) {
		int current = Q.front();
		Q.pop();

		for (int i = current; i < MAX_SIZE; i *= 2) {
			dist[i] = dist[current];
			if (i == K) return;

			if (i + 1 < MAX_SIZE && dist[i + 1] > dist[current] + 1) {
				dist[i + 1] = dist[current] + 1;
				if (i + 1 == K) return;
				Q.push(i + 1);
			}
			if (i - 1 >= 0 && dist[i - 1] > dist[current] + 1) {
				dist[i - 1] = dist[current] + 1;
				if (i - 1 == K) return;
				Q.push(i - 1);
			}

			if (i == 0)
				break;
		}
	}
}