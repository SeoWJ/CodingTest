#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	int answer = 0;

	deque<int> dq_truck_weights;
	for (unsigned int i = 0; i < truck_weights.size(); i++)
		dq_truck_weights.push_back(truck_weights[i]);
	int current_weight = 0;
	int current_trucks = 0;
	deque<pair<int, int>> trucks_on_bridge;

	while (1) {
		if (!dq_truck_weights.empty() && current_weight + dq_truck_weights.front() <= weight && current_trucks + 1 <= bridge_length) {
			for (unsigned int i = 0; i < trucks_on_bridge.size(); i++)
				trucks_on_bridge[i].second++;

			trucks_on_bridge.push_back(make_pair(dq_truck_weights.front(), 1));
			current_weight += dq_truck_weights.front();
			current_trucks++;
			answer += 1;
			dq_truck_weights.pop_front();
		}
		else {
			answer += (bridge_length + 1 - trucks_on_bridge.front().second);

			for (int i = trucks_on_bridge.size() - 1; i >= 0; i--)
				trucks_on_bridge[i].second += (bridge_length + 1 - trucks_on_bridge.front().second);
			
			current_weight -= trucks_on_bridge.front().first;
			current_trucks--;
			trucks_on_bridge.pop_front();

			if (!dq_truck_weights.empty() && current_weight + dq_truck_weights.front() <= weight && current_trucks + 1 <= bridge_length) {
				trucks_on_bridge.push_back(make_pair(dq_truck_weights.front(), 1));
				current_weight += dq_truck_weights.front();
				current_trucks++;
				dq_truck_weights.pop_front();
			}
		}

		if (dq_truck_weights.empty() && trucks_on_bridge.empty())
			break;
	}

	return answer;
}