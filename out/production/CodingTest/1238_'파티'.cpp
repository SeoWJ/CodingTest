#include <iostream>
#include <vector>

#define endl '\n'
#define INF 0x0FFFFFFF

using namespace std;

int N, M, X;

int edges[1001][1001];

void floydWashall();

int main(int argc, char* argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M >> X;

	for (int y = 0; y < 1001; y++) {
		for (int x = 0; x < 1001; x++) {
			if (y == x) edges[y][x] = 0;
			else edges[y][x] = INF;
		}
	}

	for (int i = 0; i < M; i++) {
		int start, destination, weight;
		cin >> start >> destination >> weight;

		edges[start][destination] = weight;
	}

	floydWashall();

	int longestDistance = 0;
	for (int i = 1; i <= N; i++) {
		int dist = edges[i][X] + edges[X][i];

		longestDistance = longestDistance > dist ? longestDistance : dist;
	}

	cout << longestDistance << endl;

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