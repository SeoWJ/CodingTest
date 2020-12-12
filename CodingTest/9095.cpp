#include <iostream>

#define endl "\n"

using namespace std;

void calculateIndex();

int ans[11] = { 0 };

int main(int argc, char* argv[]) {
	calculateIndex();
	int T; cin >> T;
	while (T--) {
		int n; cin >> n;
		cout << ans[n] << endl;
	}

	return 0;
}

void calculateIndex() {
	ans[1] = 1; ans[2] = 2; ans[3] = 4;
	for (int loop1 = 4; loop1 < 11; loop1++) {
		ans[loop1] = ans[loop1 - 1] + ans[loop1 - 2] + ans[loop1 - 3];
	}
}