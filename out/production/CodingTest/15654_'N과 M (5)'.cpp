#include <iostream>
#include <vector>
#include <algorithm>

#define endl '\n'
#define START 0

using namespace std;

int N, M;
vector<vector<int>> answer;

void NM(vector<pair<int, bool>> original, vector<int> current);

int main(int argc, char* argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	vector<pair<int, bool>> original;
	for (int i = 0; i < N; i++) {
		int input; cin >> input;
		original.push_back(make_pair(input, false));
	}

	NM(original, {});

	sort(answer.begin(), answer.end());

	for (unsigned int i = 0; i < answer.size(); i++) {
		for (unsigned int j = 0; j < answer[i].size(); j++) {
			cout << answer[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}

void NM(vector<pair<int, bool>> original, vector<int> current) {
	if (current.size() == M) {
		answer.push_back(current);
		return;
	}

	for (unsigned int i = 0; i < original.size(); i++) {
		if (original[i].second == false) {
			current.push_back(original[i].first);
			original[i].second = true;

			NM(original, current);

			original[i].second = false;
			current.pop_back();
		}
	}
}