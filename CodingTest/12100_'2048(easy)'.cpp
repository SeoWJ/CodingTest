#include <iostream>
#include <vector>
#include <deque>

using namespace std;

typedef deque<deque<int>> Map;

int N;
Map map;
int answer = 0;

void bruteForce(Map map, int count);
Map left(Map map);
Map right(Map map);
Map up(Map map);
Map down(Map map);
Map rotateClockWise(Map map);
Map rotateReverseClockWise(Map map);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	N = 4;
	right({
		{4,4,8,8},
		{0,0,0,0},
		{0,0,0,0},
		{0,0,0,0},
		});

	cin >> N;

	for (int y = 0; y < N; y++) {
		deque<int> row;

		for (int x = 0; x < N; x++) {
			int input; cin >> input;
			row.push_back(input);
		}

		map.push_back(row);
	}

	bruteForce(map, 0);

	cout << answer << endl;

	return 0;
}

void bruteForce(Map map, int count) {
	if (count == 5) {
		for (unsigned int y = 0; y < map.size(); y++) {
			for (unsigned int x = 0; x < map.size(); x++) {
				answer = answer > map[y][x] ? answer : map[y][x];
			}
		}

		return;
	}

	bruteForce(left(map), count + 1);
	bruteForce(right(map), count + 1);
	bruteForce(up(map), count + 1);
	bruteForce(down(map), count + 1);
}

Map left(Map map) {
	Map newMap;

	for (unsigned int y = 0; y < map.size(); y++) {
		deque<int> row;

		for (unsigned int x = 0; x < map[y].size(); x++) {
			if (map[y][x] != 0) 
				row.push_back(map[y][x]);
		}

		int rowSize = row.size();
		for (unsigned int i = 0; i < map[y].size() - rowSize; i++) row.push_back(0);

		for (int x = 0; x < N - 1; x++) {
			if (row[x] == row[x+1] && row[x] != 0) {
				row[x + 1] += row[x];
				row.erase(row.begin() + x);
				row.push_back(0);
			}
		}

		newMap.push_back(row);
	}

	return newMap;
}

Map right(Map map) {
	Map newMap;

	for (unsigned int y = 0; y < map.size(); y++) {
		deque<int> row;

		for (int x = map[y].size() - 1; x >= 0; x--) {
			if (map[y][x] != 0)
				row.push_front(map[y][x]);
		}

		int rowSize = row.size();
		for (unsigned int i = 0; i < map[y].size() - rowSize; i++) row.push_front(0);

		for (int x = N - 1; x > 0; x--) {
			if (row[x] == row[x - 1] && row[x] != 0) {
				row[x - 1] += row[x];
				row.erase(row.begin() + x);
				row.push_front(0);
			}
		}

		newMap.push_back(row);
	}

	return newMap;
}

Map up(Map map) {
	Map newMap = rotateClockWise(map);

	newMap = right(newMap);

	return rotateReverseClockWise(newMap);
}

Map down(Map map) {
	Map newMap = rotateClockWise(map);

	newMap = left(newMap);

	return rotateReverseClockWise(newMap);
}

Map rotateClockWise(Map map) {
	Map newMap;
	deque<int> row(N, 0);
	newMap.assign(N, row);

	for (int y1 = 0; y1 < N; y1++) {
		int x2 = (N - 1) - y1;

		for (int x1 = 0; x1 < N; x1++) {
			int y2 = x1;

			newMap[y2][x2] = map[y1][x1];
		}
	}

	return newMap;
}
Map rotateReverseClockWise(Map map) {
	Map newMap;
	deque<int> row(N, 0);
	newMap.assign(N, row);

	for (int y1 = 0; y1 < N; y1++) {
		int x2 = y1;

		for (int x1 = 0; x1 < N; x1++) {
			int y2 = (N - 1) - x1;

			newMap[y2][x2] = map[y1][x1];
		}
	}

	return newMap;
}