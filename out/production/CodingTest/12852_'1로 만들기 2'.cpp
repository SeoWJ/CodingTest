#include <iostream>

#define endl '\n'

using namespace std;

int DP[1000001] = { 0 };
int before[1000001] = { 0 };

int main(int argc, char* argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N; cin >> N;

	DP[1] = 0;
	DP[2] = DP[3] = before[2] = before[3] = 1;

	for (int i = 4; i <= N; i++) {
		int prev;

		if (i % 3 == 0 && i % 2 == 0)
			prev = DP[i / 3] < DP[i / 2] ? (DP[i / 3] < DP[i - 1] ? i / 3 : i - 1) : (DP[i / 2] < DP[i - 1] ? i / 2 : i - 1);
		else if (i % 3 != 0 && i % 2 == 0)
			prev = DP[i / 2] < DP[i - 1] ? i / 2 : i - 1;
		else if (i % 3 == 0 && i % 2 != 0)
			prev = DP[i / 3] < DP[i - 1] ? i / 3 : i - 1;
		else
			prev = i - 1;

		DP[i] = DP[prev] + 1;
		before[i] = prev;
	}

	cout << DP[N] << endl;

	cout << N << " ";
	int i = N;
	while (1) {
		cout << before[i] << " ";
		i = before[i];

		if (i == 1) break;
	}
	cout << endl;

	return 0;
}