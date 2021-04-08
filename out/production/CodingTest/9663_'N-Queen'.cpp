#include <iostream>
#include <vector>
#include <queue>

#define endl '\n'

using namespace std;

int N;
int dx[3] = { -1, 0, 1 };
int answer = 0;

void solution();
void bruteForce(int y, vector<int> QueenPosition);

int main(int argc, char* argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> N;
	solution();

	cout << answer << endl;

	return 0;
}

void solution() {
	for (int i = 0; i < N; i++) {
		bruteForce(1, { i });
	}
}

void bruteForce(int y, vector<int> QueenPosition) {
	if (QueenPosition.size() == N) {
		answer++;
		return;
	}

	for (int x = 0; x < N; x++) {
		bool CanPutQueen = true;

		for (int i = 0; i < 3; i++) {
			int cy = y - 1;
			int cx = x + dx[i];

			while (0 <= cy && 0 <= cx && CanPutQueen) {
				if (QueenPosition[cy] == cx)
					CanPutQueen = false;
				cy--;
				cx += dx[i];
			}
		}

		if (CanPutQueen) {
			QueenPosition.push_back(x);
			bruteForce(y + 1, QueenPosition);
			QueenPosition.pop_back();
		}
	}
}