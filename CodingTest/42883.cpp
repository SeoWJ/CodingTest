#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <iostream>

using namespace std;

string solution(string number, int k) {
	string answer = "";
	stack<char> S;
	const int answer_length = number.size() - k;
	
	int i = 0;
	while(1) {
		if (S.size() == answer_length)
			break;

		if (S.size() == answer_length - 1) {
			int max = 0;
			for (; i < number.size(); i++) {
				max = number[i] > max ? number[i] : max;
			}
			S.push(max);
			continue;
		}

		if (answer_length - S.size() > number.size() - 1 - i) {
			S.push(number[i]);
			i++;
		}
		else {
			if (S.empty()) {
				S.push(number[i]);
				i++;
				continue;
			}
			if (S.top() >= number[i]) {
				S.push(number[i]);
				i++;
			}
			else {
				if (S.top() >= number[i]) {
					S.push(number[i]);
					i++;
				}
				else {
					S.pop();
					continue;
				}
			}
		}
	}

	string temp = "";
	while(!S.empty()) {
		temp.push_back(S.top());
		S.pop();
	}

	while (temp != "") {
		answer.push_back(temp.back());
		temp.pop_back();
	}

	while(1) {
		string::iterator iter = answer.begin();
		if (answer.size() == 1)
			break;
		if (*iter == '0')
			answer.erase(iter);
		else
			break;
	}

	return answer;
}

int main() {
	cout << solution("0000", 2) << endl;
}