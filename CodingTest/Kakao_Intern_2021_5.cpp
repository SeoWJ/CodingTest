#include <string>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> Root;

int countPeople(vector<int>& num, vector<vector<int>>& links, int root) {
	if (root == -1)
		return 0;

	if (links[root][0] == -1 && links[root][1] == -1)
		return num[root];
	else {
		int leftSum = links[root][0] != -1 ? countPeople(num, links, links[root][0]) : 0;
		int rightSum = links[root][1] != -1 ? countPeople(num, links, links[root][1]) : 0;

		return num[root] + leftSum + rightSum;
	}
}

int findRoot(vector<vector<int>>& links) {
	vector<int> parents(links.size(), -1);

	for (unsigned int i = 0; i < links.size(); i++) {
		if (links[i][0] != -1)
			parents[links[i][0]] = i;
		if (links[i][1] != -1)
			parents[links[i][1]] = i;
	}

	for (unsigned int i = 0; i < parents.size(); i++) {
		if (parents[i] == -1)
			return i;
	}

	return 0;
}

int solution(int k, vector<int> num, vector<vector<int>> links) {
	int answer = 0;
	priority_queue<Root, vector<Root>, less<Root>> treeRoots;
	int temp = findRoot(links);
	treeRoots.push({ countPeople(num, links, temp), temp });

	while (treeRoots.size() != k) {
		int target = treeRoots.top().second;
		int originalSize = treeRoots.top().first;

		treeRoots.pop();

		int leftSubTreeSize = countPeople(num, links, links[target][0]);
		int rightSubTreeSize = countPeople(num, links, links[target][1]);
		int newTargetSize = originalSize;

		if (leftSubTreeSize > rightSubTreeSize) {
			treeRoots.push({ leftSubTreeSize, links[target][0] });
			links[target][0] = -1;
			newTargetSize -= leftSubTreeSize;
		}
		else {
			treeRoots.push({ rightSubTreeSize, links[target][1] });
			links[target][1] = -1;
			newTargetSize -= rightSubTreeSize;
		}

		treeRoots.push({ newTargetSize, target });
	}

	return treeRoots.top().first;
}

#include <iostream>

int main() {
	cout << solution(3,
		{ 1,2,3 },
		{ {-1, -1}, {-1, -1}, {0,1} }
	) << endl;
}