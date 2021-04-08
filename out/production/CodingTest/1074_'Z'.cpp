#include <iostream>
#include <vector>
#include <cmath>

#define endl '\n'

using namespace std;

int N, r, c;

int main(int argc, char* argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> r >> c;

	int answer = 0;
	

	while (N > 0) {
		int term = pow(4, N - 1);

		if (r >= pow(2, N - 1) && c >= pow(2, N - 1)) {
			r -= pow(2, N - 1);
			c -= pow(2, N - 1);
			answer += term * 3;
		}
		else if (r >= pow(2, N - 1) && c < pow(2, N - 1)) {
			r -= pow(2, N - 1);
			answer += term * 2;
		}
		else if (r < pow(2, N - 1) && c >= pow(2, N - 1)) {
			c -= pow(2, N - 1);
			answer += term;
		}		

		N--;
	}

	cout << answer << endl;

	return 0;
}