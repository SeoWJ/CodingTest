#include <iostream>

#define endl '\n'

using namespace std;

void operation();

int main(int argc, char* argv[]) {
	ios::sync_with_stdio(false);
	cin.tie();

	operation();

	return 0;
}

void operation() {
	int N; cin >> N;
	long long dp[91] = { 0 };
	dp[0] = 1; dp[1] = 1; dp[2] = 1; dp[3] = 2;

	for (int loop1 = 4; loop1 <= N; loop1++) {
		for (int loop2 = 0; loop2 <= loop1 - 2; loop2++)
			dp[loop1] += dp[loop2];
	}

	cout << dp[N] << endl;
}