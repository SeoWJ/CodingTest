#include <iostream>
#include <deque>
#include <string>

#define endl '\n'

using namespace std;

//nCr = n! / (n-r)!r!
// nCr = (n-1)C(r-1) + (n-1)Cr

string dp[101][101] = { "" };

string nCr(string n, string r);
string bigIntAdd(string n1, string n2);

int main(int argc, char* argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for (int n = 1; n < 101; n++) {
		dp[1][n] = to_string(n);
		dp[n][n] = to_string(1);
	}

	int n, r; cin >> n >> r;
	cout << nCr(to_string(n), to_string(r)) << endl;
	//cout << bigIntAdd(to_string(n), to_string(r)) << endl;
	dp[0][0] = "";

	return 0;
}

string nCr(string n, string r) {
	if (dp[stoi(r)][stoi(n)] == "") {
		dp[stoi(r)][stoi(n)] = bigIntAdd(nCr(to_string(stoi(n) - 1), to_string(stoi(r) - 1)), nCr(to_string(stoi(n) - 1), r));
	}
	return dp[stoi(r)][stoi(n)];
}

string bigIntAdd(string n1, string n2) {
	int n1_pos = n1.size() - 1;
	int n2_pos = n2.size() - 1;
	deque<char> result;
	char up = 0;
	
	while (1) {
		char temp = (n1[n1_pos] - '0') + (n2[n2_pos] - '0') + up;
		result.push_front((temp % 10)+ '0');
		up = temp / 10;

		n1_pos--;
		n2_pos--;

		if (n1_pos == -1 && n2_pos == -1) {
			if (up != 0)
				result.push_front(up + '0');
			break;
		}
		if (n1_pos == -1 || n2_pos == -1) break;
	}

	if (n1_pos != -1) {
		while (n1_pos > -1) {
			char temp = (n1[n1_pos] - '0') + up;
			result.push_front((temp % 10) + '0');
			up = temp / 10;

			n1_pos--;
		}
		if (up != 0)
			result.push_front(up + '0');
	}

	if (n2_pos != -1) {
		while (n2_pos > -1) {
			char temp = (n2[n2_pos] - '0') + up;
			result.push_front((temp % 10) + '0');
			up = temp / 10;

			n2_pos--;
		}
		if (up != 0)
			result.push_front(up + '0');
	}

	string result_str = "";

	for (int i = 0; i < result.size(); i++)
		result_str += result[i];

	return result_str;
}