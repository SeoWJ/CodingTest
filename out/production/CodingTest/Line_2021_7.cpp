#include <string>
#include <vector>
#include <unordered_map>
#include <queue>

#define NULL 1
#define NUMBER 2
#define STRING 3
#define NUMBERS 4
#define STRINGS 5

using namespace std;

vector<bool> solution(string program, vector<string> flag_rules, vector<string> commands) {
	vector<bool> answer;
	unordered_map<string, int> rules;

	/////// �� flag�� flag�� �䱸�ϴ� ���¸� �ؽ����̺� ���� //////////

	for (unsigned int i = 0; i < flag_rules.size(); i++) {
		string flag, argStr;
		int arg;

		vector<int> spacePosition;

		for (unsigned int j = 0; j < flag_rules[i].size(); j++)
			if (flag_rules[i][j] == ' ') spacePosition.push_back(j);

		queue<string> inputFlag;
		inputFlag.push(flag_rules[i].substr(0, spacePosition[0]));
		for (unsigned int j = 0; j < spacePosition.size(); j++) {
			if (j == spacePosition.size() - 1)
				inputFlag.push(flag_rules[i].substr(spacePosition[j] + 1, flag_rules[i].size() - spacePosition[j] - 1));
			else
				inputFlag.push(flag_rules[i].substr(spacePosition[j] + 1, spacePosition[j + 1] - spacePosition[j] - 1));
		}

		flag = inputFlag.front(); inputFlag.pop();
		argStr = inputFlag.front(); inputFlag.pop();

		if (argStr == "ALIAS") {
			argStr = inputFlag.front(); inputFlag.pop();
			int originalFlag = rules[argStr];

			if (originalFlag == 0) {
				flag_rules.push_back(*(flag_rules.begin() + i));
				flag_rules.erase(flag_rules.begin() + i--);
				continue;
			}
			else {
				arg = originalFlag;
				rules[flag] = arg;
				continue;
			}
		}

		if (argStr == "NULL") arg = NULL;
		else if (argStr == "NUMBER") arg = NUMBER;
		else if (argStr == "STRING") arg = STRING;
		else if (argStr == "NUMBERS") arg = NUMBERS;
		else if (argStr == "STRINGS") arg = STRINGS;

		rules[flag] = arg;
	}

	//////// ��ɾ� �м� ///////////////

	for (unsigned int i = 0; i < commands.size(); i++) {
		/////// �Էµ� Ŀ�ǵ带 ť�� �����̽� ������ ��� ���� //////
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

		////////// �Էµ� Ŀ�ǵ� �� ���α׷� �� �켱 Ȯ�� //////////

		string inputProgram = inputFlag.front();
		inputFlag.pop();

		if (inputProgram != program) {
			answer.push_back(false);
			continue;
		}

		//////////// �Էµ� Ŀ�ǵ� �� //////////////////

		bool correctCommand = true;
		int count[6] = { 0 };
		while (!inputFlag.empty()) {
			string flag = inputFlag.front();

			inputFlag.pop();

			if (rules[flag] == 0) {		// ��ȿ�� �÷����� ���
				correctCommand = false;
				break;
			}
			else if (rules[flag] == NULL) {		// �÷��װ� NULL�� ��
				count[NULL]++;
				
				if (count[NULL] > 1 || (!inputFlag.empty() && inputFlag.front()[0] != '-')) {
					correctCommand = false;
					break;
				}
				else if (inputFlag.empty() || (!inputFlag.empty() && inputFlag.front()[0] == '-'))
					continue;
			}
			else if (rules[flag] == NUMBER) {		// �÷��װ� �ѹ��� ���
				count[NUMBER]++;
				
				if (count[NUMBER] > 1 || inputFlag.empty()) {
					correctCommand = false;
					break;
				}

				string arg = inputFlag.front();
				inputFlag.pop();

				bool allNumber = true;		// ���ڰ� ���������� Ȯ��
				for (unsigned int j = 0; j < arg.size(); j++) {
					if ('0' <= arg[j] && arg[j] <= '9') continue;
					else allNumber = false;
				}

				if (allNumber == false) {
					correctCommand = false;
					break;
				}
			}
			else if (rules[flag] == STRING) {		// �÷��װ� ��Ʈ���� ���
				count[STRING]++;
				
				if (count[STRING] > 1 || inputFlag.empty()) {
					correctCommand = false;
					break;
				}

				string arg = inputFlag.front();
				inputFlag.pop();

				bool allAlphabet = true;		// ���ڰ� ��Ʈ������ Ȯ��
				for (unsigned int j = 0; j < arg.size(); j++) {
					if (('A' <= arg[j] && arg[j] <= 'Z') || ('a' <= arg[j] && arg[j] <= 'z')) continue;
					else allAlphabet = false;
				}

				if (allAlphabet == false) {
					correctCommand = false;
					break;
				}
			}
			else if (rules[flag] == NUMBERS) {		// �÷��װ� NUMBERS�� ���
				count[NUMBERS]++;
				
				if (count[NUMBERS] > 1 || inputFlag.empty()) {
					correctCommand = false;
					break;
				}

				bool allNumber = true;		// ���ڰ� ���������� Ȯ��
				while (!inputFlag.empty() && inputFlag.front()[0] != '-') {
					string arg = inputFlag.front();
					inputFlag.pop();

					for (unsigned int j = 0; j < arg.size(); j++) {
						if ('0' <= arg[j] && arg[j] <= '9') continue;
						else allNumber = false;
					}

					if (allNumber == false) {
						correctCommand = false;
						break;
					}
				}
			}
			else {		// �÷��װ� STRINGS�� ���
				count[STRINGS]++;
				
				if (count[STRINGS] > 1 || inputFlag.empty()) {
					correctCommand = false;
					break;
				}

				bool allAlphabet = true;		// ���ڰ� ��Ʈ������ Ȯ��
				while (!inputFlag.empty() && inputFlag.front()[0] != '-') {
					string arg = inputFlag.front();
					inputFlag.pop();

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
		}

		if (correctCommand) answer.push_back(true);
		else answer.push_back(false);
	}

	return answer;
}