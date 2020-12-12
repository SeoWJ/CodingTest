#include <iostream>
#include <cstring>
#include <queue>

#define endl '\n'

using namespace std;

class coordinate {
public:
	int x, y, distance;
	coordinate(int _x, int _y, int _distance) {
		this->x = _x;
		this->y = _y;
		this->distance = _distance;
	}
};

char map[102][102] = { 0 };
int visit[102][102] = { 0 };
int N, M;

void mazeExplore();

int main(int argc, char* argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	mazeExplore();

	return 0;
}

void mazeExplore() {
	cin >> N >> M;

	for (int y = 1; y <= N; y++) {
		string input;
		cin >> input;
		for (int x = 1; x <= M; x++) {
			map[y][x] = input[x - 1];
		}
	}

	queue<coordinate> q;
	q.push(coordinate(1, 1, 1));
	visit[q.front().y][q.front().x] = q.front().distance;

	while (!q.empty()) {
		if (map[q.front().y + 1][q.front().x] == '1' && visit[q.front().y + 1][q.front().x] == 0) {
			q.push(coordinate(q.front().x, q.front().y + 1, q.front().distance + 1));
			visit[q.front().y + 1][q.front().x] = q.front().distance + 1;
		}
		if (map[q.front().y - 1][q.front().x] == '1' && visit[q.front().y - 1][q.front().x] == 0) {
			q.push(coordinate(q.front().x, q.front().y - 1, q.front().distance + 1));
			visit[q.front().y - 1][q.front().x] = q.front().distance + 1;
		}
		if (map[q.front().y][q.front().x + 1] == '1' && visit[q.front().y][q.front().x + 1] == 0) {
			q.push(coordinate(q.front().x + 1, q.front().y, q.front().distance + 1));
			visit[q.front().y][q.front().x + 1] = q.front().distance + 1;
		}
		if (map[q.front().y][q.front().x - 1] == '1' && visit[q.front().y][q.front().x - 1] == 0) {
			q.push(coordinate(q.front().x - 1, q.front().y, q.front().distance + 1));
			visit[q.front().y][q.front().x - 1] = q.front().distance + 1;
		}

		q.pop();
	}


	cout << visit[N][M] << endl;
}