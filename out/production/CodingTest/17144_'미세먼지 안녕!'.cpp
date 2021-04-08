#include <iostream>
#include <queue>
#include <vector>

#define endl '\n'
#define WALL -10
#define AIR_CLEANER -1

using namespace std;

int R, C, T;
int room[52][52];
vector<int> airCleanerPosition;

void solution();
void clear();
void spread();
void airFlow();
void printRoom();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	solution();

	return 0;
}

void solution() {
	cin >> R >> C >> T;

	clear();

	for (int y = 1; y <= R; y++) {
		for (int x = 1; x <= C; x++) {
			cin >> room[y][x];
			
			if (room[y][x] == AIR_CLEANER)
				airCleanerPosition.push_back(y);
		}
	}

	//printRoom();

	while (T--) {
		spread();

		//printRoom();

		airFlow();

		//printRoom();
	}

	int answer = 0;
	for (int y = 1; y <= R; y++) {
		for (int x = 1; x <= C; x++) {
			if (room[y][x] >= 0)
				answer += room[y][x];
		}
	}

	cout << answer << endl;
}

void spread() {
	queue<pair<pair<int, int>, int>> Q;
	for (int y = 1; y <= R; y++) {
		for (int x = 1; x <= C; x++) {
			if (room[y][x] > 0)
				Q.push({ { y, x }, room[y][x] / 5 });
		}
	}

	while (!Q.empty()) {
		int y = Q.front().first.first;
		int x = Q.front().first.second;

		int spreadAmount = Q.front().second;

		Q.pop();		

		if (spreadAmount == 0) continue;

		if (room[y + 1][x] != WALL && room[y + 1][x] != AIR_CLEANER) {
			room[y + 1][x] += spreadAmount;
			room[y][x] -= spreadAmount;
		}
		if (room[y - 1][x] != WALL && room[y - 1][x] != AIR_CLEANER) {
			room[y - 1][x] += spreadAmount;
			room[y][x] -= spreadAmount;
		}
		if (room[y][x + 1] != WALL && room[y][x + 1] != AIR_CLEANER) {
			room[y][x + 1] += spreadAmount;
			room[y][x] -= spreadAmount;
		}
		if (room[y][x - 1] != WALL && room[y][x - 1] != AIR_CLEANER) {
			room[y][x - 1] += spreadAmount;
			room[y][x] -= spreadAmount;
		}
	}
}

void airFlow() {
	for (int y = airCleanerPosition[0]; y > 1; y--) {
		if (room[y][1] == AIR_CLEANER) continue;
		else room[y][1] = room[y - 1][1];
	}
	for (int x = 1; x < C; x++) {
		if (room[1][x] == AIR_CLEANER) continue;
		else room[1][x] = room[1][x + 1];
	}
	for (int y = 1; y < airCleanerPosition[0]; y++)
		room[y][C] = room[y + 1][C];
	for (int x = C; x > 2; x--)
		room[airCleanerPosition[0]][x] = room[airCleanerPosition[0]][x - 1];
	room[airCleanerPosition[0]][2] = 0;

	for (int y = airCleanerPosition[1]; y < R; y++) {
		if (room[y][1] == AIR_CLEANER) continue;
		else room[y][1] = room[y + 1][1];
	}
	for (int x = 1; x < C; x++) {
		if (room[R][x] == AIR_CLEANER) continue;
		else room[R][x] = room[R][x + 1];
	}
	for (int y = R; y > airCleanerPosition[1]; y--)
		room[y][C] = room[y - 1][C];
	for (int x = C; x > 2; x--)
		room[airCleanerPosition[1]][x] = room[airCleanerPosition[1]][x - 1];
	room[airCleanerPosition[1]][2] = 0;
}

void clear() {
	for (int y = 0; y < 52; y++) {
		for (int x = 0; x < 52; x++) {
			if (y == 0 || x == 0 || y > R || x > C)
				room[y][x] = WALL;
			else
				room[y][x] = 0;
		}
	}
}

void printRoom() {
	for (int y = 1; y <= R; y++) {
		for (int x = 1; x <= C; x++) {
			cout << room[y][x] << '\t';
		}
		cout << endl;
	}
	cout << "---------------------------------------" << endl;
	cout << endl;
}