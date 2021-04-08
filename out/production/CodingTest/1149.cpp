#include <iostream>

#define endl '\n'
#define min2(a,b) a < b ? a : b
#define min3(a,b,c) a < b ? (a < c ? a : c) : (b < c ? b : c)

using namespace std;

void RGVDistance();

int main(int argc, char* argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	RGVDistance();

	return 0;
}

void RGVDistance() {
	int N; cin >> N;
	int cost[1001][3] = { 0 };

	for (int i = 1; i <= N; i++)
		cin >> cost[i][0] >> cost[i][1] >> cost[i][2];

	for (int y = N; y >= 1; y--) {
		if (y == N) continue;

		cost[y][0] += min2(cost[y + 1][1], cost[y + 1][2]);
		cost[y][1] += min2(cost[y + 1][0], cost[y + 1][2]);
		cost[y][2] += min2(cost[y + 1][0], cost[y + 1][1]);
	}

	int result = min3(cost[1][0], cost[1][1], cost[1][2]);

	cout << result << endl;
}