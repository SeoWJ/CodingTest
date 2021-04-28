#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <tuple>

#define endl '\n'
#define UNABLE '*'

using namespace std;

class Alphabet {
protected:
	int R, C;
	char map[22][22];
	int answer;

public:
	Alphabet() {
		answer = 0;

		cin >> R >> C;

		memset(map, UNABLE, sizeof(map));

		for (int y = 1; y <= R; y++) {
			for (int x = 1; x <= C; x++)
				cin >> map[y][x];
		}
	}
	void DFS(tuple<int, int, int> current, vector<pair<char, bool>> usedAlphabet) {
		int moveCount = get<0>(current);
		int x = get<1>(current);
		int y = get<2>(current);

		answer = answer > moveCount ? answer : moveCount;

		if (map[y + 1][x] != '*' && usedAlphabet[map[y + 1][x] - 'A'].second == false) {
			usedAlphabet[map[y + 1][x] - 'A'].second = true;

			DFS({ moveCount + 1, x, y + 1 }, usedAlphabet);

			usedAlphabet[map[y + 1][x] - 'A'].second = false;
		}
		if (map[y - 1][x] != '*' && usedAlphabet[map[y - 1][x] - 'A'].second == false) {
			usedAlphabet[map[y - 1][x] - 'A'].second = true;

			DFS({ moveCount + 1, x, y - 1 }, usedAlphabet);

			usedAlphabet[map[y - 1][x] - 'A'].second = false;
		}
		if (map[y][x + 1] != '*' && usedAlphabet[map[y][x + 1] - 'A'].second == false) {
			usedAlphabet[map[y][x + 1] - 'A'].second = true;

			DFS({ moveCount + 1, x + 1, y }, usedAlphabet);

			usedAlphabet[map[y][x + 1] - 'A'].second = false;
		}
		if (map[y][x - 1] != '*' && usedAlphabet[map[y][x - 1] - 'A'].second == false) {
			usedAlphabet[map[y][x - 1] - 'A'].second = true;

			DFS({ moveCount + 1, x - 1, y }, usedAlphabet);

			usedAlphabet[map[y][x - 1] - 'A'].second = false;
		}
	}
	void solution() {
		vector<pair<char, bool>> usedAlphabet;
		
		for (char c = 'A'; c <= 'Z'; c++) usedAlphabet.push_back({ c, false });
		
		usedAlphabet[map[1][1] - 'A'].second = true;

		DFS({ 1, 1, 1 }, usedAlphabet);

		cout << answer << endl;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	Alphabet a;
	a.solution();

	return 0;
}