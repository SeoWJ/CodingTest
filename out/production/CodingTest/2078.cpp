#include <iostream>

using namespace std;

void operation();

int main(int argc, char* argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	operation();

	return 0;
}

void operation() {
	int A, B; cin >> A >> B;
	int left_count = 0, right_count = 0;

	while (1) {
		if (A > B && B != 1) {
			left_count += (A / B);
			A = A % B;
		}
		if (A != 1 && A < B) {
			right_count += (B / A);
			B = B % A;
		}

		if (A == 1 && B != 1) {
			right_count += (B - 1);
			break;
		}

		if (A != 1 && B == 1) {
			left_count += (A - 1);
			break;
		}
	}

	cout << left_count << " " << right_count << endl;
}