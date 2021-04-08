#include <iostream>
#include <queue>

#define endl '\n'

using namespace std;

struct Coordinate{
	int x;
	int y;

	Coordinate(int _x, int _y) {
		x = _x;
		y = _y;
	}
};

int M, N;
int tomato[1002][1002];
bool visit[1002][1002];

void clear();
int solution();

int main(int argc, char* argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	clear();

	cin >> M >> N;

	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= M; x++)
			cin >> tomato[y][x];
	}

	cout << solution() << endl;

	return 0;
}

int solution() {
	queue<Coordinate> Q;

	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= M; x++) {
			if (tomato[y][x] == 1) {
				Q.push(Coordinate(x, y));
				visit[y][x] = true;
			}
		}
	}

	while (!Q.empty()) {
		int x = Q.front().x;
		int y = Q.front().y;
		Q.pop();

		if (tomato[y + 1][x] == 0 && visit[y + 1][x] == false) {
			tomato[y + 1][x] = tomato[y][x] + 1;
			visit[y + 1][x] = true;
			Q.push(Coordinate(x, y + 1));
		}
		if (tomato[y - 1][x] == 0 && visit[y - 1][x] == false) {
			tomato[y - 1][x] = tomato[y][x] + 1;
			visit[y - 1][x] = true;
			Q.push(Coordinate(x, y - 1));
		}
		if (tomato[y][x + 1] == 0 && visit[y][x + 1] == false) {
			tomato[y][x + 1] = tomato[y][x] + 1;
			visit[y][x + 1] = true;
			Q.push(Coordinate(x + 1, y));
		}
		if (tomato[y][x - 1] == 0 && visit[y][x - 1] == false) {
			tomato[y][x - 1] = tomato[y][x] + 1;
			visit[y][x - 1] = true;
			Q.push(Coordinate(x - 1, y));
		}
	}

	int result = 0;
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= M; x++) {
			if (tomato[y][x] == 0)
				return -1;
			result = result > tomato[y][x] ? result : tomato[y][x];
		}
	}

	return result - 1;
}

void clear() {
	for (int y = 0; y < 1002; y++) {
		for (int x = 0; x < 1002; x++) {
			tomato[y][x] = -1;
			visit[y][x] = false;
		}
	}
}