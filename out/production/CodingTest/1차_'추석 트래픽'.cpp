#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

typedef pair<int, int> Time;

int solution(vector<string> lines) {
	int answer = 0;

	priority_queue<Time, vector<Time>, greater<Time>> PQ;
	vector<pair<Time, vector<Time>>> list;

	for (unsigned int i = 0; i < lines.size(); i++) {
		int hour = atoi(lines[i].substr(11, 2).c_str());
		int minute = atoi(lines[i].substr(14, 2).c_str());
		int second = atoi(lines[i].substr(17, 2).c_str());
		int milisecond = atoi(lines[i].substr(20, 3).c_str());

		string t = "";
		for (unsigned int idx = 24; idx < lines[i].size(); idx++) {
			if (lines[i][idx] == 's') break;
			else t += lines[i][idx];
		}
		int T = (int)(atof(t.c_str()) * 1000) - 1;
		
		int endTime = hour * 3600000 + minute * 60000 + second * 1000 + milisecond;
		int startTime = endTime - T;

		PQ.push({ startTime, endTime });
	}

	while (!PQ.empty()) {
		int startTime = PQ.top().first;
		int endTime = PQ.top().second;
		
		PQ.pop();
		
		bool inserted = false;
		for (unsigned int i = 0; i < list.size(); i++) {
			int* commonStart = &list[i].first.first;
			int* commonEnd = &list[i].first.second;

			if (startTime < *commonStart && *commonStart <= endTime && endTime <= *commonEnd) {
				*commonStart = startTime - 999;
				list[i].second.push_back({ startTime, endTime });
				inserted = true;
			}
			else if (*commonStart <= startTime && endTime <= *commonEnd) {
				list[i].second.push_back({ startTime, endTime });
				inserted = true;
			}
			else if (*commonStart <= startTime && startTime <= *commonEnd && *commonEnd < endTime) {
				*commonEnd = endTime + 999;
				list[i].second.push_back({ startTime, endTime });
				inserted = true;
			}
		}
		
		if(!inserted) list.push_back({ {startTime - 999, endTime + 999}, { { startTime, endTime } } });
	}

	for (unsigned int i = 0; i < list.size(); i++) {
		for (int j = list[i].first.first; j < list[i].first.second; j++) {
			int jobCount = 0;
			for (unsigned int k = 0; k < list[i].second.size(); k++) {
				if (list[i].second[k].first <= j && j <= list[i].second[k].second + 999)
					jobCount++;
			}
			answer = answer > jobCount ? answer : jobCount;
		}
	}

	return answer;
}

int main() {
	cout << solution({ "2016-09-15 01:00:04.002 2.0s", "2016-09-15 01:00:07.000 2s" }) << endl;
}