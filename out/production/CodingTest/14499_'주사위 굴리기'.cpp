#include <iostream>
#include <cstring>

#define endl '\n'
#define diceTop dice[1][1]
#define diceBottom dice[3][1]

#define RIGHT 1
#define LEFT 2
#define UP 3
#define DOWN 4

#define WALL 11

using namespace std;

int dice[4][3] = {
	{0,0,0},
	{0,0,0},
	{0,0,0},
	{0,0,0}
};

int N, M, K;
int X, Y;
int map[22][22];

void turnRight();
void turnLeft();
void turnUp();
void turnDown();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for (int y = 0; y < 22; y++) {
		for (int x = 0; x < 22; x++) map[y][x] = WALL;
	}

	cin >> N >> M >> Y >> X >> K;
	X++; Y++;

	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= M; x++)
			cin >> map[y][x];
	}

	while (K--) {
		int order; cin >> order;

		if (order == LEFT) {
			if (map[Y][X - 1] == WALL) continue;
			else {
				turnLeft();
				X--;
				
				if (map[Y][X] == 0) map[Y][X] = diceBottom;
				else {
					diceBottom = map[Y][X];
					map[Y][X] = 0;
				}

				cout << diceTop << endl;
			}
		}
		else if (order == RIGHT) {
			if (map[Y][X + 1] == WALL) continue;
			else {
				turnRight();
				X++;

				if (map[Y][X] == 0) map[Y][X] = diceBottom;
				else {
					diceBottom = map[Y][X];
					map[Y][X] = 0;
				}

				cout << diceTop << endl;
			}
		}
		else if (order == UP) {
			if (map[Y - 1][X] == WALL) continue;
			else {
				turnUp();
				Y--;

				if (map[Y][X] == 0) map[Y][X] = diceBottom;
				else {
					diceBottom = map[Y][X];
					map[Y][X] = 0;
				}

				cout << diceTop << endl;
			}
		}
		else if (order == DOWN) {
			if (map[Y + 1][X] == WALL) continue;
			else {
				turnDown();
				Y++;

				if (map[Y][X] == 0) map[Y][X] = diceBottom;
				else {
					diceBottom = map[Y][X];
					map[Y][X] = 0;
				}

				cout << diceTop << endl;
			}
		}
	}

	return 0;
}

void turnRight() {
	int temp = dice[1][2];
	dice[1][2] = dice[1][1];
	dice[1][1] = dice[1][0];
	dice[1][0] = dice[3][1];
	dice[3][1] = temp;
}
void turnLeft() {
	int temp = dice[1][0];
	dice[1][0] = dice[1][1];
	dice[1][1] = dice[1][2];
	dice[1][2] = dice[3][1];
	dice[3][1] = temp;
}
void turnUp() {
	int temp = dice[0][1];
	dice[0][1] = dice[1][1];
	dice[1][1] = dice[2][1];
	dice[2][1] = dice[3][1];
	dice[3][1] = temp;
}
void turnDown() {
	int temp = dice[3][1];
	dice[3][1] = dice[2][1];
	dice[2][1] = dice[1][1];
	dice[1][1] = dice[0][1];
	dice[0][1] = temp;
}