#include <iostream>
#include <vector>

#define endl '\n'

using namespace std;

void pairing();
void bruteForce(int _student[][2], int _answer[][3]);

int main(int argc, char* argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	pairing();

	return 0;
}

void pairing() {
	int man; cin >> man;

	int student[3][2];
	int answer[3][3];
	int index = 0;

	for (int x = 0; x < 3; x++) {
		int male, female; cin >> male >> female;
		student[x][0] = male;
		student[x][1] = female;
		answer[x][0] = answer[x][1] = answer[x][2] = -1;
	}

	if (student[0][0] > student[1][1]+ student[2][1]|| student[1][0] > student[0][1] + student[2][1] || student[2][0] > student[0][1] + student[1][1]) {
		cout << 0 << endl;
		return;
	}

	bruteForce(student, answer);
}

void bruteForce(int _student[][2], int _answer[][3]) {
	bool finished = true;
	bool possible = false;
	for (int y = 0; y < 3; y++) {
		for (int x = 0; x < 3; x++) {
			if (y == x) continue;
			else {
				if (_answer[y][x] == -1) {
					finished = false;
					break;
				}
			}
		}
		if (finished == false) break;
	}

	if (finished == true) {
		possible = true;
		for (int y = 0; y < 3; y++) {
			for (int x = 0; x < 2; x++) {
				if (_student[y][x] != 0) {
					possible = false;
					break;
				}
			}
			if (possible == false) break;
		}
	}

	if (possible == true) {
		cout << 1 << endl;
		for (int y = 0; y < 3; y++) {
			for (int x = 0; x < 3; x++) {
				if (y == x) continue;
				else {
					cout << _answer[y][x] << " ";
				}
			}
			cout << endl;
		}

		exit(0);
	}

	for (int y = 0; y < 3; y++) {
		for (int x = 0; x < 3; x++) {
			if (_answer[y][x] == -1 && y != x) {
				int temp1, temp2;

				if (_student[y][0] > _student[x][1]) {
					temp1 = _student[x][1];
					temp2 = _student[y][0];
					_answer[y][x] = _student[x][1];
					_student[y][0] -= _student[x][1];
					_student[x][1] = 0;
					bruteForce(_student, _answer);
				}
				else {
					temp1 = _student[x][1];
					temp2 = _student[y][0];
					_answer[y][x] = _student[y][0];
					_student[x][1] -= _student[y][0];
					_student[y][0] = 0;
					bruteForce(_student, _answer);
				}

				_student[x][1] = temp1; _student[y][0] = temp2; _answer[y][x] = -1;
			}
		}
	}
}