#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(vector<string> v1, vector<string> v2);
int solution(vector<vector<string>> clothes);

int main() {
	vector<string> v;
	vector<vector<string>> vv;
	v.push_back("yellow_hat");
	v.push_back("headgear");
	vv.push_back(v);
	v[0] = "blue_sunglasses";
	v[1] = "eyewear";
	vv.push_back(v);
	v[0] = "green_turban";
	v[1] = "headgear";
	vv.push_back(v);

	cout << solution(vv) << endl;

}

int solution(vector<vector<string>> clothes) {
	int answer = 0;
	
	sort(clothes.begin(), clothes.end(), compare);
	vector<int> parts;
	int p_index = 0;
	parts.push_back(1);

	for (unsigned int x = 1; x < clothes.size(); x++) {
		if (clothes[x - 1][1] == clothes[x][1])
			parts[p_index]++;
		else {
			parts.push_back(1);
			p_index++;
		}
	}

	int result = 1;
	for (unsigned int x = 0; x < parts.size(); x++) { 
		++parts[x]; 
		result *= parts[x];
	}

	answer = --result;

	return answer;
}

bool compare(vector<string> v1, vector<string> v2) {
	return v1[1] < v2[1];
}