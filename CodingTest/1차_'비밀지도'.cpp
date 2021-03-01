#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
	vector<string> answer;
	string line;
	line.assign(n, ' ');
	answer.assign(n, line);

	for (unsigned int y = 0; y < n; y++) {
		unsigned int map1 = arr1[y];
		unsigned int map2 = arr2[y];

		int idx = 0;
		for (int x = n - 1; x >= 0; x--) {
			unsigned int m1 = map1 << (31 - idx);
			unsigned int m2 = map2 << (31 - idx);

			m1 >>= 31;
			m2 >>= 31;

			if (m1 == 1)
				answer[y][x] = '#';
			if (m2 == 1)
				answer[y][x] = '#';

			idx++;
		}
	}

	return answer;
}

int main() {
	solution(5, { 9, 20, 28, 18, 11 }, { 30, 1, 21, 17, 28 });
}