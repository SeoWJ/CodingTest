#include <iostream>
#include <vector>

#define endl '\n'
#define START 0

using namespace std;

int N, M;
vector<vector<int>> answer;

void NM(vector<pair<int, bool>> original, int idx, vector<int> current);

int main(int argc, char* argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	vector<pair<int, bool>> original;

	for (int i = 1; i <= N; i++)
		original.push_back(make_pair(i, false));

	NM(original, START, {});

	for (unsigned int i = 0; i < answer.size(); i++) {
		for (unsigned int j = 0; j < answer[i].size(); j++) {
			cout << answer[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}

void NM(vector<pair<int, bool>> original, int idx, vector<int> current) {
	if (current.size() == M) {
		answer.push_back(current);
		return;
	}

	for (unsigned int i = idx; i < original.size(); i++) {
		if (original[i].second == false) {
			current.push_back(original[i].first);
			original[i].second = true;

			NM(original, i + 1, current);

			original[i].second = false;
			current.pop_back();
		}
	}
}