#include <iostream>
#include <queue>

#define endl '\n'

using namespace std;

typedef pair<pair<int, int>, char> Pipe;	// (x,y), h/v/d 가로/세로/대각선

int N;
int map[18][18];

void clearMap(int N);

int main(int argc, char* argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int answer = 0;

	cin >> N;

	clearMap(N);

	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {
			cin >> map[y][x];
		}
	}

	queue<Pipe> Q;

	Q.push({ {2, 1}, 'h' });

	while (!Q.empty()) {
		int x = Q.front().first.first;
		int y = Q.front().first.second;
		char direction = Q.front().second;

		Q.pop();

		if (x == N && y == N) {
			answer++;
			continue;
		}
		else {
			if (direction == 'h') {
				if (map[y][x + 1] != 1) 
					Q.push({ {x + 1, y}, 'h' });
				if (map[y][x + 1] != 1 && map[y + 1][x + 1] != 1 && map[y + 1][x] != 1) 
					Q.push({ {x + 1, y + 1}, 'd' });
			}
			else if (direction == 'v') {
				if (map[y + 1][x] != 1)
					Q.push({ {x, y + 1}, 'v' });
				if (map[y][x + 1] != 1 && map[y + 1][x + 1] != 1 && map[y + 1][x] != 1)
					Q.push({ {x + 1, y + 1}, 'd' });
			}
			else { // direction == 'd'
				if (map[y][x + 1] != 1)
					Q.push({ {x + 1, y}, 'h' });
				if (map[y + 1][x] != 1)
					Q.push({ {x, y + 1}, 'v' });
				if (map[y][x + 1] != 1 && map[y + 1][x + 1] != 1 && map[y + 1][x] != 1)
					Q.push({ {x + 1, y + 1}, 'd' });
			}
		}
	}

	cout << answer << endl;

	return 0;
}

void clearMap(int N) {
	for (int y = 0; y < 18; y++) {
		for (int x = 0; x < 18; x++) {
			if (y == 0 || x == 0 || x > N || y > N) map[y][x] = 1;
			else map[y][x] = 0;
		}
	}
}