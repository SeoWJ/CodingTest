#include <iostream>
#include <vector>

#define endl '\n'

using namespace std;

int M;

vector<int> S;

void add(int x) {
	bool exist = false;
	for (vector<int>::iterator iter = S.begin(); iter != S.end(); iter++) {
		if (*iter == x) {
			exist = true;
			break;
		}
	}
	if (!exist) S.push_back(x);
}

void remove(int x) {
	bool exist = false;
	for (vector<int>::iterator iter = S.begin(); iter != S.end(); iter++) {
		if (*iter == x) {
			S.erase(iter);
			break;
		}
	}
}

int check(int x) {
	bool exist = false;
	for (vector<int>::iterator iter = S.begin(); iter != S.end(); iter++) {
		if (*iter == x) {
			exist = true;
			break;
		}
	}
	if (exist) return 1;
	else return 0;
}

int main(int argc, char* argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> M;

	while (M--) {
		string operation;
		int x;

		cin >> operation;

		if (operation == "add") {
			cin >> x;
			add(x);
		}
		else if (operation == "remove") {
			cin >> x; 
			remove(x);
		}
		else if (operation == "check") {
			cin >> x;
			cout << check(x) << endl;
		}
		else if (operation == "toggle") {
			cin >> x;
			int t = check(x);
			if (t) remove(x);
			else add(x);
		}
		else if (operation == "all") {
			S.clear();
			for (int i = 1; i < 21; i++) S.push_back(i);
		}
		else if (operation == "empty")
			S.clear();
	}

	return 0;
}