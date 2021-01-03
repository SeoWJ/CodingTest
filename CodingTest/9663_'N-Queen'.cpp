#include <iostream>
#include <vector>
#include <queue>

#define endl '\n'

using namespace std;

int N;
int dx[8] = { 1, 1, 0, -1, -1, -1 , 0, 1 };
int dy[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };

void solution();
void bruteForce(vector<vector<bool>> map, int _x, int _y);

int main(int argc, char* argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	solution();

	return 0;
}

void solution() {
	vector<vector<bool>> map;
	vector<bool> temp;
	temp.assign(N, false);
	map.assign(N, temp);

	deque<vector<vector<bool>>> map_list;
	deque<vector<vector<bool>>> answer;

	for (int y = 0; y < N; y++) {
		if (y == 0) {
			map_list.push_back(map);

			for (int x = 0; x < N; x++) {
				map[y][x] = true;
				map_list.push_back(map);
				map[y][x] = false;
			}
		}
		else {
			deque<vector<vector<bool>>> cpy_map_list = map_list;
			map_list.clear();
			
			while (!cpy_map_list.empty()) {
				map_list.push_back(cpy_map_list.front());

				for (int x = 0; x < N; x++) {
					bool CanPutQueen = true;
					
					for (int i = 0; i < 8; i++) {
						int cx = x + dx[i];
						int cy = y + dy[i];

						while (0 <= cx && cx < N && 0 <= cy && cy < N && CanPutQueen) {
							if (cpy_map_list.front()[cy][cx] == true)
								CanPutQueen = false;
							cx += dx[i];
							cy += dy[i];
						}
					}

					if (CanPutQueen) {
						cpy_map_list.front()[y][x] = true;
						map_list.push_back(cpy_map_list.front());
						cpy_map_list.front()[y][x] = false;
					}
				}

				cpy_map_list.pop_front();
			}
		}
	}

	cout << map_list.front()[0][0] << endl;
}