#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
	int answer = 0;

	string student[30 + 2] = { "" };

	for (unsigned int x = 0; x < lost.size(); x++) student[lost[x]] = "lost";
	for (unsigned int x = 0; x < reserve.size(); x++) { 
		if (student[reserve[x]] == "lost") student[reserve[x]] = "";
		else student[reserve[x]] = "reserve"; 
	}

	queue<int> q;

	for (int x = 1; x <= n; x++) {
		if ((student[x - 1] != "reserve" && student[x] == "lost" && student[x + 1] == "reserve") || (student[x - 1] == "reserve" && student[x] == "lost" && student[x + 1] != "reserve"))
			q.push(x);
	}

	while (!q.empty()) {
		if (student[q.front() - 1] == "reserve") {
			student[q.front() - 1] = student[q.front()] = "";
		}
		if (student[q.front() + 1] == "reserve") {
			student[q.front() + 1] = student[q.front()] = "";
		}
		q.pop();
	}

	for (int x = 1; x <= n; x++) {
		if (student[x] == "reserve")
			q.push(x);
	}

	while (!q.empty()) {
		if (student[q.front() - 1] == "lost") {
			student[q.front() - 1] = student[q.front()] = "";
		}
		if (student[q.front() + 1] == "lost") {
			student[q.front() + 1] = student[q.front()] = "";
		}
		q.pop();
	}

	for (int x = 1; x <= n; x++) {
		if (student[x] == "" || student[x] == "reserve")
			answer++;
	}

	return answer;
}
