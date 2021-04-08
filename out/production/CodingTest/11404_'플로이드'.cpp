#include <iostream>

#define endl '\n'
#define INFINITE 0x0FFFFFFF

using namespace std;

int N, M;

int edges[101][101];
int result[101][101];

void clear();
void floydWashall();

int main(int argc, char* argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	clear();

	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int start, destination, weight;
		cin >> start >> destination >> weight;

		edges[start][destination] = edges[start][destination] < weight ? edges[start][destination] : weight;
	}

	floydWashall();

	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {
			if (result[y][x] == INFINITE)
				cout << "0" << " ";
			else
				cout << result[y][x] << " ";
		}
		cout << endl;
	}

	return 0;
}

void floydWashall() {
	for (int y = 0; y < 101; y++) {
		for (int x = 0; x < 101; x++)
			result[y][x] = edges[y][x];
	}

	for (int midPoint = 1; midPoint <= N; midPoint++) {
		for (int start = 1; start <= N; start++) {
			for (int destination = 1; destination <= N; destination++) {
				int beforeDistance = result[start][destination];
				int newDistance = result[start][midPoint] + result[midPoint][destination];

				if (newDistance < beforeDistance)
					result[start][destination] = newDistance;
			}
		}
	}
}

void clear() {
	for (int y = 0; y < 101; y++) {
		for (int x = 0; x < 101; x++) {
			edges[y][x] = INFINITE;

			if (y == x)
				edges[y][x] = 0;
		}
	}
}