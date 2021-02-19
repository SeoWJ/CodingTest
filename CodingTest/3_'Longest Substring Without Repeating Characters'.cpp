#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
	unordered_map<char, bool> longestSubstring;
	unordered_map<char, bool> recent;

	int lengthOfLongestSubstring(string s) {
		if (s.empty()) return 0;

		longestSubstring[s[0]] = true;
		recent[s[0]] = true;

		for (unsigned int i = 1; i < s.size(); i++) {
			if (recent[s[i]] == false) {
				recent[s[i]] = true;
			}
			else {
				int j = i;
				recent.clear();
				while (1) {
					if (recent[s[j]] == false) {
						recent[s[j]] = true;
						j--;
					}
					else break;
				}
			}
			longestSubstring = longestSubstring.size() > recent.size() ? longestSubstring : recent;
		}

		return longestSubstring.size();
	}
};

int main() {
	cout << Solution().lengthOfLongestSubstring("dvdf") << endl;
}