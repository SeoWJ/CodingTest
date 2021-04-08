#include <iostream>
#include <queue>
#include <unordered_map>

#define endl '\n'

using namespace std;

class absHeap {
protected:
	int N;
	priority_queue<int, vector<int>, greater<int>> PQ;
	unordered_map<int, deque<int>> hashtable;

public:
	absHeap(){
		cin >> N;
	}
	int abs(int num) { return num > 0 ? num : num * -1; }
	void solution() {
		while (N--) {
			int query; cin >> query;

			if (query == 0) {
				if (PQ.empty()) cout << 0 << endl;
				else {
					int key = PQ.top();
					PQ.pop();

					cout << hashtable[key].front() << endl;
					hashtable[key].pop_front();
				}
			}
			else {
				int key = abs(query);

				PQ.push(key);
				
				if (query > 0)
					hashtable[key].push_back(query);
				else
					hashtable[key].push_front(query);
			}
		}
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	absHeap* a = new absHeap();
	a->solution();

	delete a;

	return 0;
}