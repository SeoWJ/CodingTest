#include <iostream>
#include <vector>
#include <cstring>

#define endl '\n'

using namespace std;

int N, M;
int map[52][52];
vector<pair<pair<int, int>, bool>> chickenStoreArray;
int minimumChickenDistance = 0x7FFFFFFF;

void bruteForce(vector<pair<int, int>> aliveChickenStore, vector<pair<pair<int, int>, bool>> chickenStoreArray, int idx);

int main() {
	cin >> N >> M;

	memset(map, 3, sizeof(map));

	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {
			int input; cin >> input;
			map[y][x] = input;

			if (input == 2)
				chickenStoreArray.push_back({ { x, y }, false });
		}
	}

	bruteForce({}, chickenStoreArray, 0);

	cout << minimumChickenDistance << endl;
}

void bruteForce(vector<pair<int, int>> aliveChickenStore, vector<pair<pair<int, int>, bool>> chickenStoreArray, int idx) {
	if (aliveChickenStore.size() < M) {
		for (unsigned int i = idx; i < chickenStoreArray.size(); i++) {
			if (chickenStoreArray[i].second == false) {
				chickenStoreArray[i].second = true;
				aliveChickenStore.push_back(chickenStoreArray[i].first);

				bruteForce(aliveChickenStore, chickenStoreArray, i + 1);

				aliveChickenStore.pop_back();
				chickenStoreArray[i].second = false;
			}
		}
	}
	else {
		int totalChickenDistance = 0;

		for (int y = 1; y <= N; y++) {
			for (int x = 1; x <= N; x++) {
				if (map[y][x] == 1) {
					int chickenDistance = 0x7FFFFFFF;
					
					for (unsigned int i = 0; i < aliveChickenStore.size(); i++) {
						int chickenX = aliveChickenStore[i].first;
						int chickenY = aliveChickenStore[i].second;

						int dist = (x > chickenX ? x - chickenX : chickenX - x) + (y > chickenY ? y - chickenY : chickenY - y);

						chickenDistance = chickenDistance < dist ? chickenDistance : dist;
					}

					totalChickenDistance += chickenDistance;
				}
			}
		}

		minimumChickenDistance = minimumChickenDistance < totalChickenDistance ? minimumChickenDistance : totalChickenDistance;
	}
}