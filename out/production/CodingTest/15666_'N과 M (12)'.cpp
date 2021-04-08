#include <iostream>
#include <vector>
#include <algorithm>

#define endl '\n'

using namespace std;

class Sequence {
protected:
	int N, M;
	vector<int> numbers;
	vector<vector<int>> answer;

public:
	Sequence(int n, int m) {
		N = n; M = m;

		for (int i = 0; i < N; i++) {
			int input; cin >> input;
			numbers.push_back(input);
		}
	}
	void bruteForce(vector<int> seq) {
		if (seq.size() == M) {
			answer.push_back(seq);
			return;
		}

		for (unsigned int i = 0; i < numbers.size(); i++) {
			int maximum = seq.back();

			if (numbers[i] >= maximum) {
				seq.push_back(numbers[i]);
				
				bruteForce(seq);

				seq.pop_back();
			}
		}
	}
	void solution() {
		for (unsigned int i = 0; i < numbers.size(); i++) {
			vector<int> seq;
			seq.push_back(numbers[i]);

			bruteForce(seq);
		}

		sort(answer.begin(), answer.end());

		for (auto i : answer[0]) cout << i << ' ';
		cout << endl;

		for (unsigned int i = 1; i < answer.size(); i++) {
			if (answer[i] == answer[i - 1]) continue;
			else {
				for (auto e : answer[i]) cout << e << ' ';
				cout << endl;
			}
		}
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M; cin >> N >> M;

	Sequence* s = new Sequence(N, M);
	s->solution();

	delete s;

	return 0;
}