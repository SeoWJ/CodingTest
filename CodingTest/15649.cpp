#include <iostream>
#include <vector>
#include <algorithm>

#define endl '\n'

using namespace std;

int N, M;
vector<vector<int>> answer_list;

void N_and_M();
void bruteForce(vector<int> sequence, vector<pair<int, bool>> number_list);

int main(int argc, char* argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	N_and_M();

	return 0;
}

void N_and_M() {
	cin >> N >> M;
	vector<pair<int, bool>> number_list;

	for (int i = 1; i <= N; i++) {
		number_list.push_back(make_pair(i, true));
	}

	for (int i = 0; i < N; i++) {
		vector<int> sequence;
		
		number_list[i].second = false;
		sequence.push_back(number_list[i].first);
		
		bruteForce(sequence, number_list);

		number_list[i].second = true;
	}

	for (unsigned int i = 0; i < answer_list.size(); i++) {
		for (int j = 0; j < M; j++) {
			cout << answer_list[i][j] << " ";
		}
		cout << endl;
	}
}

void bruteForce(vector<int> sequence, vector<pair<int, bool>> number_list) {
	if (sequence.size() == M) {
		answer_list.push_back(sequence);
		return;
	}

	for (int i = 0; i < N; i++) {
		if (number_list[i].second == true) {
			number_list[i].second = false;

			sequence.push_back(number_list[i].first);

			bruteForce(sequence, number_list);

			number_list[i].second = true;
			sequence.pop_back();
		}
	}
}