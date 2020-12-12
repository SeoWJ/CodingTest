#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

#define endl '\n'

using namespace std;

void operation();

int main(int argc, char* argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	while (T--)
		operation();

	return 0;
}

void operation() {
	pair<long long, long long> point[4];
	vector<long double> length;

	for (int loop1 = 0; loop1 < 4; loop1++) {
		int x, y;
		cin >> x >> y;
		point[loop1] = make_pair(x, y);
	}

	for (int loop1 = 0; loop1 < 4; loop1++) {
		for (int loop2 = loop1 + 1; loop2 < 4; loop2++) {
			length.push_back(sqrt(pow(point[loop1].first - point[loop2].first, 2) + pow(point[loop1].second - point[loop2].second, 2)));
		}
	}

	sort(length.begin(), length.end());

	if ((length[0] == length[3] && length[4] == length[5]) || (length[0] == length[1] && length[2] == length[5]))
		cout << 1 << endl;
	else
		cout << 0 << endl;
}
