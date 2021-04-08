#include <iostream>
#include <queue>

#define endl '\n'

using namespace std;

void operation();

int main(int argc, char* argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	while (T--)
		operation();

	return 0;
}

void operation() {
	int M, N, K; cin >> M >> N >> K;
	int field[52][52] = { 0 };
	bool visit[52][52] = { false };
	queue<pair<int, int>> q;
	int bug = 0;

	for (int loop1 = 0; loop1 < K; loop1++) {
		int X, Y;
		cin >> X >> Y;
		field[X + 1][Y + 1] = 1;
	}

	for (int y = 1; y < 51; y++) {
		for (int x = 1; x < 51; x++) {
			if (field[y][x] == 1 && visit[y][x] == false) {
				visit[y][x] = true;
				bug++;
				q.push(make_pair(x - 1, y));
				q.push(make_pair(x + 1, y));
				q.push(make_pair(x, y - 1));
				q.push(make_pair(x, y + 1));
				while (!q.empty()) {
					if (field[q.front().second][q.front().first] == 1 && visit[q.front().second][q.front().first] == false) {
						visit[q.front().second][q.front().first] = true;
						q.push(make_pair(q.front().first + 1, q.front().second));
						q.push(make_pair(q.front().first - 1, q.front().second));
						q.push(make_pair(q.front().first, q.front().second + 1));
						q.push(make_pair(q.front().first, q.front().second - 1));
					}
					q.pop();
				}
			}
		}
	}

	cout << bug << endl;
}

