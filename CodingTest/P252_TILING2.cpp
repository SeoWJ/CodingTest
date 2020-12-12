#include <iostream>

#define endl '\n'

using namespace std;

void tiling();

int main(int argc, char* argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int C; cin >> C;

	while (C--)
		tiling();

	return 0;
}

void tiling() {
	int N; cin >> N;
	int dp[101] = { 0 };

	dp[1] = 1; dp[2] = 2; dp[3] = 3; dp[4] = 5; dp[5] = 8;

	for (int x = 6; x <= N; x++)
		dp[x] = (dp[x - 1] + dp[x - 2]) % 1000000007;

	cout << dp[N] << endl;
}