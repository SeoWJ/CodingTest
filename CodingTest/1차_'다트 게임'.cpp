#include <string>
#include <iostream>

using namespace std;

int solution(string dartResult) {
	int answer = 0;

	int score[3] = { 0 };
	char bonus[3] = { 0 };
	char option[3] = { 0 };

	int scoreIndex = 0, bonusIndex = -1, optionIndex = -1;

	for (auto c : dartResult) {
		if ('0' <= c && c <= '9') {
			score[scoreIndex] *= 10;
			score[scoreIndex] += c - '0';
		}
		else if ('A' <= c && c <= 'Z') {
			scoreIndex++;
			bonusIndex++;
			optionIndex++;

			bonus[bonusIndex] = c;
		}
		else
			option[optionIndex] = c;
	}

	for (int i = 0; i < 3; i++) {
		if (bonus[i] == 'D')
			score[i] = score[i] * score[i];
		else if (bonus[i] == 'T')
			score[i] = score[i] * score[i] * score[i];

		if (option[i] == '*') {
			if (i == 0) score[i] = score[i] * 2;
			else {
				score[i] = score[i] * 2;
				score[i - 1] = score[i - 1] * 2;
			}
		}
		else if (option[i] == '#')
			score[i] = score[i] * -1;
	}

	for (auto s : score)
		answer += s;

	return answer;
}

int main() {
	cout << solution("1S2D*3T") << endl;
}