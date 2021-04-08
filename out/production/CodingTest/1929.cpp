#include <iostream>
#include <cmath>

#define endl "\n"

struct number {
	int num;
	bool prime = true;
};

using namespace std;

number* arr[1000001] = { NULL };

void operation();

int main(int argc, char* argv[]) {
	ios::sync_with_stdio(false);
	cin.tie();

	operation();

	return 0;
}

void operation() {
	int M, N; cin >> M >> N;

	for (int loop1 = 0; loop1 <= N; loop1++) {
		arr[loop1] = new number();
		arr[loop1]->num = loop1;
	}

	int root_N = sqrt(N);

	for (int loop1 = 2; loop1 <= root_N; loop1++) {
		for (int loop2 = loop1 * 2; loop2 <= N; loop2 += loop1) {
			if (arr[loop1]->prime == false)
				continue;
			arr[loop2]->prime = false;
		}
	}

	arr[0]->prime = false;
	arr[1]->prime = false;

	for (int loop1 = M; loop1 <= N; loop1++) {
		if (arr[loop1]->prime == true)
			cout << arr[loop1]->num << endl;
	}
}