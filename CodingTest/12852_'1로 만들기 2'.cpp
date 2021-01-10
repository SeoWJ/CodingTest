#include <iostream>

#define endl '\n'

using namespace std;

typedef pair<int, int> pii;

int N;
pii dp[1000001] = { {0,0} };

int main(int argc, char* argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;

	dp[1] = { 0, 0 };
	dp[2] = dp[3] = { 1, 1 };

	/*for (int i = 4; i <= N; i++) {
		if (i % 2 == 0 && i % 3 == 0) {
			dp[i] = min3(i - 1, i / 2, i / 3);
		}
		else if (i % 2 == 0 && i % 3 != 0)
			dp[i] = min2(i - 1, i / 2);
		else if (i % 2 != 0 && i % 3 == 0)
			dp[i] = min2(i - 1, i / 3);
		else
			dp[i] = { dp[i - 1].first + 1, i - 1 };
	}*/

	for (int i = 4; i <= N; i++) {
		if (i % 3 == 0) {
			if (i % 2 == 0) {
				int min = dp[i / 3].first < dp[i / 2].first ? dp[i / 3].first : dp[i / 2].first;
				int prev = dp[i / 3].first < dp[i / 2].first ? i / 3 : i / 2;
				prev = min < dp[i - 1].first ? prev : i - 1;
				min = min < dp[i - 1].first ? min : dp[i - 1].first;

				dp[i] = { min + 1, prev };
			}
			else {
				int prev = dp[i / 3].first < dp[i - 1].first ? i / 3 : i - 1;
				int min = dp[i / 3].first < dp[i - 1].first ? dp[i / 3].first : dp[i - 1].first;

				dp[i] = { min + 1, prev };
			}
		}
		else if (i % 2 == 0) {
			int prev = dp[i / 2].first < dp[i - 1].first ? i / 2 : i - 1;
			int min = dp[i / 2].first < dp[i - 1].first ? dp[i / 2].first : dp[i - 1].first;

			dp[i] = { min + 1, prev };
		}
		else {
			dp[i] = { dp[i - 1].first + 1, i - 1 };
		}
	}

	cout << dp[N].first << endl;

	cout << N << " ";
	int i = dp[N].second;
	while (1) {
		if (i == 1) {
			cout << i << endl;
			break;
		}

		cout << i << " ";
		i = dp[i].second;
	}

	return 0;
}