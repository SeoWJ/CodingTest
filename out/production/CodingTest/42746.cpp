#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool compare(int i1, int i2);

string solution(vector<int> numbers) {
	string answer = "";

	sort(numbers.begin(), numbers.end(), compare);

	for (unsigned int x = 0; x < numbers.size(); x++) {
		answer += to_string(numbers[x]);
	}

	bool all_zero = true;
	for (unsigned int x = 0; x < answer.size(); x++) {
		if (answer[x] != '0')
			all_zero = false;
	}

	if (all_zero == true) return "0";

	return answer;
}

bool compare(int i1, int i2) {
	string s1 = to_string(i1) + to_string(i2);
	string s2 = to_string(i2) + to_string(i1);

	for (unsigned int x = 0; x < s1.size(); x++) {
		if (s1[x] == s2[x])
			continue;
		else if (s1[x] > s2[x])
			return true;
		else
			return false;
	}
	return false;
}

int main() {
	vector<int> v;

	v.push_back(0);
	v.push_back(0);
	v.push_back(0);
	v.push_back(0);
	v.push_back(0);
	v.push_back(0);

	cout << solution(v) << endl; 
}