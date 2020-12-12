#include <iostream>
#include <vector>

#define endl "\n"

using namespace std;

void operation();

int main(int argc, char* argv[]) {
	operation();

	return 0;
}

int max(int a, int b) {
	if (a > b)
		return a;
	else
		return b;
}

int max(int a, int b, int c) {
	if (a > b) {
		if (a > c)
			return a;
		else
			return c;
	}
	else { // a < b
		if (b < c)
			return c;
		else
			return b;
	}
}

void operation() {
	int stair_num; cin >> stair_num;
	vector<int> stair;
	vector<int> case_arr;

	for (int loop1 = 0; loop1 < stair_num; loop1++) {
		int input; cin >> input;
		stair.push_back(input);
	}

	if (stair_num == 1)
		cout << stair[0] << endl;
	else if (stair_num == 2)
		cout << stair[0] + stair[1] << endl;
	else if (stair_num == 3) {
		int ans = stair[0] + stair[2] > stair[1] + stair[2] ? stair[0] + stair[2] : stair[1] + stair[2];
		cout << ans << endl;
	}
	else if (stair_num == 4) {
		int ans = stair[3] + max(stair[2] + stair[0], stair[1] + stair[0], stair[1]);
		cout << ans << endl;
	}
	else {
		case_arr.push_back(stair[0]);
		case_arr.push_back(stair[0] + stair[1]);
		case_arr.push_back(stair[0] + stair[2] > stair[1] + stair[2] ? stair[0] + stair[2] : stair[1] + stair[2]);
		case_arr.push_back(stair[3] + max(stair[2] + stair[0], stair[1] + stair[0], stair[1]));
		for (int loop1 = 4; loop1 < stair_num; loop1++) {
			case_arr.push_back(max(case_arr[loop1 - 2] + stair[loop1], case_arr[loop1 - 3] + stair[loop1 - 1] + stair[loop1]));
		}
		cout << case_arr[stair_num - 1] << endl;
	}
}