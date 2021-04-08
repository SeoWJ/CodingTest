#include <iostream>
#include <vector>
#include <cstring>

#define endl '\n'

using namespace std;

class ProblemSolve {
protected:
	int N;
	int selection[100001];
	bool chosen[100001];
public:
	ProblemSolve(int n) {
		N = n;

		memset(chosen, false, sizeof(chosen));

		for (int i = 1; i <= N; i++)
			cin >> selection[i];
	}
	void DFS(int current, int startPoint, vector<int> group, vector<bool>& visit) {
		if (current == startPoint) {
			for (auto i : group) chosen[i] = true;
			return;
		}
		else {
			if (visit[current] == true)
				return;
			else {
				group.push_back(current);
				visit[current] = true;
				DFS(selection[current], startPoint, group, visit);
			}
		}
	}
	void solution() {
		for (int i = 1; i <= N; i++) {
			if (chosen[i] == false) {
				vector<bool> visit(100001, false);
				
				visit[i] = true;
				DFS(selection[i], i, { i }, visit);
			}
		}

		int answer = 0;

		for (int i = 1; i <= N; i++) {
			if (chosen[i] == false) answer++;
		}

		cout << answer << endl;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T; cin >> T;

	while (T--) {
		int N; cin >> N;

		ProblemSolve* p = new ProblemSolve(N);
		p->solution();

		delete p;
	}

	return 0;
}