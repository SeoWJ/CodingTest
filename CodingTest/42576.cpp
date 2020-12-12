#include <iostream>
#include <vector>

#define endl '\n'
#define min(a,b) a < b ? a : b

using namespace std;

vector<string> hashtable[1000000];

string solution(vector<string> participant, vector<string> completion);

int main(int argc, char* argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	vector<string> participant;
	vector<string> completion;

	participant.push_back("eden");
	participant.push_back("kiki");
	participant.push_back("leo");

	completion.push_back("eden");
	completion.push_back("kiki");

	cout << solution(participant, completion) << endl;
}

string solution(vector<string> participant, vector<string> completion) {
	string answer = "";

	for (unsigned int y = 0; y < completion.size(); y++) {
		int hash_num = 1;
		
		for (unsigned int x = 0; x < completion[y].size(); x++)
			hash_num = (hash_num * completion[y][x]) % 1000000;

		hashtable[hash_num].push_back(completion[y]);
	}

	vector<string>::iterator iter;

	for (unsigned int y = 0; y < participant.size(); y++) {
		bool is_exist = false;
		int hash_num = 1;

		for (unsigned int x = 0; x < participant[y].size(); x++)
			hash_num = (hash_num * participant[y][x]) % 1000000;

		for (iter = hashtable[hash_num].begin(); iter != hashtable[hash_num].end(); iter++) {
			if (*iter == participant[y]) {
				hashtable[hash_num].erase(iter);
				is_exist = true;
				break;
			}
		}

		if (is_exist == true)
			continue;
		else {
			answer = participant[y];
			break;
		}
	}

	return answer;
}