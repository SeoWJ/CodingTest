#include <iostream>
#include <sstream>
#include <vector>
#include <stack>

using namespace std;

string order;

bool isAlphabet(char c);
bool isNum(char c);
bool isBlancket(char c);
void handleBlanket(int position);
void handleNumAndAlphabet(int position);

void solution(int numOfOrder, string* orderArr) {
	// TODO: 이곳에 코드를 작성하세요. 추가로 필요한 함수와 전역변수를 선언해서 사용하셔도 됩니다.
	vector<string> answer;

	for (int count = 0; count < numOfOrder; count++) {
		stack<int> blanket_position;
		stack<int> num_and_alphabet_position;
		order = orderArr[count];

		for (int i = 0; i < orderArr[count].size(); i++) {
			if (orderArr[count][i] == '(')
				blanket_position.push(i);
		}

		int blanket_amount = blanket_position.size();
		for (int i = 0; i < blanket_amount; i++) {
			handleBlanket(blanket_position.top());
			blanket_position.pop();
		}

		for (int i = 1; i < orderArr[count].size(); i++) {
			if (isAlphabet(orderArr[count][i]) && isNum(orderArr[count][i-1]))
				num_and_alphabet_position.push(i);
		}

		int num_and_alphabet_amount = num_and_alphabet_position.size();
		for (int i = 0; i < num_and_alphabet_amount; i++) {
			handleNumAndAlphabet(num_and_alphabet_position.top());
			num_and_alphabet_position.pop();
		}
		answer.push_back(order);
	}

	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << endl;
	}
}

void handleNumAndAlphabet(int position) {
	string temp = "";
	int idx;

	for (int i = 0; i < position - 1; i++)
		temp += order[i];

	int repeat_num = (int)(order[position - 1] - '0');

	for (int i = 0; i < repeat_num; i++) {
		temp += order[position];
	}

	for (idx = position + 1; idx < order.size(); idx++)
		temp += order[idx];

	order = temp;
}

void handleBlanket(int position) {
	string temp = "";
	int idx;
	
	for (int i = 0; i < position - 1; i++)
		temp += order[i];

	if (isAlphabet(order[position - 1])) {
		for (idx = position + 1; order[idx] != ')'; idx++) {
			temp += order[position - 1];
			temp += order[idx];
		}
		idx++;
		for (; idx < order.size(); idx++)
			temp += order[idx];

		order = temp;
	}
	if (isNum(order[position - 1])) {
		string repeat = "";
		for (idx = position + 1; order[idx] != ')'; idx++) {
			repeat += order[idx];
		}
		for (char i = 0; i < order[position - 1] - '0'; i++) {
			temp += repeat;
		}
		idx++;
		for (; idx < order.size(); idx++)
			temp += order[idx];

		order = temp;
	}
}

bool isAlphabet(char c) {
	if (c == 'R' || c == 'G' || c == 'B')
		return true;
	return false;
}
bool isNum(char c) {
	if ('0' <= c && c <= '9')
		return true;
	return false;
}
bool isBlancket(char c) {
	if (c == '(' || c == ')')
		return true;
	return false;
}

struct input_data {
	int numOfOrder;
	string* orderArr;
};

void process_stdin(struct input_data& inputData) {
	string line;
	istringstream iss;

	getline(cin, line);
	iss.str(line);
	iss >> inputData.numOfOrder;

	inputData.orderArr = new string[inputData.numOfOrder];
	for (int i = 0; i < inputData.numOfOrder; i++) {
		getline(cin, line);
		iss.clear();
		iss.str(line);
		iss >> inputData.orderArr[i];
	}
}

int main() {
	struct input_data inputData;
	process_stdin(inputData);

	solution(inputData.numOfOrder, inputData.orderArr);
	return 0;
}