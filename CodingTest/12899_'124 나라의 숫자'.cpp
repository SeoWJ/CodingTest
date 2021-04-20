#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

string convert[4] = { "", "1", "2", "4" };

string solution(int n) {
	string answer = "";
	deque<int> q;

	while (1) {
		if (n <= 3) {
			q.push_front(n);
			break;
		}

		if (n % 3 == 0) {
			q.push_front(3);
			n = n / 3 - 1;
		}
		else {
			q.push_front(n % 3);
			n /= 3;
		}
	}

	for (unsigned int i = 0; i < q.size(); i++) {
		answer += convert[q[i]];
	}

	return answer;
}

int main() {
	for (int i = 1; i < 100; i++)
		cout << i << " : " << solution(i) << endl << endl;
}