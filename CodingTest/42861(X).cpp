#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int n, vector<vector<int>> costs) {
	int answer = 0;
	vector<vector<int>> cost_map;
	vector<int> cost_temp;
	cost_temp.assign(n, -1);
	cost_map.assign(n, cost_temp);

	vector<int> tree;
	vector<int> fringe;

	for (unsigned int i = 0; i < costs.size(); i++) {
		cost_map[costs[i][0]][costs[i][1]] = costs[i][2];
		cost_map[costs[i][1]][costs[i][0]] = costs[i][2];
	}

	tree.push_back(0);
	
	for (int i = 1; i < n; i++) {
		if (cost_map[0][i] != -1)
			fringe.push_back(i);
	}

	while (tree.size() != n) {
		int minimum = 2100000000;
		int min_y = -1, min_x = -1;

		for (unsigned int y = 0; y < fringe.size(); y++) {
			for (unsigned int x = 0; x < n; x++) {
				bool tree_exist = false;
				for (int i = 0; i < tree.size(); i++) {
					if (x == tree[i]) {
						tree_exist = true;
						break;
					}
				}
				if (tree_exist == true) continue;
				if (0 <= cost_map[fringe[y]][x] && cost_map[fringe[y]][x] < minimum) {
					min_y = fringe[y];
					min_x = x;
					minimum = cost_map[fringe[y]][x];
				}
			}
		}

		for (vector<int>::iterator iter = fringe.begin(); iter != fringe.end(); iter++) {
			if (*iter == min_y) {
				tree.push_back(*iter);
				fringe.erase(iter);
				break;
			}
		}

		for (int i = 0; i < n; i++) {
			if (cost_map[tree.back()][i] != -1) {
				bool tree_exist = false;
				for (int j = 0; j < tree.size(); j++) {
					if (tree[j] == i) {
						tree_exist = true;
						break;
					}
				}
				if (tree_exist == false)
					fringe.push_back(i);
			}
		}
		sort(fringe.begin(), fringe.end());
		fringe.erase(unique(fringe.begin(), fringe.end()), fringe.end());

		answer += minimum;
	}

	return answer;
}

int main() {
	vector<vector<int>> costs = { {0,1,1},{0,2,2},{1,2,5},{1,3,1},{2,3,8} };
	cout << solution(4, costs) << endl;
}