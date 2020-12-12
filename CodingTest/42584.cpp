#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> prices) {
	vector<int> answer;

	answer.assign(prices.size(), 0);
	answer[prices.size() - 1] = 0;

	queue<int>* q = NULL;

	for (unsigned int x = 0; x < prices.size(); x++) {
		if (x == 0) {
			queue<int>* temp = new queue<int>;
			temp->push(0);
			q = temp;
			continue;
		}

		queue<int>* temp = new queue<int>;
		while (!q->empty()) {
			if (prices[x] >= prices[q->front()]) {
				temp->push(q->front());
			}
			answer[q->front()]++;
			q->pop();
		}
		temp->push(x);
		delete q;
		q = temp;
	}

	return answer;
}

int main() {
	vector<int> prices;
	prices.push_back(1);
	prices.push_back(2);
	prices.push_back(3);
	prices.push_back(2);
	prices.push_back(3);

	prices = solution(prices);

	for (unsigned int x = 0; x < prices.size(); x++) {
		cout << prices[x] << endl;
	}
}
