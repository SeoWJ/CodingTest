#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

typedef pair<int, int> Job;		// turnaround time, arrival time

int solution(vector<vector<int>> jobs) {
	int answer = 0;
	int time = 0;
	priority_queue<Job, vector<Job>, greater<Job>> PQ;

	sort(jobs.begin(), jobs.end());

	for (unsigned int i = 0; i < jobs.size(); i++) {
		if (time <= jobs[i][0] && PQ.empty()) {
			time = jobs[i][0];
			time += jobs[i][1];
			answer += time - jobs[i][0];
		}
		else if (time <= jobs[i][0] && !PQ.empty()) {
			Job currentJob = PQ.top();
			PQ.pop();

			time += currentJob.first;
			answer += time - currentJob.second;
			i--;
		}
		else {
			PQ.push({ jobs[i][1], jobs[i][0] });
		}
	}

	while (!PQ.empty()) {
		Job currentJob = PQ.top();
		PQ.pop();

		time += currentJob.first;
		answer += time - currentJob.second;
	}

	return answer / jobs.size();
}

int main(){
	cout << solution({ {0, 3}, {1, 9}, {500, 6} }) << endl;;
}