#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<int, int> Log;		// <start, end>
typedef pair<Log, int> CommonTime; // <<start, end>, peoplecount>

int strToInt(string log, int idx);
Log convert(string log);
bool compare(CommonTime c1, CommonTime c2);
string convert(int second);

string solution(string play_time, string adv_time, vector<string> logs) {
	string answer = "";

	if (play_time == adv_time)
		return "00:00:00";

	int playTime = strToInt(play_time, 0) * 3600 + strToInt(play_time, 3) * 60 + strToInt(play_time, 6);
	int advTime = strToInt(adv_time, 0) * 3600 + strToInt(adv_time, 3) * 60 + strToInt(adv_time, 6);

	priority_queue<Log, vector<Log>, greater<Log>> PQ;
	deque<CommonTime> timeLine;

	for (unsigned int i = 0; i < logs.size(); i++)
		PQ.push(convert(logs[i]));

	while (!PQ.empty()) {
		int logStart = PQ.top().first;
		int logEnd = PQ.top().second;
		PQ.pop();

		if (timeLine.empty()) {
			timeLine.push_back({ { logStart, logEnd }, 1 });
		}
		else {
			int commonStart = timeLine[timeLine.size() - 1].first.first;
			int commonEnd = timeLine[timeLine.size() - 1].first.second;

			if (commonStart <= logStart && logEnd <= commonEnd) {
				timeLine[timeLine.size() - 1].first.first = logStart;
				timeLine[timeLine.size() - 1].first.second = logEnd;
				timeLine[timeLine.size() - 1].second++;
			}
			else if (logStart < commonStart && commonStart <= logEnd && logEnd <= commonEnd) {
				timeLine[timeLine.size() - 1].first.second = logEnd;
				timeLine[timeLine.size() - 1].second++;
			}
			else if (commonStart < logStart && logStart <= commonEnd && commonEnd <= logEnd) {
				timeLine[timeLine.size() - 1].first.first = logStart;
				timeLine[timeLine.size() - 1].second++;
			}
			else {
				timeLine.push_back({ {logStart, logEnd}, 1 });
			}
		}
	}

	sort(timeLine.begin(), timeLine.end(), compare);

	answer = convert(timeLine[0].first.second - advTime);

	return answer;
}

int strToInt(string log, int idx) {
	int result = 0;
	result += log[idx] - '0';
	idx++;
	result *= 10;
	result += log[idx] - '0';

	return result;
}

Log convert(string log) {
	int startHour, startMinute, startSecond;
	int endHour, endMinute, endSecond;

	int startPoint, endPoint;

	startHour = strToInt(log, 0);
	startMinute = strToInt(log, 3);
	startSecond = strToInt(log, 6);
	endHour = strToInt(log, 9);
	endMinute = strToInt(log, 12);
	endSecond = strToInt(log, 15);

	startPoint = startHour * 3600 + startMinute * 60 + startSecond;
	endPoint = endHour * 3600 + endMinute * 60 + endSecond;

	return { startPoint, endPoint };
}

string convert(int second) {
	int h, m, s;
	string result = "";
	
	h = second / 3600;
	second -= 3600 * h;

	m = second / 60;
	second -= 60 * m;

	s = second;

	if (h < 10)
		result += '0';
	result += to_string(h) + ":";

	if (m < 10)
		result += '0';
	result += to_string(m) + ":";

	if (s < 10)
		result += '0';
	result += to_string(s);

	return result;
}

bool compare(CommonTime c1, CommonTime c2) {
	if (c1.second != c2.second)
		return c1.second > c2.second;
	else
		return c1.first.first < c2.first.first;
}

int main() {
	solution("99:59:59", "25:00:00", { "69:59:59-89:59:59", "01:00:00-21:00:00", "79:59:59-99:59:59", "11:00:00-31:00:00" });
}