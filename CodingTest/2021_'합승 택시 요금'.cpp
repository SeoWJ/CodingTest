#include <string>
#include <vector>
#include <queue>

#define INF 0x7FFFFFFF

using namespace std;

typedef pair<int, int> Edge;		// weight, destination;
typedef pair<int, int> Node;		// distance, startPoint;

int N;
int startVertex, destinationA, destinationB;
deque<Edge> edges[201];
int distanceArray[201];
int distanceArrayFromSpecificPoint[201];

void clearDistanceArray() { for (int i = 0; i < 201; i++) distanceArray[i] = INF; }
void clearDistanceArrayFromSpecificPoint(){ for (int i = 0; i < 201; i++) distanceArrayFromSpecificPoint[i] = INF; }
void dijkstra(int startVertex, int* distanceArray);

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
	int answer = 0;

	N = n;
	startVertex = s;
	destinationA = a;
	destinationB = b;

	for (unsigned int i = 0; i < fares.size(); i++) {
		int start = fares[i][0];
		int destination = fares[i][1];
		int weight = fares[i][2];

		edges[start].push_back({ weight, destination });
		edges[destination].push_back({ weight, start });
	}

	clearDistanceArray();

	dijkstra(startVertex, distanceArray);

	int notTaxiSharingCost = distanceArray[destinationA] + distanceArray[destinationB];
	int taxiSharingCost = INF;

	for (int i = 1; i <= N; i++) {
		clearDistanceArrayFromSpecificPoint();

		int midPointCost = distanceArray[i];
		
		dijkstra(i, distanceArrayFromSpecificPoint);

		int totalCost = midPointCost + distanceArrayFromSpecificPoint[destinationA] + distanceArrayFromSpecificPoint[destinationB];

		taxiSharingCost = taxiSharingCost < totalCost ? taxiSharingCost : totalCost;
	}

	answer = taxiSharingCost < notTaxiSharingCost ? taxiSharingCost : notTaxiSharingCost;

	return answer;
}

void dijkstra(int startVertex, int* distanceArray) {
	priority_queue<Node, vector<Node>, greater<Node>> PQ;

	distanceArray[startVertex] = 0;

	PQ.push({ 0, startVertex });

	while (!PQ.empty()) {
		int currentNode = PQ.top().second;
		
		PQ.pop();

		for (unsigned int i = 0; i < edges[currentNode].size(); i++) {
			int beforeDistance = distanceArray[edges[currentNode][i].second];
			int newDistance = distanceArray[currentNode] + edges[currentNode][i].first;

			if (newDistance < beforeDistance) {
				distanceArray[edges[currentNode][i].second] = newDistance;
				PQ.push({ newDistance, edges[currentNode][i].second });
			}
		}
	}
}