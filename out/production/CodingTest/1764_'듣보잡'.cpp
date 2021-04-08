#include <iostream>
#include <vector>
#include <algorithm>

#define endl '\n'
#define HASH_MAX 9715467

using namespace std;

int N, M;

vector<string> N_hash[HASH_MAX];
vector<string> answer;

int main(int argc, char* argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		string input; cin >> input;
		int idx = 1;
		
		for (unsigned int j = 0; j < input.size(); j++)
			idx = (idx * input[j]) % HASH_MAX;

		N_hash[idx].push_back(input);
	}

	for (int i = 0; i < M; i++) {
		string input; cin >> input;
		int idx = 1;

		for (unsigned int j = 0; j < input.size(); j++)
			idx = (idx * input[j]) % HASH_MAX;

		for (unsigned int j = 0; j < N_hash[idx].size(); j++) {
			if (input == N_hash[idx][j]) {
				answer.push_back(input);
				break;
			}
		}
	}

	sort(answer.begin(), answer.end());

	cout << answer.size() << endl;
	for (unsigned int i = 0; i < answer.size(); i++) {
		cout << answer[i] << endl;
	}

	return 0;
}