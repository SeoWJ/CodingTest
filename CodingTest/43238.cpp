#include <string>
#include <vector>
#include <iostream>

typedef unsigned long long ull;

#define MAX 9223372036854775807

using namespace std;

long long solution(int n, vector<int> times) {
	long long answer = 0;
	ull left = 0, right = MAX, mid = (left + right) / 2;

	while (1) {
		ull checked = 0;
		ull checked2 = 0;
		for (unsigned int x = 0; x < times.size(); x++) {
			checked += mid / times[x];
			checked2 += (mid - 1) / times[x];
		}
		//cout << "LEFT : " << left << " RIGHT : " << right << " MID : " << mid << " CHECKED(1) : " << checked << " CHECKED(2) : " << checked2 << " " << endl;

		if (checked == n && checked2 < n) {
			answer = mid;
			return answer;
		}
		else if (checked < n) {
			left = mid + 1;
			mid = (left + right) / 2;
			if (left == right) {
				answer = mid;
				return answer;
			}
			continue;
		}
		else {
			right = mid - 1;
			mid = (left + right) / 2;
			if (left == right) {
				answer = mid;
				return answer;
			}
			continue;
		}
	}
}

int main() {
	int n = 6;
	vector<int> times;
	/*times.push_back(7);
	times.push_back(10);*/

	times.push_back(1);
	times.push_back(1);
	times.push_back(1);
	times.push_back(1);

	cout << solution(n, times) << endl;
}