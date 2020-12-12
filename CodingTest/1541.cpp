#include <iostream>

#define endl '\n'

using namespace std;

string input;
int idx = 0;

void missingBracket();
int readNumber();
int handleMinus();

int main(int argc, char* argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	missingBracket();

	return 0;
}

int readNumber() {
	int result = 0;

	for (;;) {
		if (idx == input.size()) break;
		if (input[idx] == '+' || input[idx] == '-') break;
		else {
			result *= 10;
			result += input[idx] - '0';
		}
		idx++;
	}

	return result;
}

int handleMinus() {
	int result = readNumber();

	while (1) {
		if (idx == input.size()) return result * -1;
		if (input[idx] == '-') return result * -1;
		else if (input[idx] == '+') { ++idx; result += readNumber(); }
	}
}

void missingBracket() {
	cin >> input;

	int result = 0;

	for (;;) {
		if (input[0] != '-') result += readNumber();
		if (input[idx] == '-') { ++idx;  result += handleMinus(); }
		else if (input[idx] == '+') { ++idx;  result += readNumber(); }

		if (idx == input.size()) break;
	}

	cout << result << endl;
}