/*#include <string>
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
}*/

#include <string>
#include <vector>

#define INFINITE 0x0FFFFFFF

using namespace std;

int edges[201][201];

void clear();
void floydWashall();

int N, S, A, B;

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
	int answer = 0;

	N = n; S = s; A = a; B = b;

	clear();

	for (unsigned int i = 0; i < fares.size(); i++) {
		int start = fares[i][0];
		int destination = fares[i][1];
		int weight = fares[i][2];

		edges[start][destination] = edges[destination][start] = weight;
	}

	floydWashall();

	int noTaxiSharingCost = edges[S][A] + edges[S][B];
	int taxiSharingCost = INFINITE;

	for (int midPoint = 1; midPoint <= N; midPoint++) {
		int sharingCost = edges[S][midPoint] + edges[midPoint][A] + edges[midPoint][B];
		taxiSharingCost = taxiSharingCost < sharingCost ? taxiSharingCost : sharingCost;
	}

	answer = taxiSharingCost < noTaxiSharingCost ? taxiSharingCost : noTaxiSharingCost;

	return answer;
}

void floydWashall() {
	for (int midPoint = 1; midPoint <= N; midPoint++) {
		for (int start = 1; start <= N; start++) {
			for (int destination = 1; destination <= N; destination++) {
				int beforeDistance = edges[start][destination];
				int newDistance = edges[start][midPoint] + edges[midPoint][destination];

				if (newDistance < beforeDistance)
					edges[start][destination] = newDistance;
			}
		}
	}
}

void clear() {
	for (int y = 0; y < 201; y++) {
		for (int x = 0; x < 201; x++) {
			if (y == x) edges[y][x] = 0;
			else edges[y][x] = INFINITE;
		}
	}
}

int main() {
	solution(6, 4, 6, 2, { {4, 1, 10},{3, 5, 24},{5, 6, 2},{3, 1, 41},{5, 1, 24},{4, 6, 50},{2, 4, 66},{2, 3, 22},{1, 6, 25} });
}