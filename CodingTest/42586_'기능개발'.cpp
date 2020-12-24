#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;

	deque<int> dq_progresses;
	deque<int> dq_speeds;
	for (unsigned int i = 0; i < progresses.size(); i++) {
		dq_progresses.push_back(progresses[i]);
		dq_speeds.push_back(speeds[i]);
	}

	while (!dq_progresses.empty()) {
		for (int i = 0; i < dq_progresses.size(); i++)
			dq_progresses[i] += dq_speeds[i];

		int distribution = 0;
		while (dq_progresses.front() >= 100 && !dq_progresses.empty()) {
			dq_progresses.pop_front();
			dq_speeds.pop_front();
			distribution++;
		}

		if(distribution != 0)
			answer.push_back(distribution);
	}

	return answer;
}