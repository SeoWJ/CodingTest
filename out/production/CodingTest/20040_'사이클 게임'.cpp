#include <iostream>
#include <vector>

#define endl '\n'

using namespace std;

class CycleGame {
protected:
	int N, M;
	int unionHead[500000];
	vector<pair<int, int>> gameLog;

public:
	CycleGame() {
		cin >> N >> M;

		for (int i = 0; i < 500000; i++) unionHead[i] = i;

		for (int i = 0; i < M; i++) {
			int p1, p2;
			cin >> p1 >> p2;

			gameLog.push_back({ p1, p2 });
		}
	}
	int getUnionHead(int node) {
		if (unionHead[node] == node) return unionHead[node];
		else return getUnionHead(unionHead[node]);
	}
	void setUnionHead(int node, int setValue) {
		int prevUnionHead = getUnionHead(node);
		unionHead[prevUnionHead] = setValue;
	}
	void solution() {
		int answer = 0;

		for (unsigned int i = 0; i < gameLog.size(); i++) {
			int node1 = gameLog[i].first;
			int node2 = gameLog[i].second;

			int unionHead1 = getUnionHead(node1);
			int unionHead2 = getUnionHead(node2);

			if (unionHead1 == unionHead2) {
				answer = i + 1;
				break;
			}
			else {
				if (unionHead1 < unionHead2)
					setUnionHead(unionHead2, unionHead1);
				else
					setUnionHead(unionHead1, unionHead2);
			}
		}

		cout << answer << endl;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	CycleGame* c = new CycleGame();
	c->solution();

	delete c;

	return 0;
}