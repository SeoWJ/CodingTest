#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
	vector<int> answer;
	int pattern_1st[10] = { 1,2,3,4,5,1,2,3,4,5 };
	int pattern_2nd[8] = { 2,1,2,3,2,4,2,5 };
	int pattern_3rd[10] = { 3,3,1,1,2,2,4,4,5,5 };

	int person[4] = { 0 };

	for (int x = 0; x < answers.size(); x++) {
		if (answers[x] == pattern_1st[x % 10]) person[1]++;
		if (answers[x] == pattern_2nd[x % 8]) person[2]++;
		if (answers[x] == pattern_3rd[x % 10]) person[3]++;
	}

	int max_score = 0;
	for (int x = 1; x <= 3; x++) max_score = max_score > person[x] ? max_score : person[x];

	for (int x = 1; x <= 3; x++) {
		if (person[x] == max_score)
			answer.push_back(x);
	}

	return answer;
}