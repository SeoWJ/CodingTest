#include <iostream>
#include <queue>
#include <vector>

#define endl '\n'

using namespace std;

void printerQueue();

int main(int argc, char* argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T; cin >> T;

	while (T--)
		printerQueue();

	return 0;
}

void printerQueue() {
	int N, M; cin >> N >> M;
	vector<int> result;
	deque<pair<int, int>> printer;

	for (int x = 0; x < N; x++) {
		int priority; cin >> priority;
		printer.push_back(make_pair(x, priority));
	}

	while (!printer.empty()) {
		bool can_print = true;
		for (int x = 0; x < printer.size(); x++) {
			if (printer[0].second < printer[x].second) {
				can_print = false;
				break;
			}
		}

		if (can_print == false) {
			pair<int, int> temp = printer.front();
			printer.pop_front();
			printer.push_back(temp);
		}
		else {
			result.push_back(printer.front().first);
			printer.pop_front();
		}
	}

	for (int x = 0; x < result.size(); x++) {
		if (result[x] == M)
			cout << x + 1 << endl;
	}
}