#include <iostream>
#include <cstring>

#define endl '\n'

using namespace std;

class Table {
protected:
	int N, K;
	string sequence;
	bool visit[20001];

public:
	Table(int n, int k, string seq) { N = n; K = k; sequence = seq; memset(visit, false, sizeof(visit)); }
	void solution() {
		int answer = 0;

		for (int i = 0; i < sequence.size(); i++) {
			if (sequence[i] == 'P') {
				int idx = ((i - K) >= 0 ? (i - K) : 0);
				int limit = ((i + K) < sequence.size() - 1 ? (i + K) : sequence.size() - 1);

				for (; idx <= limit; idx++) {
					if (sequence[idx] == 'H' && visit[idx] == false) {
						visit[idx] = true;
						answer++;
						break;
					}
				}
			}
		}

		cout << answer << endl;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, K; string seq;
	cin >> N >> K >> seq;

	Table* t = new Table(N, K, seq);
	t->solution();

	return 0;
}