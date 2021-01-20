#include <iostream>
#include <string>
#include <vector>

#define MAX 0x7FFFFFFFFFFFFFFF

using namespace std;

long long solution(int n, vector<int> times) {
	long long answer = 0;

	unsigned long long left = 0, right = MAX, mid = (left + right) / 2;

	while (1) {
		if (left >= right) {
			answer = mid;
			return answer;
		}

		unsigned long long check = 0;
		unsigned long long check2 = 0;

		for (unsigned int i = 0; i < times.size(); i++) {
			check += mid / times[i];
			check2 += (mid - 1) / times[i];
		}

		if (check == n && check2 < n) {
			answer = mid;
			return answer;
		}
		else if (check < n) {
			left = mid + 1;
			mid = (left + right) / 2;
		}
		else {	// (check > n)
			right = mid - 1;
			mid = (left + right) / 2;
		}
	}
}