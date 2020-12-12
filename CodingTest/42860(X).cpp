#include <iostream>
#include <string>
#include <vector>

#define left -1
#define right 1

using namespace std;

int solution(string name);

int main(int argc, char* argv[]) {
	string name;
	cin >> name;

	cout << solution(name) << endl;
}

int solution(string name) {
	int answer = 0;
	int alphabet[26] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,12,11,10,9,8,7,6,5,4,3,2,1 };

	int direction;
	int left_fd = name.size() - 1, right_fd = 1, final_destination;
	bool allA = true;

	for (int x = 0; x < name.size(); x++) {
		if (name[x] != 'A')
			allA = false;
	}
	if (allA == true) return 0;
	
	for (int x = 1; x < name.size(); x++) {
		if (name[x] != 'A')
			right_fd = x;
	}

	for (int x = name.size() - 1; x >= 1; x--) {
		if (name[x] != 'A')
			left_fd = x;
	}

	if (name.size() - 1 - right_fd >= left_fd - 1) {
		direction = right;
		final_destination = right_fd;
	}
	else {
		direction = left;
		final_destination = left_fd;
	}

	if (direction == right) {
		for (int x = 0; x <= final_destination; x++) {
			if (x == 0)
				answer += alphabet[name[x] - 'A'];
			else
				answer += 1 + alphabet[name[x] - 'A'];
		}
	}
	else {
		for (int x = name.size() - 1; x >= final_destination; x--) {
			answer += 1 + alphabet[name[x] - 'A'];
		}
		answer += alphabet[name[0] - 'A'];
	}

	return answer;
}