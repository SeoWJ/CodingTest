#include <iostream>
#include <queue>

#define endl '\n'

using namespace std;

int N;
int* input[1000000] = { NULL };

int main(int argc, char* argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;

	priority_queue<pair<int, int*>, vector<pair<int, int*>>, greater<pair<int, int*>>> PQ;

	for (int i = 0; i < N; i++) {
		input[i] = new int;
		cin >> *input[i];
		PQ.push({ *input[i], input[i] });
	}

	int rank = 0;
	pair<int, int*> prev = { 0x7FFFFFFF, NULL };

	while (!PQ.empty()) {
		pair<int, int*> current = PQ.top();
		PQ.pop();

		if (current.first == prev.first) {
			*current.second = *prev.second;
		}
		else {
			*current.second = rank;
			rank++;
		}

		prev = current;		
	}

	for (int i = 0; i < N; i++) {
		cout << *input[i] << " ";
	}
	cout << endl;

	return 0;
}