#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(string s) {
	int answer = 0;
	unordered_map<string, string> number;

	number["one"] = "1";
	number["two"] = "2";
	number["three"] = "3";
	number["four"] = "4";
	number["five"] = "5";
	number["six"] = "6";
	number["seven"] = "7";
	number["eight"] = "8";
	number["nine"] = "9";
	number["zero"] = "0";

	string answerString = "";
	string temp = "";

	for (unsigned int i = 0; i < s.size(); i++) {
		if ('0' <= s[i] && s[i] <= '9')
			answerString += s[i];
		else {
			temp += s[i];

			if (number[temp] != "") {
				answerString += number[temp];
				temp.clear();
			}
		}
	}

	answer = atoi(answerString.c_str());

	return answer;
}

#include <iostream>

int main() {
	solution("one4seveneight");
}