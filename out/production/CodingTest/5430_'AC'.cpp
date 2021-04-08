#include <iostream>
#include <queue>

#define endl '\n'

using namespace std;

void solution();

int main(int argc, char* argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T; cin >> T;

	while (T--)
		solution();

	return 0;
}

void solution() {
	string p;
	int n;
	deque<int> x;
	bool direction = true; // true = 정방향, false = 역방향

	cin >> p;
	cin >> n;

	int num = -1;
	while (1) {
		char input; cin >> input;

		if (input == '[') continue;
		else if (input == ',') {
			x.push_back(num);
			num = 0;
		}
		else if (input == ']') {
			if (num == -1) break;

			x.push_back(num);
			break;
		}
		else {
			if (num == -1) num = 0;

			num *= 10;
			num += input - '0';
		}
	}

	for (unsigned int i = 0; i < p.size(); i++) {
		if (p[i] == 'R') {
			direction = !direction;
		}
		else if (p[i] == 'D') {
			if (x.size() > 0) {
				if (direction == true) {
					x.pop_front();
				}
				else if (direction == false) {
					x.pop_back();
				}
			}
			else {
				cout << "error" << endl;
				return;
			}
		}
	}

	if (x.size() > 0) {
		cout << '[';
		if (direction) {
			for (unsigned int i = 0; i < x.size(); i++) {
				if (i != x.size() - 1)
					cout << x[i] << ',';
				else
					cout << x[i] << ']' << endl;
			}
		}
		else {
			for (int i = x.size() - 1; i >= 0; i--) {
				if (i != 0)
					cout << x[i] << ',';
				else
					cout << x[i] << ']' << endl;
			}
		}
	}
	else cout << "[]" << endl;
}