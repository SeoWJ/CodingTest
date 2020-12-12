#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

bool prime[10000000] = { true };
bool visit[10000000] = { false };
int answer = 0;

void eratostenes();
void bruteForce(vector<string> num, string start_num);
int stringToInt(string number);

int solution(string numbers) {
	eratostenes();
	
	vector<string> num;
	num.assign(7, "X");

	for (unsigned int x = 0; x < numbers.size(); x++) {
		num[x] = numbers[x];
	}

	for (unsigned int x = 0; x < numbers.size(); x++) {
		if (num[x] != "X") {
			string start_num = "";

			start_num += num[x];
			string temp = num[x];
			num[x] = "X";

			bruteForce(num, start_num);

			num[x] = temp;
		}
	}

	return answer;
}

void bruteForce(vector<string> num, string _start_num) {
	int number = stringToInt(_start_num);
	if (prime[number] == true && visit[number] == false) {
		answer++;
		visit[number] = true;
	}

	bool finish = true;
	for (unsigned int x = 0; x < 7; x++) {
		if (num[x] != "X") {
			finish = false;
			break;
		}
	}
	if (finish == true) return;

	for (unsigned int x = 0; x < 7; x++) {
		string start_num = _start_num;
		if (num[x] != "X") {
			start_num += num[x];
			string temp = num[x];
			num[x] = "X";

			bruteForce(num, start_num);

			num[x] = temp;
		}
	}
}

int stringToInt(string number) {
	int index = 0;
	int result = 0;
	for (int x = number.size() - 1; x >= 0; x--) {
		result += (number[x] - '0') * pow(10, index);
		index++;
	}

	return result;
}

void eratostenes() {
	for (int x = 2; x < 10000000; x++) prime[x] = true;
	prime[0] = prime[1] = false;

	for (int x = 2; x <= sqrt(10000000); x++) {
		if (prime[x] == true) {
			for (int y = x + x; y < 10000000; y += x) {
				prime[y] = false;
			}
		}
	}
}

int main() {
	cout << solution("9999999") << endl;

	return 0;
}