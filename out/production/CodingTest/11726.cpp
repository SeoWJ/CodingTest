#include <iostream>

#define endl "\n"

using namespace std;

void operation(int n);

int main(int argc, char* argv[]) {
	ios::sync_with_stdio(false);
	cin.tie();

	int n; cin >> n;
	operation(n);
}

void operation(int n) {
	int arr[1001] = { 0,1,2 };

	if (n == 1) {
		cout << "1" << endl;
		return;
	}

	else if (n == 2) {
		cout << "2" << endl;
		return;
	}

	for (int loop1 = 3; loop1 <= n; loop1++)
		arr[loop1] = (arr[loop1 - 1] + arr[loop1 - 2]) % 10007;

	cout << arr[n] << endl;
	return;
}