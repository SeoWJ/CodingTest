#include <iostream>
#include <unordered_map>

#define endl '\n'

using namespace std;

void solution();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T; cin >> T;

	while (T--)
		solution();

	return 0;
}

void solution() {
	int N; cin >> N;

	unordered_map<string, int> clothes;

	for (int i = 0; i < N; i++) {
		string item, category;
		cin >> item >> category;

		clothes[category]++;
	}

	int answer = 1;

	for (unordered_map<string, int>::iterator iter = clothes.begin(); iter != clothes.end(); iter++) {
		answer *= (iter->second) + 1;
	}

	cout << --answer << endl;
}