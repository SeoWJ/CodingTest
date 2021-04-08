#include <iostream>
#include <vector>
#include <algorithm>

#define endl '\n'

using namespace std;

int N, M;
vector<int> natural;
vector<vector<int>> answer;

void bruteForce(vector<int> seq, int loopStart);

int main(int argc, char* argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		int input; cin >> input;
		natural.push_back(input);
	}

	sort(natural.begin(), natural.end());

	bruteForce({}, 0);

	for (auto v : answer) {
		for (auto e : v)
			cout << e << " ";
		cout << endl;
	}

	return 0;
}

void bruteForce(vector<int> seq, int loopStart) {
	if (seq.size() == M) {
		answer.push_back(seq);
		return;
	}

	for (unsigned int i = loopStart; i < natural.size(); i++) {
		seq.push_back(natural[i]);
		bruteForce(seq, i);
		seq.pop_back();
	}
}