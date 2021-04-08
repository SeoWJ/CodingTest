#include <iostream>
#include <cstring>
#include <queue>

#define endl '\n'

using namespace std;

int map[27][27];
bool visit[27][27];
int village;

void BFS(int X, int Y);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	memset(map, 0, sizeof(map));
	memset(visit, false, sizeof(visit));
	village = 1;
	
	int N; cin >> N;

	for (int y = 1; y <= N; y++) {
		string input; cin >> input;

		for (int x = 1; x <= N; x++)
			map[y][x] = input[x - 1] - '0';
	}

	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {
			if (map[y][x] == 1 && visit[y][x] == false) {
				village++;
				BFS(x, y);
			}
		}
	}

	cout << village - 1 << endl;

	for (int i = 2; i <= village; i++) {
		int count = 0;

		for (int y = 1; y <= N; y++) {
			for (int x = 1; x <= N; x++) {
				if (map[y][x] == i) count++;
			}
		}

		cout << count << endl;
	}

	return 0;
}

void BFS(int X, int Y) {
	queue<pair<int, int>> Q;
	
	Q.push({ X, Y });
	visit[Y][X] = true;

	while (!Q.empty()) {
		int x = Q.front().first;
		int y = Q.front().second;
		map[y][x] = village;

		Q.pop();

		if (map[y + 1][x] == 1 && visit[y + 1][x] == false) {
			Q.push({ x, y + 1 });
			visit[y + 1][x] = true;
		}
		if (map[y - 1][x] == 1 && visit[y - 1][x] == false) {
			Q.push({ x, y - 1 });
			visit[y - 1][x] = true;
		}
		if (map[y][x + 1] == 1 && visit[y][x + 1] == false) {
			Q.push({ x + 1, y });
			visit[y][x + 1] = true;
		}
		if (map[y][x - 1] == 1 && visit[y][x - 1] == false) {
			Q.push({ x - 1, y });
			visit[y][x - 1] = true;
		}
	}
}