#include <iostream>
#include <vector>
#include <string>

#define endl '\n'
#define HASH_MAX 9715467

using namespace std;

int N, M;

string pokemon[100001];
vector<pair<int, string>> hash_table[HASH_MAX];

int main(int argc, char* argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		string input; cin >> input;
		pokemon[i] = input;

		int hash_num = 1;
		for (unsigned int j = 0; j < input.size(); j++) {
			hash_num = (hash_num * input[j]) % HASH_MAX;
		}
		hash_table[hash_num].push_back({ i, input });
	}

	for (int i = 0; i < M; i++) {
		string input; cin >> input;
		if ('0' <= input[0] && input[0] <= '9') {
			cout << pokemon[stoi(input)] << endl;
		}
		else {
			int hash_num = 1;
			for (unsigned int j = 0; j < input.size(); j++)
				hash_num = (hash_num * input[j]) % HASH_MAX;
			for (unsigned int j = 0; j < hash_table[hash_num].size(); j++) {
				if (hash_table[hash_num][j].second == input) {
					cout << hash_table[hash_num][j].first << endl;
					break;
				}
			}
		}
	}

	return 0;
}