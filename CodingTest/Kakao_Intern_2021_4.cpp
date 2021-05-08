#include <string>
#include <vector>
#include <queue>
#include <cstring>
#include <tuple>

using namespace std;

typedef tuple<int, int, vector<vector<int>>*> qNode;

int solution(int n, int start, int end, vector<vector<int>> roads, vector<int> traps) {
	int answer = 0;
	bool isTrap[3001] = { false };
	for (unsigned int i = 0; i < traps.size(); i++) isTrap[traps[i]] = true;

	queue<qNode> Q;

	vector<vector<int>>* v = new vector<vector<int>>();
	*v = roads;
	Q.push({ 0, 0, v });

	while (!Q.empty()) {
		int currentNode = get<0>(Q.front());
		int currentDistance = get<1>(Q.front());
		vector<vector<int>>* currentEdges = get<2>(Q.front());

		for(int nextNode = )
	}
	

	return answer;
}