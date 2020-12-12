#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long factorial(int n);

vector<int> solution(int n, long long k) {
	vector<int> answer;

	vector<pair<int, bool>> people;
	for (int x = 1; x <= n; x++) people.push_back(make_pair(x, true));

	while (answer.size() != n) {
		long long jump = factorial(n - (answer.size() + 1));
		for (int i = 0; i < n; i++) {
			if (people[i].second == false)
				continue;
			if (k > jump) {
				k -= jump;
				continue;
			}
			else {
				answer.push_back(people[i].first);
				people[i].second = false;

				break;
			}
		}
	}

	return answer;
}

long long factorial(int n) {
	long long result = 1;
	for (int x = 1; x <= n; x++) {
		result *= x;
	}

	return result;
}

int main() {
	int n = 3;
	int k = 5;

	vector<int> result = solution(n, k);
}