#include <string>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> Number;

vector<int> solution(vector<string> operations) {
	vector<int> answer;

	priority_queue<Number, vector<Number>, greater<Number>> minHeap;
	priority_queue<Number, vector<Number>, less<Number>> maxHeap;
	bool visit[1000001] = { false };

	for (unsigned int i = 0; i < operations.size(); i++) {
		char command = operations[i][0];
		int number = 0;

		for (unsigned int j = 2; j < operations[i].size(); j++) {
			if (j == 2 && operations[i][2] == '-') continue;

			number *= 10;
			number += operations[i][j] - '0';
		}
		if (operations[i][2] == '-') number *= -1;

		if (command == 'I') {
			minHeap.push({ number, i });
			maxHeap.push({ number, i });
			visit[i] = true;
		}
		else {
			if (number == -1) {
				if (minHeap.empty()) continue;

				int idx = minHeap.top().second;
				minHeap.pop();

				visit[idx] = false;

				while (1) {
					if (!minHeap.empty() && visit[minHeap.top().second] == false)
						minHeap.pop();
					else
						break;
				}
				while (1) {
					if (!maxHeap.empty() && visit[maxHeap.top().second] == false)
						maxHeap.pop();
					else
						break;
				}
			}
			else {
				if (maxHeap.empty()) continue;

				int idx = maxHeap.top().second;
				maxHeap.pop();

				visit[idx] = false;

				while (1) {
					if (!maxHeap.empty() && visit[maxHeap.top().second] == false)
						maxHeap.pop();
					else
						break;
				}
				while (1) {
					if (!minHeap.empty() && visit[minHeap.top().second] == false)
						minHeap.pop();
					else
						break;
				}
			}
		}
	}

	while (1) {
		if (!minHeap.empty() && visit[minHeap.top().second] == false)
			minHeap.pop();
		else
			break;
	}
	while (1) {
		if (!maxHeap.empty() && visit[maxHeap.top().second] == false)
			maxHeap.pop();
		else
			break;
	}

	if (minHeap.empty() && maxHeap.empty())
		return { 0, 0 };
	else
		return { maxHeap.top().first, minHeap.top().first };
}

int main() {
	solution({ "I 16", "I -5643", "D -1", "D 1", "D 1", "I 123", "D -1" });
}