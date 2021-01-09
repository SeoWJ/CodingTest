#include <iostream>
#include <queue>

#define endl '\n'
#define max(a, b) a > b ? a : b

using namespace std;

int V;
deque<pair<int, int>> connection[100001];
bool visit[100001];
deque<int> leaf;
int MFN = -1;
int MFN_dist = 0;
int tree_diameter = 0;

void clear();
void DFS(int start, int diameter);
void DFS(int start, int* MFN, int MFN_dist);

int main(int argc, char* argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> V;

	for (int i = 0; i < V; i++) {
		int start;
		cin >> start;

		while (1) {
			int destination, weight;
			cin >> destination;

			if (destination == -1)
				break;

			cin >> weight;

			connection[start].push_back({ destination, weight });
		}
	}

	clear();
	DFS(1, &MFN, 0);

	clear();
	DFS(MFN, 0);

	cout << tree_diameter << endl;

	return 0;
}

void DFS(int start, int* MFN, int dist) {
	visit[start] = true;
	*MFN = MFN_dist > dist ? *MFN : start;
	MFN_dist = max(MFN_dist, dist);	

	for (unsigned int i = 0; i < connection[start].size(); i++) {
		if (visit[connection[start][i].first] == false) {
			DFS(connection[start][i].first, MFN, dist + connection[start][i].second);
		}
	}
}

void DFS(int start, int diameter) {
	visit[start] = true;
	tree_diameter = max(tree_diameter, diameter);

	for (unsigned int i = 0; i < connection[start].size(); i++) {
		if (visit[connection[start][i].first] == false) {
			DFS(connection[start][i].first, diameter + connection[start][i].second);
		}
	}
}

void clear() {
	for (int i = 0; i <= V; i++)
		visit[i] = false;
}