#include <iostream>
#include <vector>

#define endl '\n'

using namespace std;

int N, M;
vector<vector<int>> answer;

void bruteForce(vector<int> seq, int loopStart);

int main(int argc, char* argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	bruteForce({}, 1);

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

	for (int i = loopStart; i <= N; i++) {
		seq.push_back(i);
		bruteForce(seq, i);
		seq.pop_back();
	}
}