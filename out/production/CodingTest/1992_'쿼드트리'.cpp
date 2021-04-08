#include <iostream>
#include <cstring>

#define endl '\n'

using namespace std;

int N;
int map[64][64];

string zip(int size, int startX, int startY);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	memset(map, 0, sizeof(map));

	cin >> N;

	for (int y = 0; y < N; y++) {
		string input; cin >> input;

		for (int x = 0; x < N; x++) {
			map[y][x] = input[x] - '0';
		}
	}

	cout << zip(N, 0, 0) << endl;

	return 0;
}

string zip(int size, int startX, int startY) {
	string result = "";

	bool all0 = true, all1 = true;
	for (int y = startY; y < startY + size; y++) {
		for (int x = startX; x < startX + size; x++) {
			if (map[y][x] == 0) all1 = false;
			else if (map[y][x] == 1) all0 = false;

			if (!all0 && !all1) break;
		}
	}

	if (all0) return "0";
	if (all1) return "1";

	result += '(';

	if (size > 1) {
		result += zip(size / 2, startX, startY);
		result += zip(size / 2, startX + size / 2, startY);
		result += zip(size / 2, startX, startY + size / 2);
		result += zip(size / 2, startX + size / 2, startY + size / 2);
	}

	result += ')';

	return result;
}