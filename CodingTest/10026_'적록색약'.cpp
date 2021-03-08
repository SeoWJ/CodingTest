#include <iostream>
#include <queue>
#include <cstring>

#define endl '\n'

using namespace std;

int N;
char map[102][102];
bool visit[102][102];
bool blindVisit[102][102];

void BFS(int X, int Y);
void blindBFS(int X, int Y);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int count = 0, blindCount = 0;

	cin >> N;

	memset(map, 'W', sizeof(map));
	memset(visit, false, sizeof(visit));
	memset(blindVisit, false, sizeof(blindVisit));

	for (int y = 1; y <= N; y++) {
		string input; cin >> input;

		for (unsigned int x = 0; x < input.size(); x++)
			map[y][x + 1] = input[x];
	}

	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {
			if (visit[y][x] == false) {
				count++;
				BFS(x, y);
			}
			if (blindVisit[y][x] == false) {
				blindCount++;
				blindBFS(x, y);
			}
		}
	}

	cout << count << " " << blindCount << endl;

	return 0;
}

void BFS(int X, int Y) {
	queue<pair<int, int>> Q;
	Q.push({ X,Y });
	visit[Y][X] = true;
	char targetColor = map[Y][X];

	while (!Q.empty()) {
		int x = Q.front().first;
		int y = Q.front().second;

		Q.pop();

		if (map[y + 1][x] == targetColor && visit[y + 1][x] == false) {
			visit[y + 1][x] = true;
			Q.push({ x, y + 1 });
		}
		if (map[y - 1][x] == targetColor && visit[y - 1][x] == false) {
			visit[y - 1][x] = true;
			Q.push({ x, y - 1 });
		}
		if (map[y][x + 1] == targetColor && visit[y][x + 1] == false) {
			visit[y][x + 1] = true;
			Q.push({ x + 1, y });
		}
		if (map[y][x - 1] == targetColor && visit[y][x - 1] == false) {
			visit[y][x - 1] = true;
			Q.push({ x - 1, y });
		}
	}
}

void blindBFS(int X, int Y) {
	queue<pair<int, int>> Q;
	Q.push({ X,Y });
	blindVisit[Y][X] = true;
	char targetColor = map[Y][X];
	if (targetColor == 'B') {
		while (!Q.empty()) {
			int x = Q.front().first;
			int y = Q.front().second;

			Q.pop();

			if (map[y + 1][x] == targetColor && blindVisit[y + 1][x] == false) {
				blindVisit[y + 1][x] = true;
				Q.push({ x, y + 1 });
			}
			if (map[y - 1][x] == targetColor && blindVisit[y - 1][x] == false) {
				blindVisit[y - 1][x] = true;
				Q.push({ x, y - 1 });
			}
			if (map[y][x + 1] == targetColor && blindVisit[y][x + 1] == false) {
				blindVisit[y][x + 1] = true;
				Q.push({ x + 1, y });
			}
			if (map[y][x - 1] == targetColor && blindVisit[y][x - 1] == false) {
				blindVisit[y][x - 1] = true;
				Q.push({ x - 1, y });
			}
		}
	}
	else if (targetColor == 'R' || targetColor == 'G') {
		while (!Q.empty()) {
			int x = Q.front().first;
			int y = Q.front().second;

			Q.pop();

			if ((map[y + 1][x] == 'R' || map[y + 1][x] == 'G') && blindVisit[y + 1][x] == false) {
				blindVisit[y + 1][x] = true;
				Q.push({ x, y + 1 });
			}
			if ((map[y - 1][x] == 'R' || map[y - 1][x] == 'G') && blindVisit[y - 1][x] == false) {
				blindVisit[y - 1][x] = true;
				Q.push({ x, y - 1 });
			}
			if ((map[y][x + 1] == 'R' || map[y][x + 1] == 'G') && blindVisit[y][x + 1] == false) {
				blindVisit[y][x + 1] = true;
				Q.push({ x + 1, y });
			}
			if ((map[y][x - 1] == 'R' || map[y][x - 1] == 'G') && blindVisit[y][x - 1] == false) {
				blindVisit[y][x - 1] = true;
				Q.push({ x - 1, y });
			}
		}
	}
}