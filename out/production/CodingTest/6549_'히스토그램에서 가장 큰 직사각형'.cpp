#include <iostream>
#include <vector>

#define endl '\n'

using namespace std;

int N;
vector<int> square;

void solution();
long long divideAndConquer(int start, int end);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	while (1)
		solution();

	return 0;
}

void solution() {
	square.clear();
	cin >> N;

	if (N == 0) exit(0);

	for (int i = 0; i < N; i++) {
		int input; cin >> input;
		square.push_back(input);
	}

	cout << divideAndConquer(0, N - 1) << endl;
}

long long divideAndConquer(int start, int end) {
	if (start == end) return square[start];
	else {
		int mid = (start + end) / 2;

		long long leftMax = divideAndConquer(start, mid);
		long long rightMax = divideAndConquer(mid + 1, end);

		long long lowestSquare = 0x7FFFFFFF;
		for (int i = start; i <= end; i++) lowestSquare = lowestSquare < square[i] ? lowestSquare : square[i];
		long long thirdArea = lowestSquare * (end - start + 1);

		return leftMax > rightMax ? (leftMax > thirdArea ? leftMax : thirdArea) : (rightMax > thirdArea ? rightMax : thirdArea);
	}
}