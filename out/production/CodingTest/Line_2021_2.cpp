#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int rule1(string inp_str);
int rule2(string inp_str);
int rule3(string inp_str);
int rule4(string inp_str);
int rule5(string inp_str);

vector<int> solution(string inp_str) {
	vector<int> answer;

	int result;

	result = rule1(inp_str);
	if (result) answer.push_back(result);
	result = rule2(inp_str);
	if (result) answer.push_back(result);
	result = rule3(inp_str);
	if (result) answer.push_back(result);
	result = rule4(inp_str);
	if (result) answer.push_back(result);
	result = rule5(inp_str);
	if (result) answer.push_back(result);

	if (answer.empty()) answer.push_back(0);

	return answer;
}


int rule1(string inp_str) {
	if (8 <= inp_str.size() && inp_str.size() <= 15) return 0;
	else return 1;
}
int rule2(string inp_str) {
	for (unsigned int i = 0; i < inp_str.size(); i++) {
		if (('A' <= inp_str[i] && inp_str[i] <= 'Z') || ('a' <= inp_str[i] && inp_str[i] <= 'z') || ('0' <= inp_str[i] && inp_str[i] <= '9') ||
			inp_str[i] == '~' || inp_str[i] == '!' || inp_str[i] == '@' || inp_str[i] == '#' || inp_str[i] == '$' || inp_str[i] == '%' || inp_str[i] == '^' || inp_str[i] == '&' || inp_str[i] == '*')
			continue;
		else return 2;
	}
	return 0;
}
int rule3(string inp_str) {
	bool g1, g2, g3, g4;
	int groupCount = 0;
	g1 = g2 = g3 = g4 = false;
	
	for (unsigned int i = 0; i < inp_str.size(); i++) {
		if ('A' <= inp_str[i] && inp_str[i] <= 'Z')  g1 = true;
		else if ('a' <= inp_str[i] && inp_str[i] <= 'z') g2 = true;
		else if ('0' <= inp_str[i] && inp_str[i] <= '9') g3 = true;
		else if (inp_str[i] == '~' || inp_str[i] == '!' || inp_str[i] == '@' || inp_str[i] == '#' || inp_str[i] == '$' || inp_str[i] == '%' || inp_str[i] == '^' || inp_str[i] == '&' || inp_str[i] == '*') g4 = true;
	}

	if (g1) groupCount++;
	if (g2) groupCount++;
	if (g3) groupCount++;
	if (g4) groupCount++;

	if (groupCount >= 3) return 0;
	else return 3;
}
int rule4(string inp_str) {
	for (unsigned int i = 0; i < inp_str.size() - 3; i++) {
		string str = inp_str.substr(i, 4);

		if (str[0] == str[1] && str[1] == str[2] && str[2] == str[3])
			return 4;
	}
	return 0;
}
int rule5(string inp_str) {
	unordered_map<char, int> UM;

	for (unsigned int i = 0; i < inp_str.size(); i++) {
		UM[inp_str[i]]++;

		if (UM[inp_str[i]] == 5)
			return 5;
	}
	return 0;
}