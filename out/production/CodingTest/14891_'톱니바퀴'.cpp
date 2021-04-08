#include <iostream>
#include <queue>
#include <cstring>

#define endl '\n'

#define N false
#define S true

#define clockWise 1
#define reverseClockWise -1

using namespace std;

deque<deque<bool>> wheel;

void spin(int wheelNumber, int direction);
void rotateClockWise(int n);
void rotateReverseClockWise(int n);
int needSpin[4];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i=0; i<4; i++){
		string input; cin >> input;

		deque<bool> w;

		for (int x = 0; x < 8; x++) {
			if (input[x] == '1')
				w.push_back(S);
			else
				w.push_back(N);
		}

		wheel.push_back(w);
	}

	int K; cin >> K;

	while (K--) {
		memset(needSpin, 0, sizeof(needSpin));

		int wheelNumber, direction;
		cin >> wheelNumber >> direction;

		spin(wheelNumber - 1, direction);

		for (int i = 0; i < 4; i++) {
			if (needSpin[i] == clockWise)
				rotateClockWise(i);
			else if (needSpin[i] == reverseClockWise)
				rotateReverseClockWise(i);
			else
				continue;
		}
	}

	int answer = 0;

	if (wheel[0][0]) answer += 1;
	if (wheel[1][0]) answer += 2;
	if (wheel[2][0]) answer += 4;
	if (wheel[3][0]) answer += 8;

	cout << answer << endl;

	return 0;
}

void spin(int wheelNumber, int direction) {
	needSpin[wheelNumber] = direction;

	int toLeft = wheelNumber - 1;
	int toRight = wheelNumber + 1;

	while (toLeft >= 0) {
		if (wheel[toLeft][2] != wheel[toLeft + 1][6]) {
			needSpin[toLeft] = needSpin[toLeft + 1] * (-1);
			toLeft--;
		}
		else
			break;
	}

	while (toRight < 4) {
		if (wheel[toRight][6] != wheel[toRight - 1][2]) {
			needSpin[toRight] = needSpin[toRight - 1] * (-1);
			toRight++;
		}
		else 
			break;
	}
}

void rotateClockWise(int n) {
	wheel[n].push_front(wheel[n][wheel[n].size() - 1]);
	wheel[n].pop_back();
}

void rotateReverseClockWise(int n) {
	wheel[n].push_back(wheel[n][0]);
	wheel[n].pop_front();
}