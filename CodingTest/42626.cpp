#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
	int answer = 0;

	priority_queue<int, vector<int>, greater<int>> min_heap;

	for (unsigned int x = 0; x < scoville.size(); x++) {
		min_heap.push(scoville[x]);
	}

	while (min_heap.top() < K) {
		int temp1, temp2;
		if (!min_heap.empty()) {
			temp1 = min_heap.top(); min_heap.pop();
		}
		else return -1;
		if (!min_heap.empty()) {
			temp2 = min_heap.top(); min_heap.pop();
		}
		else return -1;

		int mixed_food = temp1 + (temp2 * 2);
		
		min_heap.push(mixed_food);
		answer++;
	}

	return answer;
}