#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool compare(int i1, int i2) { return i1 > i2; }

int solution(vector<int> citations) {
	int answer = 0;

	sort(citations.begin(), citations.end(), compare);

	int limit = citations.size();
	for (int h_index = 0; h_index <= limit; h_index++) {
		if (citations.back() < h_index) {
			while (citations.back() < h_index) {
				citations.pop_back();
				
				if (citations.empty())
					return answer;
			}
		}
		if (h_index <= citations.size())
			answer = h_index;
	}

	return answer;
}

int main() {
	vector<int> citations;
	citations.push_back(0);
	citations.push_back(0);
	citations.push_back(0);
	citations.push_back(0);

	cout << solution(citations) << endl;
}