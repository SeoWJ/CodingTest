#include <iostream>
#include <vector>
#include <algorithm>

#define endl '\n'

using namespace std;

int N, M;
vector<vector<int>> answer;

void bruteForce(vector<pair<int, bool>> natural, vector<int> seq);

int main(int argc, char* argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	vector<pair<int, bool>> natural;

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		int input; cin >> input;
		natural.push_back({ input, false });
	}

	sort(natural.begin(), natural.end());

	bruteForce(natural, {});

	sort(answer.begin(), answer.end());

	for (unsigned int i = 0; i < answer[0].size(); i++)
		cout << answer[0][i] << " ";
	cout << endl;

	for (unsigned int i = 1; i < answer.size(); i++) {
		if (answer[i] == answer[i - 1])
			continue;
		else {
			for (auto e : answer[i])
				cout << e << " ";
			cout << endl;
		}
	}
}

void bruteForce(vector<pair<int, bool>> natural, vector<int> seq) {
	if (seq.size() == M) {
		answer.push_back(seq);
		return;
	}

	for (unsigned int i = 0; i < natural.size(); i++) {
		if (natural[i].second == false) {
			natural[i].second = true;
			seq.push_back(natural[i].first);

			bruteForce(natural, seq);

			seq.pop_back();
			natural[i].second = false;
		}
	}
}