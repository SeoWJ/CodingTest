#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
	int answer = 0;

	queue<int> printer;
	priority_queue<int, vector<int>, less<int>> PQ;

	for (unsigned int i = 0; i < priorities.size(); i++) {
		printer.push(priorities[i]);
		PQ.push(priorities[i]);
	}

	while (1) {
		int currentPriority = printer.front();
		printer.pop();

		if (location == 0) {
			if (currentPriority == PQ.top()) {
				answer++;
				break;
			}
			else {
				printer.push(currentPriority);
				location = printer.size() - 1;
			}
		}
		else {
			if (currentPriority == PQ.top()) {
				answer++;
				PQ.pop();
			}
			else
				printer.push(currentPriority);

			location--;
		}
	}

	return answer;
}

int main() {
	solution({ 2,1,3,2 }, 2);
}