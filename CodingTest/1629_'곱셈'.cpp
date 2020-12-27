#include <iostream>

#define endl '\n'

using namespace std;

long long power(int A, int B, int C);

int main(int argc, char* argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int A, B, C;
	cin >> A >> B >> C;

	cout << power(A % C, B, C) << endl;

	return 0;
}

long long power(int A, int B, int C) {
	if (B == 1)
		return A;
	else {
		long long temp = power(A, B / 2, C);

		if (B % 2 == 0)
			return (temp * temp) % C;
		else
			return ((temp * temp % C) * A) % C;
	}
}