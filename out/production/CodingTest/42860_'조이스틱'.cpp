#include <string>
#include <vector>
#include <iostream>

#define LEFT -1
#define RIGHT 1

using namespace std;

int solution(string name) {
	int answer = 0;
	int direction = 0;
	int alphabet[26] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,12,11,10,9,8,7,6,5,4,3,2,1 };

	if (name.size() == 1) return alphabet[name[0] - 'A'];
	bool allA = true;
	for (int i = 0; i < name.size(); i++) {
		if (name[i] != 'A') allA = false;
	}
	if (allA) return 0;

	int left = 1, right = name.size() - 1;
	while (left < name.size() && right > 0) {
		if (name[right] == 'A') {
			direction = RIGHT;
			break;
		}
		if (name[left] == 'A') {
			direction = LEFT;
			break;
		}
		left++;
		right--;
	}
	if (direction == 0) direction = RIGHT;

	answer += alphabet[name[0] - 'A'];

	int finishPoint;
	if (direction == RIGHT) {
		finishPoint = name.size() - 1;
		if (name[finishPoint] == 'A')
			while (name[finishPoint] == 'A') finishPoint--;

		for (int i = 1; i <= finishPoint; i++) {
			answer++;
			answer += alphabet[name[i] - 'A'];
		}
	}
	else if (direction == LEFT) {
		finishPoint = 1;
		if (name[finishPoint] == 'A')
			while (name[finishPoint] == 'A') finishPoint++;

		for (int i = name.size() - 1; i >= finishPoint; i--) {
			answer++;
			answer += alphabet[name[i] - 'A'];
		}
	}

	return answer;
}

int main() { cout << solution("JAA"); }