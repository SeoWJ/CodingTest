#include <string>
#include <vector>
#include <unordered_map>
#include <queue>

#define NULL 1
#define NUMBER 2
#define STRING 3

using namespace std;

vector<bool> solution(string program, vector<string> flag_rules, vector<string> commands) {
	vector<bool> answer;
	unordered_map<string, int> rules;

	/////// 각 flag와 flag가 요구하는 형태를 해시테이블에 저장 //////////

	for (unsigned int i = 0; i < flag_rules.size(); i++) {
		string flag; int arg;

		int idx = 0;
		while (flag_rules[i][idx] != ' ') flag += flag_rules[i][idx++];

		idx++;
		string argStr = flag_rules[i].substr(idx, flag_rules[i].size() - 1 - flag.size());

		if (argStr == "NULL") arg = NULL;
		else if (argStr == "NUMBER") arg = NUMBER;
		else arg = STRING;

		rules[flag] = arg;
	}

	//////// 명령어 분석 ///////////////

	for (unsigned int i = 0; i < commands.size(); i++) {
		/////// 입력된 커맨드를 큐에 스페이스 단위로 끊어서 삽입 //////
		vector<int> spacePosition;

		for (unsigned int j = 0; j < commands[i].size(); j++)
			if (commands[i][j] == ' ') spacePosition.push_back(j);

		queue<string> inputFlag;
		inputFlag.push(commands[i].substr(0, spacePosition[0]));
		for (unsigned int j = 0; j < spacePosition.size(); j++) {
			if (j == spacePosition.size() - 1)
				inputFlag.push(commands[i].substr(spacePosition[j] + 1, commands[i].size() - spacePosition[j] - 1));
			else
				inputFlag.push(commands[i].substr(spacePosition[j] + 1, spacePosition[j + 1] - spacePosition[j] - 1));
		}

		////////// 입력된 커맨드 중 프로그램 명 우선 확인 //////////

		string inputProgram = inputFlag.front();
		inputFlag.pop();

		if (inputProgram != program) {
			answer.push_back(false);
			continue;
		}

		//////////// 입력된 커맨드 비교 //////////////////

		bool correctCommand = true;
		int count[6] = { 0 };
		while (!inputFlag.empty()) {
			string flag = inputFlag.front();

			inputFlag.pop();

			if (rules[flag] == 0) {		// 무효한 플래그인 경우
				correctCommand = false;
				break;
			}
			else if (rules[flag] == NULL) {		// 플래그가 NULL일 때
				count[NULL]++;

				if (count[NULL] > 1 || (!inputFlag.empty() && inputFlag.front()[0] != '-')) {
					correctCommand = false;
					break;
				}
				else if (inputFlag.empty() || (!inputFlag.empty() && inputFlag.front()[0] == '-'))
					continue;
			}
			else if (rules[flag] == NUMBER) {		// 플래그가 넘버인 경우
				count[NUMBER]++;

				if (count[NUMBER] > 1 || inputFlag.empty()) {
					correctCommand = false;
					break;
				}

				string arg = inputFlag.front();
				inputFlag.pop();

				bool allNumber = true;		// 인자가 숫자인지를 확인
				for (unsigned int j = 0; j < arg.size(); j++) {
					if ('0' <= arg[j] && arg[j] <= '9') continue;
					else allNumber = false;
				}

				if (allNumber == false) {
					correctCommand = false;
					break;
				}
			}
			else if (rules[flag] == STRING) {		// 플래그가 스트링인 경우
				count[STRING]++;

				if (count[STRING] > 1 || inputFlag.empty()) {
					correctCommand = false;
					break;
				}

				string arg = inputFlag.front();
				inputFlag.pop();

				bool allAlphabet = true;		// 인자가 스트링인지 확인
				for (unsigned int j = 0; j < arg.size(); j++) {
					if (('A' <= arg[j] && arg[j] <= 'Z') || ('a' <= arg[j] && arg[j] <= 'z')) continue;
					else allAlphabet = false;
				}

				if (allAlphabet == false) {
					correctCommand = false;
					break;
				}
			}
		}

		if (correctCommand) answer.push_back(true);
		else answer.push_back(false);
	}

	return answer;
}
