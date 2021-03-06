#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_map>

using namespace std;

typedef pair<int, pair<int, int>> Edge;

int solution(int distance, vector<int> rocks, int n) {
	int answer = 0;

	if (rocks.size() == n) return distance;

	sort(rocks.begin(), rocks.end());

	priority_queue<Edge, vector<Edge>, greater<Edge>> PQ;
	unordered_map<int, bool> UM;
	UM[0] = UM[distance] = true;

	for (int i = 0; i < rocks.size(); i++) {
		UM[rocks[i]] = true;
		PQ.push({ rocks[i], {0, rocks[i]} });

		for (int j = 0; j < i; j++)
			PQ.push({ rocks[i] - rocks[j], {rocks[j], rocks[i]} });

		PQ.push({ distance - rocks[i], {rocks[i], distance} });
	}

	int removeRockCount = 0;
	while (removeRockCount < n) {
		int start = PQ.top().second.first;
		int destination = PQ.top().second.second;
		int weight = PQ.top().first;

		PQ.pop();

		if (UM[start] == false || UM[destination] == false) continue;
		else {
			UM[destination] = false;
			removeRockCount++;
		}
	}

	vector<int> newRocks;
	for (unsigned int i = 0; i < rocks.size(); i++) {
		if (UM[rocks[i]] == true) newRocks.push_back(rocks[i]);
	}

	vector<int> newDistances;
	for (unsigned int i = 0; i < newRocks.size(); i++) {
		if (i == 0) newDistances.push_back(newRocks[i]);
		else newDistances.push_back(newRocks[i] - newRocks[i - 1]);
	}
	newDistances.push_back(distance - newRocks[newRocks.size() - 1]);

	sort(newDistances.begin(), newDistances.end());

	answer = newDistances[0];

	return answer;
}