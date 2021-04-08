#include <iostream>

#define endl "\n"

using namespace std;

struct Node {
	bool edge[101] = { false };
};

Node* node[101] = { NULL };
bool map[101][101] = { false };
bool visit[101] = { false };

void operation();
void bfs(int start, int start2, int destination);
void clearVisit();

int main(int argc, char* argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	operation();

	return 0;
}

void operation() {
	int N; cin >> N;

	for (int loop1 = 1; loop1 <= N; loop1++)
		node[loop1] = new Node();

	for (int loop1 = 1; loop1 <= N; loop1++) {
		for (int loop2 = 1; loop2 <= N; loop2++)
			cin >> node[loop1]->edge[loop2];
	}

	for (int loop1 = 1; loop1 <= N; loop1++) {
		for (int loop2 = 1; loop2 <= N; loop2++) {
			bfs(loop1, loop1, loop2);
			clearVisit();
		}
	}

	for (int loop1 = 1; loop1 <= N; loop1++) {
		for (int loop2 = 1; loop2 <= N; loop2++) {
			cout << map[loop1][loop2] << " ";
		}
		cout << endl;
	}
}

void bfs(int start, int start2, int destination) {
	for (int loop1 = 1; loop1 < 101; loop1++) {
		if (node[start]->edge[destination] == true || node[start2]->edge[destination] == true) {
			map[start][destination] = true;
			return;
		}
		if (node[start2]->edge[loop1] == true && visit[loop1] == false) {
			visit[loop1] = true;
			bfs(start, loop1, destination);
		}
	}
}

void clearVisit() {
	for (int loop1 = 0; loop1 < 101; loop1++)
		visit[loop1] = false;
}