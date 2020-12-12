#include <iostream>

#define endl '\n'
#define min(a,b) a < b ? a : b

using namespace std;

int dp[1000001] = { 0 };

void makeOne();

int main(int argc, char* argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	makeOne();

	return 0;
}

void makeOne() {
	int N; cin >> N;

	for (int loop1 = 2; loop1 <= N; loop1++) {
		if (loop1 % 3 == 0) {
			if (loop1 % 2 == 0) {
				int minimum = dp[loop1 / 3] + 1;
				minimum = min(minimum, dp[loop1 / 2] + 1);
				minimum = min(minimum, dp[loop1 - 1] + 1);
				dp[loop1] = minimum;
			}
			else {
				dp[loop1] = min(dp[loop1 / 3] + 1, dp[loop1 - 1] + 1);
			}
		}
		else if (loop1 % 2 == 0)
			dp[loop1] = min(dp[loop1 / 2] + 1, dp[loop1 - 1] + 1);
		else
			dp[loop1] = dp[loop1 - 1] + 1;
	}

	cout << dp[N] << endl;
}