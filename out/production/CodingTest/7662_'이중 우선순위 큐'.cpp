#include <iostream>
#include <queue>

#define endl '\n'

using namespace std;

typedef pair<int, int> pii;

int T;

void solution();

int main(int argc, char* argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> T;

	while (T--)
		solution();

	return 0;
}

void solution() {
	int K; cin >> K;

	priority_queue<pii, vector<pii>, greater<pii>> min_heap;
	priority_queue<pii, vector<pii>, less<pii>> max_heap;
	bool visit[1000000];

	for (int i = 0; i < 1000000; i++)
		visit[i] = true;

	for (int i = 0; i < K; i++) {
		char operation;
		int n;

		cin >> operation >> n;

		if (operation == 'I') {
			min_heap.push({ n, i });
			max_heap.push({ n, i });
		}
		else if (operation == 'D') {
			if (n == -1) {
				while (!min_heap.empty() && visit[min_heap.top().second] == false)
					min_heap.pop();
				if (!min_heap.empty()) {
					visit[min_heap.top().second] = false;
					min_heap.pop();
				}
			}
			else if (n == 1) {
				while (!max_heap.empty() && visit[max_heap.top().second] == false)
					max_heap.pop();
				if (!max_heap.empty()) {
					visit[max_heap.top().second] = false;
					max_heap.pop();
				}
			}
		}
	}

	while (!min_heap.empty() && visit[min_heap.top().second] == false)
		min_heap.pop();
	while (!max_heap.empty() && visit[max_heap.top().second] == false)
		max_heap.pop();

	if (min_heap.empty())
		cout << "EMPTY" << endl;
	else
		cout << max_heap.top().first << " " << min_heap.top().first << endl;
}