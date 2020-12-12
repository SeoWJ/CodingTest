#include <iostream>
#include <vector>

typedef long long int64;

using namespace std;

void operation();

int main(int argc, char* argv[]) {
	ios::sync_with_stdio(false);
	operation();

	return 0;
}

void operation() {
	int K, N; cin >> K >> N;
	int64 cable[10000] = { 0 };
	int64 left = 1, right = 1, mid;
	vector<int64> possible_answer;

	for (int loop1 = 0; loop1 < K; loop1++) {
		cin >> cable[loop1];
		if (cable[loop1] > right)
			right = cable[loop1];
	}

	mid = (left + right) / 2;

	while (left <= right) {
		int cable_num = 0;
		mid = (left + right) / 2;

		for (int loop1 = 0; loop1 < K; loop1++)
			cable_num += (cable[loop1] / mid);

		if (cable_num >= N) {
			possible_answer.push_back(mid);
			left = mid + 1;
		}
		else
			right = mid - 1;
	}

	int64 answer = 0;
	for (unsigned int loop1 = 0; loop1 < possible_answer.size(); loop1++) {
		if (answer < possible_answer[loop1])
			answer = possible_answer[loop1];
	}

	cout << answer << endl;
}