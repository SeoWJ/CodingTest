#include <iostream>
#include <queue>

#define endl '\n'
#define max(a, b) a > b ? a : b

using namespace std;

typedef pair<int, int> pii;

int N, K;
pii item[101];
int dp[101][100001] = { 0 };

void solution();

int main(int argc, char* argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> K;

	for (int i = 1; i <= N; i++) {
		int weight, value;
		cin >> weight >> value;

		item[i] = { weight, value };
	}

	solution();

	cout << dp[N][K] << endl;

	return 0;
}

void solution() {
	int min_weight = 0x7FFFFFFF;

	for (int y = 1; y <= N; y++) {
		min_weight = min_weight < item[y].first ? min_weight : item[y].first;

		for (int x = min_weight; x <= K; x++) {
			if (x - item[y].first < 0)
				dp[y][x] = dp[y - 1][x];
			else
				dp[y][x] = max(dp[y - 1][x], dp[y - 1][x - item[y].first] + item[y].second);
		}
	}
}