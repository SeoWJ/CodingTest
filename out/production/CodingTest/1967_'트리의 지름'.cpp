#include <iostream>
#include <queue>
#include <vector>

#define endl '\n'
#define max(a, b) a > b ? a : b
#define INFINITY 101

using namespace std;

int N;
deque<pair<int, int>> connection[10001];
deque<int> leaf;
bool visit[10001];
int tree_diameter = 0;

void DFS(int start, int diameter);
void clearVisit();

int main(int argc, char* argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	int start, destination, weight;
	
	while (cin >> start >> destination >> weight) {
		connection[start].push_back({ destination, weight });
		connection[destination].push_back({ start, weight });
	}

	/*while (1) {
		cin >> start;
		if (start == -1) break;
		cin >> destination >> weight;

		connection[start].push_back({ destination, weight });
		connection[destination].push_back({ start, weight });
	}*/

	for (int i = 1; i <= N; i++) {
		if (connection[i].size() == 1)
			leaf.push_back(i);
	}

	for (unsigned int i = 0; i < leaf.size(); i++) {
		clearVisit();
		DFS(leaf[i], 0);
	}

	cout << tree_diameter << endl;
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

void clearVisit() {
	for (int i = 0; i <= N; i++)
		visit[i] = false;
}