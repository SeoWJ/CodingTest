#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

#define APPLE 1
#define WALL 3

#define RIGHT 0
#define DOWN 1
#define LEFT 2
#define UP 3

#define turnRight(a) ((a + 1) % 4)
#define turnLeft(a) (a - 1 == -1 ? 3 : a - 1)

using namespace std;

typedef pair<int, int> Coordinate;

int N, K;
int board[102][102];
int snakeLimit;
queue<pair<int, char>> directionChange;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0 , -1 };

void play();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	memset(board, 0, sizeof(board));

	cin >> N >> K;

	for (int y = 0; y < 102; y++) {
		for (int x = 0; x < 102; x++) {
			if (y == 0 || x == 0 || x > N || y > N) board[y][x] = WALL;
		}
	}

	for (int i = 0; i < K; i++) {
		int y, x; cin >> y >> x;
		board[y][x] = APPLE;
	}

	int L; cin >> L;

	while (L--) {
		int time; char direction;
		cin >> time >> direction;

		directionChange.push({ time, direction });
	}

	play();

	return 0;
}

void play() {
	int time = 0;
	deque<Coordinate> snake;
	int direction = RIGHT;
	snakeLimit = 1;

	snake.push_back({ 1,1 });

	while (1) {
		time++;
		bool crash = false;

		int newHeadX = snake[snake.size() - 1].first + dx[direction];
		int newHeadY = snake[snake.size() - 1].second + dy[direction];

		if (board[newHeadY][newHeadX] == APPLE) {
			snakeLimit++;
			board[newHeadY][newHeadX] = 2;
		}
		else if (board[newHeadY][newHeadX] == WALL) {
			break;
		}
		else {
			for (unsigned int i = 0; i < snake.size(); i++) {
				if (newHeadX == snake[i].first && newHeadY == snake[i].second) {
					crash = true;
					break;
				}
			}
		}

		if (crash) break;

		snake.push_back({ newHeadX , newHeadY });
		board[newHeadY][newHeadX] = 2;
		
		while (snake.size() > snakeLimit) {
			board[snake.front().second][snake.front().first] = 0;
			snake.pop_front();
		}

		if (!directionChange.empty() && time == directionChange.front().first) {
			if (directionChange.front().second == 'L')
				direction = turnLeft(direction);
			else
				direction = turnRight(direction);

			directionChange.pop();
		}
	}

	cout << time << endl;
}