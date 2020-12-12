#include <iostream>
#include <cstring>

#define endl '\n'
#define min2(A,B) A < B ? A : B
#define min3(A,B,C) A < B ?  (A < C ? A : C) : (B < C ? B : C)

using namespace std;

int num[10001];

void pi();
int check(int _start, int _end);
void clear();

int main(int argc, char* argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int C; cin >> C;

	while (C--)
		pi();

	return 0;
}

void pi() {
	clear();

	string input; cin >> input;
	int dp[10001] = { 0 };

	for (unsigned int x = 1; x <= input.size(); x++) num[x] = input[x - 1] - '0';

	dp[3] = check(1, 3);
	dp[4] = check(1, 4);
	dp[5] = check(1, 5);
	dp[6] = check(1, 3) + check(4, 6);
	dp[7] = min2(check(1, 3) + check(4, 7), check(1, 4) + check(5, 7));
	dp[8] = min3(check(1, 3) + check(4, 8), check(1, 4) + check(5, 8), check(1, 5) + check(6, 8));

	for (unsigned int x = 9; x <= input.size(); x++) {
		dp[x] = min3(dp[x - 3] + check(x - 2, x), dp[x - 5] + check(x - 4, x), dp[x - 4] + check(x - 3, x));
	}
	cout << dp[input.size()] << endl;
}

int check(int _start, int _end) {
	bool one = true, two = true, four = true, five = true;
	int previous = num[_start + 1] - num[_start];

	for (int x = _start + 2; x <= _end; x++) {
		int difference = num[x] - num[x - 1];
		
		if (previous == 0 && difference == 0)
			two = four = five = false;
		else if ((previous == 1 && difference == 1) || (previous == -1 && difference == -1))
			one = four = five = false;
		else if (previous == difference * (-1))
			one = two = five = false;
		else if (previous == difference)
			one = two = four = false;
		else
			one = two = four = five = false;

		previous = difference;
	}

	if (one == true)
		return 1;
	if (two == true)
		return 2;
	if (four == true)
		return 4;
	if (five == true)
		return 5;
	
	return 10;
}

void clear() {
	for (int x = 0; x < 10001; x++) num[x] = 0;
}