#include <iostream>

#define endl "\n"

using namespace std;

void operation();

int main(int argc, char* argv[]) {
	ios::sync_with_stdio(false);
	cin.tie();

	operation();

	return 0;
}

void operation() {
	int dp[1001] = { 0 };
	dp[1] = 1; dp[2] = 3; dp[3] = 5;

	int n; cin >> n;
	for (int loop1 = 4; loop1 <= n; loop1++)
		dp[loop1] = (dp[loop1 - 1] + (dp[loop1 - 2] * 2)) % 10007;
	cout << dp[n] << endl;
}