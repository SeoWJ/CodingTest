#include<iostream>

#define endl '\n'
#define max3(a,b,c) a > b ? (a > c ? a : c) : (b > c ? b : c)

using namespace std;

void wineTasting();

int main(int argc, char* argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	wineTasting();

	return 0;
}

void wineTasting() {
	int N; cin >> N;
	int wine[10001] = { 0 };
	int dp[10001] = { 0 };

	for (int x = 1; x <= N; x++) cin >> wine[x];

	dp[1] = wine[1];
	dp[2] = wine[1] + wine[2];
	dp[3] = max3(wine[1] + wine[2], wine[2] + wine[3], wine[3] + wine[1]);

	if (N <= 3) {
		cout << dp[N] << endl;
		return;
	}
	else {

	}
}