#include <iostream>

#define endl '\n'

using namespace std;

int sticker[2][100000];
int dp[2][100000];

void solution();
void clear();

int main(int argc, char* argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int T; cin >> T;

	while(T--)
		solution();

	return 0;
}

void solution() {
	clear();

	int N; cin >> N;

	for (int y = 0; y < 2; y++) {
		for (int x = 0; x < N; x++)
			cin >> sticker[y][x];
	}

	if (N == 1) {
		int result = sticker[0][0] > sticker[1][0] ? sticker[0][0] : sticker[1][0];
		cout << result << endl;
		return;
	}
	else if (N == 2) {
		int result = sticker[0][0] + sticker[1][1] > sticker[0][1] + sticker[1][0] ? sticker[0][0] + sticker[1][1] : sticker[0][1] + sticker[1][0];
		cout << result << endl;
		return;
	}
	else {
		dp[0][0] = sticker[0][0];
		dp[1][0] = sticker[1][0];
		dp[0][1] = sticker[1][0] + sticker[0][1];
		dp[1][1] = sticker[0][0] + sticker[1][1];

		for (int i = 2; i < N; i++) {
			dp[0][i] = dp[1][i - 1] + sticker[0][i] > dp[1][i - 2] + sticker[0][i] ? dp[1][i - 1] + sticker[0][i] : dp[1][i - 2] + sticker[0][i];
			dp[1][i] = dp[0][i - 1] + sticker[1][i] > dp[0][i - 2] + sticker[1][i] ? dp[0][i - 1] + sticker[1][i] : dp[0][i - 2] + sticker[1][i];
		}

		int result = dp[0][N - 1] > dp[1][N - 1] ? dp[0][N - 1] : dp[1][N - 1];
		cout << result << endl;
	}
}

void clear() {
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 100000; j++) {
			sticker[i][j] = -1;
			dp[i][j] = -1;
		}
	}
}