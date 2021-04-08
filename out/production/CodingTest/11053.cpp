#include <iostream>

#define endl '\n'

using namespace std;

void longestIncreasingSequence();

int main(int argc, char* argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	longestIncreasingSequence();

	return 0;
}

void longestIncreasingSequence() {
	int N; cin >> N;
	int A[1000];
	int dp[1000];
	int dp_max = 1;

	for (int loop1 = 0; loop1 < N; loop1++) {
		cin >> A[loop1];
		dp[loop1] = 1;
	}

	for (int fix = 1; fix < N; fix++) {
		for (int move = 0; move < fix; move++) {
			if (A[move] < A[fix]) {
				dp[fix] = dp[move] + 1 > dp[fix] ? dp[move] + 1 : dp[fix];

				dp_max = dp_max > dp[fix] ? dp_max : dp[fix];
			}
		}
	}

	cout << dp_max << endl;
}