#include <iostream>
#include <queue>

#define endl '\n'
#define x(a) a.first
#define y(a) a.second
#define max(a,b) a > b ? a : b
#define copy_map(a, b) for (int y = 0; y < 10; y++) {\
										for (int x = 0; x < 10; x++)\
											b[y][x] = a[y][x];\
									}\

using namespace std;

int N, M;
int map[10][10] = { 0 };
int safe_area = 0;

void lab();
void spreadVirus(int _map[][10]);

int main(int argc, char* argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	lab();

	return 0;
}

void lab() {
	cin >> N >> M;

	for (int y = 0; y < 10; y++) {
		for (int x = 0; x < 10; x++) {
			map[y][x] = 9;
		}
	}

	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= M; x++) {
			int input; cin >> input;
			map[y][x] = input;
		}
	}

	for (int loop1 = 0; loop1 < N * M; loop1++) {
		if (map[(loop1 / M) + 1][(loop1 % M) + 1] == 0) {
			for (int loop2 = loop1 + 1; loop2 < N * M; loop2++) {
				if (map[(loop2 / M) + 1][(loop2 % M) + 1] == 0) {
					for (int loop3 = loop2 + 1; loop3 < N * M; loop3++) {
						if (map[(loop3 / M) + 1][(loop3 % M) + 1] == 0) {
							map[(loop1 / M) + 1][(loop1 % M) + 1] = map[(loop2 / M) + 1][(loop2 % M) + 1] = map[(loop3 / M) + 1][(loop3 % M) + 1] = 1;
							int cpy[10][10];
							copy_map(map, cpy)
								spreadVirus(cpy);
							map[(loop1 / M) + 1][(loop1 % M) + 1] = map[(loop2 / M) + 1][(loop2 % M) + 1] = map[(loop3 / M) + 1][(loop3 % M) + 1] = 0;
						}
					}
				}
			}
		}
	}

	cout << safe_area << endl;
}

void spreadVirus(int _map[][10]) {
	bool visit[10][10] = { false };
	queue< pair<int, int> > q;

	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= M; x++) {
			if (_map[y][x] == 2) {
				q.push(make_pair(x, y));
				visit[y][x] = true;
			}
		}
	}

	while (!q.empty()) {
		if (_map[y(q.front()) - 1][x(q.front())] == 0 && visit[y(q.front()) - 1][x(q.front())] == false) {
			_map[y(q.front()) - 1][x(q.front())] = 2;
			visit[y(q.front()) - 1][x(q.front())] = true;
			q.push(make_pair(x(q.front()), y(q.front()) - 1));
		}
		if (_map[y(q.front()) + 1][x(q.front())] == 0 && visit[y(q.front()) + 1][x(q.front())] == false) {
			_map[y(q.front()) + 1][x(q.front())] = 2;
			visit[y(q.front()) + 1][x(q.front())] = true;
			q.push(make_pair(x(q.front()), y(q.front()) + 1));
		}
		if (_map[y(q.front())][x(q.front()) - 1] == 0 && visit[y(q.front())][x(q.front()) - 1] == false) {
			_map[y(q.front())][x(q.front()) - 1] = 2;
			visit[y(q.front())][x(q.front()) - 1] = true;
			q.push(make_pair(x(q.front()) - 1, y(q.front())));
		}
		if (_map[y(q.front())][x(q.front()) + 1] == 0 && visit[y(q.front())][x(q.front()) + 1] == false) {
			_map[y(q.front())][x(q.front()) + 1] = 2;
			visit[y(q.front())][x(q.front()) + 1] = true;
			q.push(make_pair(x(q.front()) + 1, y(q.front())));
		}

		q.pop();
	}

	int cpy_safe_area = 0;
	for (int y = 0; y < 10; y++) {
		for (int x = 0; x < 10; x++) {
			if (_map[y][x] == 0)
				cpy_safe_area++;
		}
	}

	safe_area = max(safe_area, cpy_safe_area);
}