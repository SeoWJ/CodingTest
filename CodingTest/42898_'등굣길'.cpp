#include <string>
#include <vector>

#define MOD 1000000007

using namespace std;

int map[101][101] = { 0 };

int solution(int m, int n, vector<vector<int>> puddles) {
	for (unsigned int i = 0; i < puddles.size(); i++)
		map[puddles[i][1]][puddles[i][0]] = -1;

	map[1][1] = 1;
	for (int x = 2; x <= m; x++) {
		if (map[1][x] == -1) continue;
		else map[1][x] = map[1][x - 1];
	}
	for (int y = 2; y <= n; y++) {
		if (map[y][1] == -1) continue;
		else map[y][1] = map[y - 1][1];
	}

	for (int y = 2; y <= n; y++) {
		for (int x = 2; x <= m; x++) {
			if (map[y][x] == -1) continue;

			if (map[y - 1][x] == -1 && map[y][x - 1] == -1) continue;
			else if (map[y - 1][x] == -1 && map[y][x - 1] != -1) map[y][x] = map[y][x - 1];
			else if (map[y - 1][x] != -1 && map[y][x - 1] == -1)map[y][x] = map[y - 1][x];
			else map[y][x] = (map[y - 1][x] + map[y][x - 1]) % MOD;
		}
	}

	return map[n][m];
}

int main() {
	solution(4, 3, { {2,2} });
}