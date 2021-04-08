#include <iostream>

#define endl '\n'

using namespace std;

int A, B;
int answer = 0;

void DFS(int currentNumber, int count);

int main(int argc, char* argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> A >> B;

	if (A == B) cout << 0 << endl;

	DFS(B, 1);

	cout << (answer == 0 ? -1 : answer) << endl;

	return 0;
}

void DFS(int currentNumber, int count) {
	if (currentNumber == A)
		answer = answer > count ? answer : count;
	else if (currentNumber < A)
		return;

	if (currentNumber % 10 == 1)
		DFS(currentNumber / 10, count + 1);
	if (currentNumber % 2 == 0)
		DFS(currentNumber / 2, count + 1);
}