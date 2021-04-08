#include <iostream>
#include <vector>
#include <queue>

#define endl '\n'
#define WALL -1000

using namespace std;

class World {
protected:
	int N, L, R;
	int map[52][52];
	int unite[52][52];
	int moveCount;
	vector<pair<int, vector<pair<int, int>>>> uniteInformation;

public:
	World(int n, int l, int r) { N = n; L = l; R = r; moveCount = 0; }
	void solution();
	void inputMap();
	void clearUnite();
	void checkUnite();
	int ABS(int a, int b);
	pair<int, vector<pair<int, int>>> BFS(int X, int Y, int uniteNumber);
};


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, L, R;
	cin >> N >> L >> R;

	World w(N, L, R);
	w.solution();

	return 0;
}

void World::solution() {
	inputMap();

	while (1) {
		clearUnite();
		uniteInformation.clear();

		checkUnite();

		if (uniteInformation.empty()) {
			cout << moveCount << endl;
			return;
		}
		else {
			for (unsigned int i = 0; i < uniteInformation.size(); i++) {
				int peopleAverage = uniteInformation[i].first / uniteInformation[i].second.size();

				for (unsigned int j = 0; j < uniteInformation[i].second.size(); j++)
					map[uniteInformation[i].second[j].second][uniteInformation[i].second[j].first] = peopleAverage;
			}
			moveCount++;
		}
	}
}

pair<int, vector<pair<int, int>>> World::BFS(int X, int Y, int uniteNumber) {
	vector<pair<int, int>> unitePosition;
	int totalUnitePeople = 0;
	queue<pair<int, int>> Q;
	Q.push({ X, Y });
	unite[Y][X] = uniteNumber;

	while (!Q.empty()) {
		int x = Q.front().first;
		int y = Q.front().second;

		Q.pop();
		unitePosition.push_back({ x, y });
		totalUnitePeople += map[y][x];

		if (map[y + 1][x] != WALL && unite[y + 1][x] == 0 && L <= ABS(map[y][x], map[y + 1][x]) && ABS(map[y][x], map[y + 1][x]) <= R) {
			Q.push({ x, y + 1 });
			unite[y + 1][x] = uniteNumber;
		}
		if (map[y - 1][x] != WALL && unite[y - 1][x] == 0 && L <= ABS(map[y][x], map[y - 1][x]) && ABS(map[y][x], map[y - 1][x]) <= R) {
			Q.push({ x, y - 1 });
			unite[y - 1][x] = uniteNumber;
		}
		if (map[y][x + 1] != WALL && unite[y][x + 1] == 0 && L <= ABS(map[y][x], map[y][x + 1]) && ABS(map[y][x], map[y][x + 1]) <= R) {
			Q.push({ x + 1, y });
			unite[y][x + 1] = uniteNumber;
		}
		if (map[y][x - 1] != WALL && unite[y][x - 1] == 0 && L <= ABS(map[y][x], map[y][x - 1]) && ABS(map[y][x], map[y][x - 1]) <= R) {
			Q.push({ x - 1, y });
			unite[y][x - 1] = uniteNumber;
		}
	}

	return { totalUnitePeople, unitePosition };
}

void World::checkUnite() {
	int uniteNumber = 0;

	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {
			if (unite[y][x] == 0) {
				uniteNumber++;
				
				pair<int, vector<pair<int, int>>> uniteInfoTemp = BFS(x, y, uniteNumber);

				if (uniteInfoTemp.second.size() == 1) continue;
				else uniteInformation.push_back(uniteInfoTemp);
			}
		}
	}
}

void World::clearUnite() {
	for (int y = 0; y < 52; y++) {
		for (int x = 0; x < 52; x++) {
			unite[y][x] = 0;
		}
	}
}

void World::inputMap() {
	for (int y = 0; y < 52; y++) {
		for (int x = 0; x < 52; x++) {
			map[y][x] = WALL;
		}
	}

	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++)
			cin >> map[y][x];
	}
}

int World::ABS(int a, int b) {
	return a > b ? a - b : b - a;
}