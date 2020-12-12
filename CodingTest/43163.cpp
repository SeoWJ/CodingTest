#include <string>
#include <vector>

using namespace std;

int answer = 99999;

bool canChange(string original, string next) {
	int different_char = 0;

	for (unsigned int x = 0; x < original.size(); x++) {
		if (original[x] != next[x])
			different_char++;
	}

	if (different_char == 1)
		return true;
	else
		return false;
}

void bruteForce(string begin, string target, vector<string> words, vector<bool> visit, int changeNum) {
	if (begin == target) {
		answer = answer < changeNum ? answer : changeNum;
		return;
	}

	for (unsigned int x = 0; x < words.size(); x++) {
		if (canChange(begin, words[x]) && visit[x] == false) {
			visit[x] = true;
			bruteForce(words[x], target, words, visit, changeNum + 1);
			visit[x] = false;
		}
	}
}

int solution(string begin, string target, vector<string> words) {
	vector<bool> visit;
	visit.assign(words.size(), false);

	bool can_solve = false;
	for (unsigned int x = 0; x < words.size(); x++) {
		if (target == words[x])
			can_solve = true;
	}

	if (can_solve == false)
		return 0;

	for (unsigned int x = 0; x < words.size(); x++) {
		if (canChange(begin, words[x])) {
			visit[x] = true;
			bruteForce(words[x], target, words, visit, 1);
			visit[x] = false;
		}
	}

	return answer;
}