#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<vector<char>> letter;
	vector<char> digit;
	unsigned int idx = 0;
	vector<string> answer;

	void DFS(unsigned int idx, vector<string> combination) {
		if (idx == 0) {
			for (int i = 0; i < letter[digit[idx]].size(); i++) {
				string temp = "";
				answer.push_back(temp + (char)('a' + letter[digit[idx]][i]));
			}
		}
		else {
			vector<string> result;
			for (unsigned int i = 0; i < combination.size(); i++) {
				for (int j = 0; j < letter[digit[idx]].size(); j++) {
					result.push_back(combination[i] + (char)('a' + letter[digit[idx]][j]));
				}
			}
			answer = result;
		}
	}	
	vector<string> letterCombinations(string digits) {
		char cnt = 0;
		vector<char> v;
		letter.assign(10, v);

		for (int i = 2; i < 10; i++) {
			if (i != 7 && i != 9) {
				for (int j = 0; j < 3; j++) {
					letter[i].push_back(cnt);
					cnt++;
				}
			}
			else {
				for (int j = 0; j < 4; j++) {
					letter[i].push_back(cnt);
					cnt++;
				}
			}
		}

		for (unsigned int i = 0; i < digits.size(); i++)
			digit.push_back(digits[i] - '0');

		for (unsigned int i = 0; i < digits.size(); i++)
			DFS(i, answer);

		return answer;
	}
};

int main() {
	Solution().letterCombinations("23");
}