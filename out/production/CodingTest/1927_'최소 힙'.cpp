#include <iostream>
#include <queue>

#define endl '\n'

using namespace std;

int N;

int main(int argc, char* argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	priority_queue<int, vector<int>, greater<int>> PQ;

	cin >> N;

	while (N--) {
		int x; cin >> x;

		if (x > 0) {
			PQ.push(x);
		}
		else {
			if (PQ.empty())
				cout << 0 << endl;
			else {
				cout << PQ.top() << endl;
				PQ.pop();
			}
		}
	}

	return 0;
}