#include <iostream>
#include <queue>

#define endl '\n'

using namespace std;

class Coordinate {
public:
	int X, Y, direction;
	Coordinate(int X, int Y, int direction) {
		this->X = X;
		this->Y = Y;
		this->direction = direction;
	}
};

int map[106][106];

void robot();
void clearMap();

int main(int argc, char* argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	robot();

	return 0;
}

void robot() {
	clearMap();

	int M, N; cin >> M >> N;

	for (int y = 0 + 3; y <= M + 3; y++) {
		for (int x = 0 + 3; x <= N + 3; x++) {
			cin >> map[y][x];
			if (map[y][x] == 1)
				map[y][x] = -1;
		}
	}

	int pos_Y, pos_X, current_direction;
	cin >> pos_Y >> pos_X >> current_direction;

	int target_Y, target_X, target_direction;
	cin >> target_Y >> target_X >> target_direction;

	queue<Coordinate> Q;
	Coordinate c(pos_X + 3, pos_Y + 3, current_direction);
	Q.push(c);

	while (!Q.empty()) {
		Coordinate cur = Q.front();
		Q.pop();

		if (cur.direction == 1) {
			for (int step = 1; step <= 3; step++) {
				if (map[cur.Y][cur.X + step] == 0) {
					map[cur.Y][cur.X + step] = map[cur.Y][cur.X] + 1;
				}
				if (map[cur.Y][cur.X - step] == 0) {
					map[cur.Y][cur.X - step] = map[cur.Y][cur.X] + 3;
				}
				if (map[cur.Y + step][cur.X] == 0) {
					map[cur.Y + step][cur.X] = map[cur.Y][cur.X] + 2;
				}
				if (map[cur.Y - step][cur.X] == 0) {
					map[cur.Y - step][cur.X] = map[cur.Y][cur.X] + 2;
				}
			}
		}
	}
}

void clearMap() {
	for (int y = 0; y < 102; y++) {
		for (int x = 0; x < 102; x++)
			map[y][x] = -1;
	}
}