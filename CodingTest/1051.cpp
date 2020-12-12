#include <iostream>
#include <cstring>

#define endl '\n'

using namespace std;

int N, M;
int map[52][52];
int max_side = 0;

void numberSquare();
void clear();

int main(int argc, char* argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	numberSquare();

	return 0;
}

void numberSquare() {
	clear();
	cin >> N >> M;

	for (int y = 1; y <= N; y++) {
		string input; cin >> input;
		
		for (int x = 1; x <= M; x++)
			map[y][x] = input[x - 1] - '0';
	}

	int max_length = N < M ? N : M;
	int answer = 0;

	for (int length = 2; length <= max_length; length++) {
		for (int y = 1; y <= N; y++) {
			if (y + (length - 1) > N)
				break;

			for (int x = 1; x <= M; x++) {
				if (x + (length - 1) > M)
					break;
				
				if (map[y][x] == map[y][x + (length - 1)] && map[y][x + (length - 1)] == map[y + (length - 1)][x] && map[y + (length - 1)][x] == map[y + (length - 1)][x + (length - 1)])
					answer = answer > length ? answer : length;
			}
		}
	}

	if (answer == 0) {
		cout << 1 << endl;
		return;
	}
	cout << answer * answer << endl;
}

void clear() {
	for (int y = 0; y < 52; y++) {
		for (int x = 0; x < 52; x++) {
			map[y][x] = -1;
		}
	}
}