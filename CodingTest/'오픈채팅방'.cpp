#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<string> solution(vector<string> record) {
	vector<string> answer;
	unordered_map<string, string> userTable;

	for (unsigned int i = 0; i < record.size(); i++) {
		string command = record[i].substr(0, 5);
		string userId;
		string userNickName;
		unsigned int idx;

		if (command == "Enter") {
			for (idx = 6; record[i][idx] != ' '; idx++)
				userId += record[i][idx];
			idx++;
			for (; idx < record[i].size(); idx++)
				userNickName += record[i][idx];

			answer.push_back(userId + "\n´ÔÀÌ µé¾î¿Ô½À´Ï´Ù.");
			userTable[userId] = userNickName;
		}
		else if (command == "Leave") {
			for (idx = 6; idx < record[i].size(); idx++)
				userId += record[i][idx];

			answer.push_back(userId + "\n´ÔÀÌ ³ª°¬½À´Ï´Ù.");
		}
		else {
			for (idx = 7; record[i][idx] != ' '; idx++)
				userId += record[i][idx];
			idx++;
			for (; idx < record[i].size(); idx++)
				userNickName += record[i][idx];

			userTable[userId] = userNickName;
		}
	}

	for (unsigned int i = 0; i < answer.size(); i++) {
		int idx = 0;

		for (; idx < answer[i].size(); idx++) {
			if (answer[i][idx] == '\n')
				break;
		}

		string userId = answer[i].substr(0, idx);
		string message = "";
		for (idx++; idx < answer[i].size(); idx++)
			message.push_back(answer[i][idx]);

		string newMessage = userTable[userId] + message;
		answer[i] = newMessage;
	}

	return answer;
}

int main() {
	solution({ "Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan" });
}