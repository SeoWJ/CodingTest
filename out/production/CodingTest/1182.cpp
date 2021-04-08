#include <iostream>

#define endl '\n'

using namespace std;

int N, S;
int arr[20] = { 999999 };
int answer = 0;

void sum();
void count_ans(int _start, int _sum);

int main(int argc, char* argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	sum();

	return 0;
}

void sum() {
	cin >> N >> S;

	for (int loop1 = 0; loop1 < N; loop1++) {
		cin >> arr[loop1];
	}

	int arr[20] = { 0 };

	for (int loop1 = 0; loop1 < N; loop1++)
		count_ans(loop1, 0);

	cout << answer << endl;
}

void count_ans(int _start, int _sum) {
	_sum += arr[_start];

	if (_sum == S)
		answer++;

	for (int loop1 = _start + 1; loop1 < N; loop1++)
		count_ans(loop1, _sum);
}