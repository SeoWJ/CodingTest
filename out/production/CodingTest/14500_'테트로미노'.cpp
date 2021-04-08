#include <iostream>
#include <vector>

#define endl '\n'
#define UNABLE -4001

using namespace std;

int N, M;

int map[508][508];
vector<int> tetromino_dx[] = {
	{0,1,2,3}, {0,0,0,0},
	{0,1,0,1},
	{0,0,0,1}, {0,1,2,2}, {0,0,0,-1},  {0,-1,-2,-2},
	{0,0,0,-1}, {0,1,2,2}, {0,0,0,1}, {0,-1,-2,-2},
	{0,0,1,1}, {0,1,1,2},
	{0,0,-1,-1}, {0,1,1,2},
	{0,1,1,2}, {0,0,0,1}, {0,-1,-1,-2}, {0,0,0,-1}
};
vector<int> tetromino_dy[] = {
	{0,0,0,0}, {0,1,2,3},
	{0,0,1,1},
	{0,1,2,2}, {0,0,0,-1}, {0,-1,-2,-2}, {0,0,0,1},
	{0,1,2,2}, {0,0,0,1}, {0,-1,-2,-2}, {0,0,0,-1},
	{0,1,1,2}, {0,0,-1,-1},
	{0,1,1,2}, {0,0,1,1},
	{0,0,1,0}, {0,-1,-2,-1}, {0,0,-1,0}, {0,1,2,1}
};

void clear();

int main(int argc, char* argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	clear();

	cin >> N >> M;

	for (int y = 4; y < N + 4; y++) {
		for (int x = 4; x < M + 4; x++) {
			cin >> map[y][x];
		}
	}

	int total_max_area = 0;

	for (int y = 4; y < N + 4; y++) {
		for (int x = 4; x < M + 4; x++) {
			int max_area = 0;
			
			for (int i = 0; i < 19; i++) {
				int area = 0;
				for (int j = 0; j < 4; j++) {
					area += map[y + tetromino_dy[i][j]][x + tetromino_dx[i][j]];
				}
				max_area = max_area > area ? max_area : area;
			}
			total_max_area = total_max_area > max_area ? total_max_area : max_area;
		}
	}

	cout << total_max_area << endl;

	return 0;
}

void clear() {
	for (int y = 0; y < 508; y++) {
		for (int x = 0; x < 508; x++)
			map[y][x] = UNABLE;
	}
}