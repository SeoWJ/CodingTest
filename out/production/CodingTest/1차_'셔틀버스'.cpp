#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

string solution(int n, int t, int m, vector<string> timetable) {
	string answer = "";

	priority_queue<int, vector<int>, greater<int>> PQ;

	for (unsigned int i = 0; i < timetable.size(); i++) {
		int hour = atoi(timetable[i].substr(0, 2).c_str());
		int minute = atoi(timetable[i].substr(3, 2).c_str());

		PQ.push(hour * 60 + minute);
	}

	int conTime = -1;
	
	for (int i = 0; i < n; i++) {
		int busTime = 9 * 60 + i * t;
		int busPeopleCount = 0;

		while (!PQ.empty() && PQ.top() <= busTime) {
			busPeopleCount++;
			
			if (i == n - 1 && busPeopleCount == m) {
				conTime = PQ.top() - 1;
				break;
			}
			else if (i != n - 1 && busPeopleCount == m) {
				PQ.pop();
				break;
			}
			PQ.pop();
		}
	}

	if (conTime == -1)
		conTime = 9 * 60 + (n - 1) * t;

	if (conTime / 60 < 10) answer += '0';
	answer += to_string(conTime / 60);
	answer += ':';
	conTime %= 60;
	if (conTime < 10) answer += '0';
	answer += to_string(conTime);

	return answer;
}

int main() {
	cout << solution(2, 1, 2, { "09:00", "09:00", "09:00", "09:00" }) << endl;
}