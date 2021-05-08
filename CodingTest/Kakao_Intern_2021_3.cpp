#include <string>
#include <vector>
#include <stack>

using namespace std;

/*string solution(int n, int k, vector<string> cmd) {
	string answer = "";
	deque<int> table;
	deque<int> tableOriginal;
	stack<pair<int, int>> repair;
	int currentIndex = k;

	for (int i = 0; i < n; i++)
		table.push_back(i);
	tableOriginal = table;

	for (unsigned int i = 0; i < cmd.size(); i++) {
		char command = cmd[i][0];
		int x = 0;

		if (command == 'D' || command == 'U')
			x = atoi(cmd[i].substr(2, cmd[i].size() - 2).c_str());

		if (command == 'D')
			currentIndex += x;
		else if (command == 'U')
			currentIndex -= x;
		else if (command == 'C') {
			repair.push({ currentIndex, table[currentIndex] });
			table.erase(table.begin() + currentIndex);

			if (currentIndex == table.size())
				currentIndex -= 1;
		}
		else {
			int insertIndex = repair.top().first;
			int insertContent = repair.top().second;

			repair.pop();

			if (insertIndex <= currentIndex)
				currentIndex++;
			table.insert(table.begin() + insertIndex, insertContent);
		}
	}

	int tableIndex = 0;
	for (unsigned int i = 0; i < tableOriginal.size(); i++) {
		if (tableOriginal[i] == table[tableIndex]) {
			answer += "O";
			tableIndex++;
		}
		else
			answer += "X";
	}

	return answer;
}*/

string solution(int n, int k, vector<string> cmd) {
	string answer = "";
	deque<pair<int, bool>> table;
	deque<pair<int, bool>> tableOriginal;
	stack<int> repair;
	int currentIndex = k, realIndex = k;

	for (int i = 0; i < n; i++)
		table.push_back({ i, true });
	tableOriginal = table;
	int realTableSize = table.size();

	for (unsigned int i = 0; i < cmd.size(); i++) {
		char command = cmd[i][0];
		int x = 0;

		if (command == 'D' || command == 'U')
			x = atoi(cmd[i].substr(2, cmd[i].size() - 2).c_str());

		if (command == 'D') {
			while (x--) {
				if (table[++currentIndex].second == false)
					x++;
			}
		}
		else if (command == 'U') {
			while (x--) {
				if (table[--currentIndex].second == false)
					x++;
			}
		}
		else if (command == 'C') {
			repair.push(currentIndex);
			table[currentIndex].second = false;

			realTableSize--;
			
		}
		else {
		}
	}
	return answer;
}