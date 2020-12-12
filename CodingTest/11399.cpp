#include <iostream>
#include <vector>
#include <algorithm>

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
	int N; cin >> N;
	vector<int> P;

	for (int loop1 = 0; loop1 < N; loop1++) {
		int input; cin >> input;
		P.push_back(input);
	}

	sort(P.begin(), P.end());

	int result = 0;
	for (int loop1 = 0; loop1 < N; loop1++) {
		for (int loop2 = 0; loop2 <= loop1; loop2++) {
			result += P[loop2];
		}
	}

	cout << result << endl;
}