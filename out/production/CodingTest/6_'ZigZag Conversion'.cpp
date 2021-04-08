#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	string convert(string s, int numRows) {
		if (numRows == 1)
			return s;

		vector<vector<char>> pattern;
		vector<char> temp;

		temp.assign(1000, NULL);
		pattern.assign(numRows, temp);

		bool goDown = true;
		unsigned int position = 0;
		int y = 0, x = 0;
		bool finished = false;

		while (position < s.size()) {
			if (goDown == true) {
				for (; y < numRows; y++) {
					pattern[y][x] = s[position];
					position++;

					if (position == s.size()) break;
				}
			}
			else {
				y -= 2;
				x++;

				for (; y > 0; y--) {
					pattern[y][x] = s[position];
					position++;
					x++;

					if (position == s.size()) break;
				}
			}

			goDown = !goDown;
		}

		string answer = "";

		for (int y = 0; y < numRows; y++) {
			for (int x = 0; x < 1000; x++) {
				if (pattern[y][x] != NULL)
					answer += pattern[y][x];
			}
		}

		return answer;
	}
};

int main() {
	cout << Solution().convert("AB", 1) << endl;
}