#include <iostream>
#include <queue>

#define endl '\n'

using namespace std;

int map[202][202] = { 0 };

void competitiveSpread();
void clearMap();

int main(int argc, char* argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	competitiveSpread();

	return 0;
}

void competitiveSpread() {
	clearMap();

	int N, K; cin >> N >> K;

	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++)
			cin >> map[y][x];
	}

	int S, target_X, target_Y; cin >> S >> target_Y >> target_X;

	queue<pair<int, int>>* Q = new queue<pair<int, int>>;
	for (int virus = 1; virus <= 1000; virus++) {
		for (int y = 1; y <= N; y++) {
			for (int x = 1; x <= N; x++) {
				if (map[y][x] == virus) {
					Q->push(make_pair(x, y));
				}
			}
		}
	}

	while (S--) {
		queue<pair<int, int>>* temp_Q = new queue<pair<int, int>>;
		while (!Q->empty()) {
			if (map[Q->front().second - 1][Q->front().first] == 0) {
				map[Q->front().second - 1][Q->front().first] = map[Q->front().second][Q->front().first];
				temp_Q->push(make_pair(Q->front().first, Q->front().second - 1));
			}
			if (map[Q->front().second + 1][Q->front().first] == 0) {
				map[Q->front().second + 1][Q->front().first] = map[Q->front().second][Q->front().first];
				temp_Q->push(make_pair(Q->front().first, Q->front().second + 1));
			}
			if (map[Q->front().second][Q->front().first - 1] == 0) {
				map[Q->front().second][Q->front().first - 1] = map[Q->front().second][Q->front().first];
				temp_Q->push(make_pair(Q->front().first - 1, Q->front().second));
			}
			if (map[Q->front().second][Q->front().first + 1] == 0) {
				map[Q->front().second][Q->front().first + 1] = map[Q->front().second][Q->front().first];
				temp_Q->push(make_pair(Q->front().first + 1, Q->front().second));
			}

			Q->pop();
		}
		delete Q;
		Q = temp_Q;
	}

	cout << map[target_Y][target_X] << endl;
}

void clearMap() {
	for (int y = 0; y < 202; y++) {
		for (int x = 0; x < 202; x++)
			map[y][x] = -1;
	}
}