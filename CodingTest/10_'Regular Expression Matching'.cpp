#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	bool isMatch(string s, string p) {
		vector<string> pattern;
		bool specialCharactorExist = false;

		for (unsigned int i = 0; i < p.size(); i++) {
			if (i != p.size()-1 && p[i + 1] == '*') {
				string temp = "";
				temp += p[i];
				temp += p[i + 1];
				pattern.push_back(temp);
				i++;
				specialCharactorExist = true;
			}
			else {
				string temp = "";
				temp += p[i];
				pattern.push_back(temp);
				if (p[i] == '.') specialCharactorExist = true;
			}
		}

		if (!specialCharactorExist) {
			if (s == p) return true;
			else return false;
		}
		else {
			int j = 0;
			for (unsigned int i = 0; i < pattern.size(); i++) {
				if (pattern[i].size() == 1) {
					if (pattern[i][0] == s[j] || pattern[i][0] == '.') {
						j++;
						continue;
					}
					else {
						return false;
					}
				}
				else {
					if (pattern[i] == ".*") {
						if (i == pattern.size() - 1) return true;
						else {
							while (1) {
								if (j == s.size()) return false;
								if (s[j] == pattern[i + 1][0]) break;
								else j++;
							}
						}
					}
					if (i != pattern.size() - 1 && pattern[i][0] == pattern[i + 1][0]) {
						if (pattern[i][0] != s[j]) continue;
						else {
							while (1) {
								if (pattern[i][0] != s[j]) break;
								else if (pattern[i][0] == s[j]) j++;
							}
							j--;
						}
					}
					else {
						while (1) {
							if (pattern[i][0] != s[j]) break;
							else if (pattern[i][0] == s[j]) j++;
						}
					}
				}
			}
			if (j == s.size())
				return true;
			else
				return false;
		}
	}
};

int main() {
	cout << Solution().isMatch("abc", "aaa") << endl;
}