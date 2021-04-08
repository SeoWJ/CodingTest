#include <iostream>

#define endl '\n'

using namespace std;

int answer = 0;
int n;

void oneTwoThreePlus();
void bruteForce(int now);

int main(int argc, char* argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T; cin >> T;

	while(T--)
		oneTwoThreePlus();

	return 0;
}

void oneTwoThreePlus() {
	cin >> n;

	for (int x = 1; x <= 3; x++)
		bruteForce(x);

	cout << answer << endl;
	answer = 0;
}

void bruteForce(int now) {
	if (now == n) {
		answer++;
		return;
	}

	if (now > n)
		return;

	for (int x = 1; x <= 3; x++)
		bruteForce(now + x);
}