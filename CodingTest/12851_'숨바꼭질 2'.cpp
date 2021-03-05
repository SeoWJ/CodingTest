#include <iostream>
#include <queue>

#define endl '\n'
#define INF 0x0FFFFFFF

using namespace std;

int N, K;
pair<int, int> point[100001];

void solution();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	solution();

	return 0;
}

void solution() {
	cin >> N >> K;

	for (int i = 0; i < 100001; i++) point[i] = { INF, 0 };
	point[N] = { 0, 1 };

	queue<int> Q;
	Q.push(N);

	while (!Q.empty()) {
		int currentPosition = Q.front();
		int currentCost = point[currentPosition].first;

		Q.pop();

		if (currentPosition < 100000 && currentCost + 1 < point[currentPosition + 1].first) {
			point[currentPosition + 1] = { currentCost + 1, 1 };
			Q.push(currentPosition + 1);
		}
		else if (currentPosition < 100000 && currentCost + 1 == point[currentPosition + 1].first) {
			point[currentPosition + 1].second++;
			Q.push(currentPosition + 1);
		}

		if (0 < currentPosition && currentCost + 1 < point[currentPosition - 1].first) {
			point[currentPosition - 1] = { currentCost + 1, 1 };
			Q.push(currentPosition - 1);
		}
		else if (0 < currentPosition && currentCost + 1 == point[currentPosition - 1].first) {
			point[currentPosition - 1].second++;
			Q.push(currentPosition - 1);
		}
		if (currentPosition * 2 <= 100000 && currentCost + 1 < point[currentPosition * 2].first) {
			point[currentPosition * 2] = { currentCost + 1, 1 };
			Q.push(currentPosition * 2);
		}
		else if (currentPosition * 2 <= 100000 && currentCost + 1 < point[currentPosition * 2].first) {
			point[currentPosition * 2].second++;
			Q.push(currentPosition * 2);
		}
	}

	cout << point[K].first << endl << point[K].second << endl;
}