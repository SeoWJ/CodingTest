#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

struct Truck {
	int weight;
	int position;

	Truck(int w, int p) { weight = w; position = p; }
};

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	int answer = 0;
	
	queue<int> truckWeights;
	deque<Truck> crossingTruck;
	int crossingTruckWeights = 0;

	for (unsigned int i = 0; i < truck_weights.size(); i++) truckWeights.push(truck_weights[i]);
	
	while (!truckWeights.empty() || !crossingTruck.empty()) {
		if (!truckWeights.empty() && crossingTruck.size() + 1 <= bridge_length && crossingTruckWeights + truckWeights.front() <= weight) {
			for (unsigned int i = 0; i < crossingTruck.size(); i++)
				crossingTruck[i].position++;

			crossingTruck.push_back(Truck(truckWeights.front(), 1));
			crossingTruckWeights += truckWeights.front();
			truckWeights.pop();
			answer++;
		}
		else {
			int timeFlow = (bridge_length - crossingTruck.front().position) + 1;
			
			answer += timeFlow;

			for (unsigned int i = 0; i < crossingTruck.size(); i++)
				crossingTruck[i].position += timeFlow;

			crossingTruckWeights -= crossingTruck.front().weight;
			crossingTruck.pop_front();

			if (!truckWeights.empty() && crossingTruck.size() + 1 <= bridge_length && crossingTruckWeights + truckWeights.front() <= weight) {
				crossingTruck.push_back(Truck(truckWeights.front(), 1));
				crossingTruckWeights += truckWeights.front();
				truckWeights.pop();
			}
		}
	}

	return answer;
}

int main() {
	cout << solution(4, 10, { 1,2,3,10 }) << endl;
}