#include <iostream>
#include <vector>

#define endl '\n'
#define INF 0x0FFFFFFF

using namespace std;

int N, M, R;
int edges[101][101];
int itemAmount[101];

void floydWashall();

int main(int argc, char* argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for (int y = 0; y < 101; y++) {
		itemAmount[y] = 0;
		for (int x = 0; x < 101; x++) {
			if (y == x) edges[y][x] = 0;
			else edges[y][x] = INF;
		}
	}

	cin >> N >> M >> R;

	for (int i = 1; i <= N; i++)
		cin >> itemAmount[i];

	for (int i = 0; i < R; i++) {
		int start, destination, weight;
		cin >> start >> destination >> weight;

		edges[start][destination] = edges[destination][start] = weight;
	}

	floydWashall();

	int answer = 0;

	for (int y = 1; y <= N; y++) {
		int temp = 0;
		for (int x = 1; x <= N; x++) {
			if (edges[y][x] <= M)
				temp += itemAmount[x];
		}
		answer = answer > temp ? answer : temp;
	}

	cout << answer << endl;

	return 0;
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