#include <iostream>

#define endl '\n'

using namespace std;

void zoo();

int main(int argc, char* argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	zoo();

	return 0;
}

void zoo() {
	int N; cin >> N;

	int dp[100001] = { 0 };
	dp[0] = 1, dp[1] = 3;

	for (int x = 2; x <= N; x++) {
		dp[x] = ((dp[x - 1] * 2) + dp[x - 2]) % 9901;
	}

	cout << dp[N] << endl;
}