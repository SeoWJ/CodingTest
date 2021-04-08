#include <iostream>
#include <vector>

#define endl '\n'
#define INF 0x0FFFFFFF

using namespace std;

class Friends {
protected:
	int N;
	pair<int, int> sanggunHouse;
	vector<pair<int, int>> store;
	pair<int, int> rockFestival;
	vector<vector<int>> dist;

public:
	Friends(int n) {
		N = n;
		int x, y;

		cin >> x >> y;
		sanggunHouse = { x, y };
		store.push_back(sanggunHouse);

		for (int i = 0; i < N; i++) {
			cin >> x >> y;
			store.push_back({ x,y });
		}

		cin >> x >> y;
		rockFestival = { x, y };
		store.push_back(rockFestival);

		vector<int> row(N + 2, INF);
		dist.assign(N + 2, row);

		for (int y = 0; y < N + 2; y++) {
			for (int x = 0; x < N + 2; x++) {
				if (x == y) dist[y][x] = 0;
				else {
					int x1 = store[y].first;
					int y1 = store[y].second;
					int x2 = store[x].first;
					int y2 = store[x].second;

					int distanceBetween = ABS(x1, x2) + ABS(y1, y2);

					if (distanceBetween <= 20 * 50)
						dist[y][x] = 1;
				}
			}
		}
	}
	int ABS(int n1, int n2) {
		return n1 > n2 ? n1 - n2 : n2 - n1;
	}
	void floydWashall() {
		for (int midPoint = 0; midPoint < N + 2; midPoint++) {
			for (int start = 0; start < N + 2; start++) {
				for (int destination = 0; destination < N + 2; destination++) {
					int beforeDistance = dist[start][destination];
					int newDistance = dist[start][midPoint] + dist[midPoint][destination];

					if (newDistance < beforeDistance)
						dist[start][destination] = newDistance;
				}
			}
		}
	}
	void solution() {
		floydWashall();

		if (dist[0][N + 1] == INF)
			cout << "sad" << endl;
		else
			cout << "happy" << endl;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		Friends f(N);

		f.solution();
	}

	return 0;
}