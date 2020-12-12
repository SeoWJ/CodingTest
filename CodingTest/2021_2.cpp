#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<pair<string, int>> course_list;

void bruteForce(string order, string course, int pos);
bool compare(pair<string, int> p1, pair<string, int> p2);

vector<string> solution(vector<string> orders, vector<int> course) {
	vector<string> answer;

	for (unsigned int y = 0; y < orders.size(); y++) {
		for (unsigned int x = 0; x < orders[y].size(); x++) {
			string temp = "";
			temp += orders[y][x];
			bruteForce(orders[y], temp, x);
		}
   }

	sort(course_list.begin(), course_list.end(), compare);
	
	for (unsigned int x = 0; x < course.size(); x++) {
		vector<pair<string, int>> candidate;
		for (unsigned int y = 0; y < course_list.size(); y++) {
			if (candidate.size() == 0 && course_list[y].first.size() == course[x] && course_list[y].second >= 2)
				candidate.push_back(make_pair(course_list[y].first, course_list[y].second));
			else if (candidate.size() != 0 && course_list[y].first.size() == course[x] && course_list[y].second == candidate[0].second)
				candidate.push_back(make_pair(course_list[y].first, course_list[y].second));
		}

		for (unsigned int z = 0; z < candidate.size(); z++)
			answer.push_back(candidate[z].first);
	}

	sort(answer.begin(), answer.end());

	return answer;
}

bool compare(pair<string, int> p1, pair<string, int> p2) {
	if (p1.second != p2.second)
		return p1.second > p2.second;
	else
		return p1.first.size() > p2.first.size();
}

void bruteForce(string order, string course, int pos) {
	if (course.size() > 1) {
		bool inserted = false;
		for (unsigned int x = 0; x < course_list.size(); x++) {
			if (course_list[x].first == course) {
				course_list[x].second++;
				inserted = true;
				break;
			}
		}
		if (inserted == false) {
			course_list.push_back(make_pair(course, 1));
		}
	}

	if (pos == order.size() - 1)
		return;
	
	
	for (unsigned int x = pos + 1; x < order.size(); x++) {
		course += order[x];
		sort(course.begin(), course.end());
		bruteForce(order, course, x);
		
		for (string::iterator iter = course.begin(); iter != course.end(); iter++) {
			if (*iter == order[x]) {
				course.erase(iter);
				break;
			}
		}
	}
}

int main() {
	vector<string> orders = { "ABCDE", "AB", "CD", "ADE", "XYZ", "XYZ", "ACD" };
	vector<int> course = { 2,3,5 };
	
	vector<string> result = solution(orders, course);

	for (unsigned int x = 0; x < result.size(); x++)
		cout << result[x] << endl;

	return 0;
}