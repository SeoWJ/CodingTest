#include <iostream>
#include <vector>
#include <queue>

#define endl '\n'

using namespace std;

class Ladder {
protected:
	int N;
	int M;
	int H;
	vector<vector<int>> ladder;
	vector<int> horizontalLine;
	int answer;

public:
	Ladder(int n, int m, int h) {
		N = n; M = m; H = h;
		answer = 0x7FFFFFFF;

		vector<int> row(N + 2);
		horizontalLine.assign(N + 2, 0);
		ladder.assign(M + 2, row);

		int a, b;

		while (cin >> a >> b) {
			ladder[a][b] = 1;
			ladder[a][b + 1] = -1;
			horizontalLine[b]++;
			horizontalLine[b + 1]++;
		}
	}
	bool play(vector<vector<int>> ladder) {
		bool success = true;

		for (int i = 1; i <= N; i++) {
			int x = i;
			int y = 0;

			while (y <= M + 1) {
				if (ladder[y][x] == 1) {
					x++; y++;
				}
				else if (ladder[y][x] == -1) {
					x--; y++;
				}
				else
					y++;
			}

			if (x != i) return false;
		}
		return true;
	}
	void bruteForce(int add, vector<pair<int, int>> newLine, vector<int> horizontalLine, vector<vector<int>> ladder) {
		if (add <= 3) {
			if (play(ladder) == true)
				answer = add < answer ? add : answer;
		}
		else
			return;

		for (int x = (newLine.empty() ? 1 : newLine.back().first); x <= N - 1; x++) {
			if (horizontalLine[x] == H) continue;

			for (int y = (newLine.empty() ? 1 : newLine.back().second); y <= M; y++) {
				if (ladder[y][x] == 0 && ladder[y][x + 1] == 0) {
					add++;
					ladder[y][x] = 1;
					ladder[y][x + 1] = -1;
					horizontalLine[x]++;
					horizontalLine[x + 1]++;
					newLine.push_back({ x, y });

					bruteForce(add, newLine, horizontalLine, ladder);

					add--;
					ladder[y][x] = ladder[y][x + 1] = 0;
					horizontalLine[x]--;
					horizontalLine[x + 1]--;
					newLine.pop_back();
				}
			}
		}
	}
	void solution() {
		bruteForce(0, {}, this->horizontalLine, this->ladder);

		cout << (answer == 0x7FFFFFFF ? -1 : answer) << endl;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M, H; cin >> N >> M >> H;

	Ladder l(N, M, H);
	l.solution();

	return 0;
}