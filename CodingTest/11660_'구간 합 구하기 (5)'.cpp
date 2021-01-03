#include <iostream>

#define endl '\n'

using namespace std;

int N, M;
long long map[1025][1025];

void insert();
void solution();

int main(int argc, char* argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	insert();
	
	while(M--)
		solution();

	return 0;
}

void insert() {
	for (int y = 0; y < 1025; y++) {
		for (int x = 0; x < 1025; x++)
			map[y][x] = 0;
	}

	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {
			int input; cin >> input;
			map[y][x] = map[y][x - 1] + input;
		}
	}
}

void solution() {
	long long result = 0;
	int x1, x2, y1, y2;
	//cin >> x1 >> y1 >> x2 >> y2;
	cin >> y1 >> x1 >> y2 >> x2;

	for (int y = y1; y <= y2; y++)
		result += map[y][x2] - map[y][x1 - 1];

	cout << result << endl;
}