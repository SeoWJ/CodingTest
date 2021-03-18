#include <iostream>
#include <cstring>
#include <queue>
#include <vector>

#define endl '\n'

#define WALL 6

using namespace std;

typedef vector<vector<int>> Map;

int N, M;
int answer = 0x7FFFFFFF;
Map map;

void bruteForce(Map map, deque<pair<int, int>> cameraQueue);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	vector<int> row(10, 6);
	map.assign(10, row);

	cin >> N >> M;

	deque<pair<int, int>> cameraQueue;

	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= M; x++) {
			cin >> map[y][x];

			if (1 <= map[y][x] && map[y][x] <= 5)
				cameraQueue.push_back({ x, y });
		}
	}

	bruteForce(map, cameraQueue);

	cout << answer << endl;

	return 0;
}

void bruteForce(Map map, deque<pair<int, int>> cameraQueue) {
	if (cameraQueue.empty()) {
		int unablePoint = 0;

		for (int y = 1; y <= N; y++) {
			for (int x = 1; x <= M; x++) {
				if (map[y][x] == 0) unablePoint++;
			}
		}

		answer = answer < unablePoint ? answer : unablePoint;

		return;
	}

	int x = cameraQueue.front().first;
	int y = cameraQueue.front().second;
	int camera = map[y][x];

	cameraQueue.pop_front();

	Map cpyMap;

	if (camera == 1) {
		cpyMap = map;
		for (int xx = x + 1; xx <= M; xx++) {
			if (cpyMap[y][xx] == 0) cpyMap[y][xx] = 7;
			else if (cpyMap[y][xx] == 6) break;
			else continue;
		}
		bruteForce(cpyMap, cameraQueue);

		cpyMap = map;
		for (int xx = x - 1; xx > 0; xx--) {
			if (cpyMap[y][xx] == 0) cpyMap[y][xx] = 7;
			else if (cpyMap[y][xx] == 6) break;
			else continue;
		}
		bruteForce(cpyMap, cameraQueue);

		cpyMap = map;
		for (int yy = y + 1; yy <= N; yy++) {
			if (cpyMap[yy][x] == 0) cpyMap[yy][x] = 7;
			else if (cpyMap[yy][x] == 6) break;
			else continue;
		}
		bruteForce(cpyMap, cameraQueue);

		cpyMap = map;
		for (int yy = y - 1; yy > 0; yy--) {
			if (cpyMap[yy][x] == 0) cpyMap[yy][x] = 7;
			else if (cpyMap[yy][x] == 6) break;
			else continue;
		}
		bruteForce(cpyMap, cameraQueue);
	}
	else if (camera == 2) {
		cpyMap = map;
		for (int xx = x + 1; xx <= M; xx++) {
			if (cpyMap[y][xx] == 0) cpyMap[y][xx] = 7;
			else if (cpyMap[y][xx] == 6) break;
			else continue;
		}
		for (int xx = x - 1; xx > 0; xx--) {
			if (cpyMap[y][xx] == 0) cpyMap[y][xx] = 7;
			else if (cpyMap[y][xx] == 6) break;
			else continue;
		}
		bruteForce(cpyMap, cameraQueue);

		cpyMap = map;
		for (int yy = y + 1; yy <= N; yy++) {
			if (cpyMap[yy][x] == 0) cpyMap[yy][x] = 7;
			else if (cpyMap[yy][x] == 6) break;
			else continue;
		}
		for (int yy = y - 1; yy > 0; yy--) {
			if (cpyMap[yy][x] == 0) cpyMap[yy][x] = 7;
			else if (cpyMap[yy][x] == 6) break;
			else continue;
		}
		bruteForce(cpyMap, cameraQueue);
	}
	else if (camera == 3) {
		cpyMap = map;
		for (int xx = x + 1; xx <= M; xx++) {
			if (cpyMap[y][xx] == 0) cpyMap[y][xx] = 7;
			else if (cpyMap[y][xx] == 6) break;
			else continue;
		}
		for (int yy = y - 1; yy > 0; yy--) {
			if (cpyMap[yy][x] == 0) cpyMap[yy][x] = 7;
			else if (cpyMap[yy][x] == 6) break;
			else continue;
		}
		bruteForce(cpyMap, cameraQueue);

		cpyMap = map;
		for (int yy = y - 1; yy > 0; yy--) {
			if (cpyMap[yy][x] == 0) cpyMap[yy][x] = 7;
			else if (cpyMap[yy][x] == 6) break;
			else continue;
		}
		for (int xx = x - 1; xx > 0; xx--) {
			if (cpyMap[y][xx] == 0) cpyMap[y][xx] = 7;
			else if (cpyMap[y][xx] == 6) break;
			else continue;
		}
		bruteForce(cpyMap, cameraQueue);

		cpyMap = map;
		for (int xx = x - 1; xx > 0; xx--) {
			if (cpyMap[y][xx] == 0) cpyMap[y][xx] = 7;
			else if (cpyMap[y][xx] == 6) break;
			else continue;
		}
		for (int yy = y + 1; yy <= N; yy++) {
			if (cpyMap[yy][x] == 0) cpyMap[yy][x] = 7;
			else if (cpyMap[yy][x] == 6) break;
			else continue;
		}
		bruteForce(cpyMap, cameraQueue);

		cpyMap = map;
		for (int yy = y + 1; yy <= N; yy++) {
			if (cpyMap[yy][x] == 0) cpyMap[yy][x] = 7;
			else if (cpyMap[yy][x] == 6) break;
			else continue;
		}
		for (int xx = x + 1; xx <= M; xx++) {
			if (cpyMap[y][xx] == 0) cpyMap[y][xx] = 7;
			else if (cpyMap[y][xx] == 6) break;
			else continue;
		}
		bruteForce(cpyMap, cameraQueue);
	}
	else if (camera == 4) {
		cpyMap = map;
		for (int xx = x + 1; xx <= M; xx++) {
			if (cpyMap[y][xx] == 0) cpyMap[y][xx] = 7;
			else if (cpyMap[y][xx] == 6) break;
			else continue;
		}
		for (int yy = y - 1; yy > 0; yy--) {
			if (cpyMap[yy][x] == 0) cpyMap[yy][x] = 7;
			else if (cpyMap[yy][x] == 6) break;
			else continue;
		}
		for (int xx = x - 1; xx > 0; xx--) {
			if (cpyMap[y][xx] == 0) cpyMap[y][xx] = 7;
			else if (cpyMap[y][xx] == 6) break;
			else continue;
		}
		bruteForce(cpyMap, cameraQueue);

		cpyMap = map;
		for (int yy = y - 1; yy > 0; yy--) {
			if (cpyMap[yy][x] == 0) cpyMap[yy][x] = 7;
			else if (cpyMap[yy][x] == 6) break;
			else continue;
		}
		for (int xx = x - 1; xx > 0; xx--) {
			if (cpyMap[y][xx] == 0) cpyMap[y][xx] = 7;
			else if (cpyMap[y][xx] == 6) break;
			else continue;
		}
		for (int yy = y + 1; yy <= N; yy++) {
			if (cpyMap[yy][x] == 0) cpyMap[yy][x] = 7;
			else if (cpyMap[yy][x] == 6) break;
			else continue;
		}
		bruteForce(cpyMap, cameraQueue);

		cpyMap = map;
		for (int xx = x - 1; xx > 0; xx--) {
			if (cpyMap[y][xx] == 0) cpyMap[y][xx] = 7;
			else if (cpyMap[y][xx] == 6) break;
			else continue;
		}
		for (int yy = y + 1; yy <= N; yy++) {
			if (cpyMap[yy][x] == 0) cpyMap[yy][x] = 7;
			else if (cpyMap[yy][x] == 6) break;
			else continue;
		}
		for (int xx = x + 1; xx <= M; xx++) {
			if (cpyMap[y][xx] == 0) cpyMap[y][xx] = 7;
			else if (cpyMap[y][xx] == 6) break;
			else continue;
		}
		bruteForce(cpyMap, cameraQueue);

		cpyMap = map;
		for (int yy = y + 1; yy <= N; yy++) {
			if (cpyMap[yy][x] == 0) cpyMap[yy][x] = 7;
			else if (cpyMap[yy][x] == 6) break;
			else continue;
		}
		for (int xx = x + 1; xx <= M; xx++) {
			if (cpyMap[y][xx] == 0) cpyMap[y][xx] = 7;
			else if (cpyMap[y][xx] == 6) break;
			else continue;
		}
		for (int yy = y - 1; yy > 0; yy--) {
			if (cpyMap[yy][x] == 0) cpyMap[yy][x] = 7;
			else if (cpyMap[yy][x] == 6) break;
			else continue;
		}
		bruteForce(cpyMap, cameraQueue);
	}
	else if (camera == 5) {
		cpyMap = map;
		for (int xx = x + 1; xx <= M; xx++) {
			if (cpyMap[y][xx] == 0) cpyMap[y][xx] = 7;
			else if (cpyMap[y][xx] == 6) break;
			else continue;
		}
		for (int xx = x - 1; xx > 0; xx--) {
			if (cpyMap[y][xx] == 0) cpyMap[y][xx] = 7;
			else if (cpyMap[y][xx] == 6) break;
			else continue;
		}
		for (int yy = y - 1; yy > 0; yy--) {
			if (cpyMap[yy][x] == 0) cpyMap[yy][x] = 7;
			else if (cpyMap[yy][x] == 6) break;
			else continue;
		}
		for (int yy = y + 1; yy <= N; yy++) {
			if (cpyMap[yy][x] == 0) cpyMap[yy][x] = 7;
			else if (cpyMap[yy][x] == 6) break;
			else continue;
		}
		bruteForce(cpyMap, cameraQueue);
	}
}