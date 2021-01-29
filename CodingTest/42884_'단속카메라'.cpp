#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> routes) {
	//int answer = 0;
	deque<vector<int>> answer;

	sort(routes.begin(), routes.end());

	for (unsigned int i = 0; i < routes.size(); i++) {
		if (answer.size() == 0) { 
			answer.push_back(routes[0]);
			continue;
		}
		
		int commonStart = answer[answer.size() - 1][0];
		int commonEnd = answer[answer.size() - 1][1];
		int routeStart = routes[i][0];
		int routeEnd = routes[i][1];

		if (commonStart <= routeStart && routeEnd <= commonEnd) {
			answer[answer.size() - 1][0] = routeStart;
			answer[answer.size() - 1][1] = routeEnd;
		}
		else if (routeStart < commonStart && commonStart <= routeEnd && routeEnd <= commonEnd) {
			answer[answer.size() - 1][1] = routeEnd;
		}
		else if (commonStart <= routeStart && routeStart <= commonEnd && commonEnd < routeEnd) {
			answer[answer.size() - 1][0] = routeStart;
		}
		else {
			answer.push_back(routes[i]);
		}
	}

	return answer.size();
}

int main() {
	cout << solution({ {-20, 15}, {-14, -5},{-18,-13}, {-5, -3} }) << endl;
}