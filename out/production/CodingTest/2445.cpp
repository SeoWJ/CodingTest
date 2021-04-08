#include <iostream>

#define endl "\n"

using namespace std;

void operation();

int main(int argc, char* argv[]) {
	operation();

	return 0;
}

void operation() {
	int N; cin >> N;

	for (int loop1 = 1; loop1 <= N; loop1++) {
		for (int loop2 = 1; loop2 <= loop1; loop2++)
			cout << "*";

		for (int loop2 = 1; loop2 <= N - loop1; loop2++)
			cout << " ";

		for (int loop2 = 1; loop2 <= N - loop1; loop2++)
			cout << " ";

		for (int loop2 = 1; loop2 <= loop1; loop2++)
			cout << "*";

		cout << endl;
	}

	for (int loop1 = 1; loop1 < N; loop1++) {
		for (int loop2 = 1; loop2 <= N - loop1; loop2++)
			cout << "*";

		for (int loop2 = 1; loop2 <= loop1; loop2++)
			cout << " ";

		for (int loop2 = 1; loop2 <= loop1; loop2++)
			cout << " ";

		for (int loop2 = 1; loop2 <= N - loop1; loop2++)
			cout << "*";

		cout << endl;
	}
}