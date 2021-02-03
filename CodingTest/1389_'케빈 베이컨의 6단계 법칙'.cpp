#include <iostream>

#define endl '\n'
#define INFINITE 0x0FFFFFFF

using namespace std;

int N, M;

int edges[101][101];

void clear();
void floydWashall();

int main(int argc, char* argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	clear();

	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int A, B; cin >> A >> B;
		edges[A][B] = edges[B][A] = 1;
	}

	floydWashall();

	int minimumKevinBacon = INFINITE;
	int answer = 0;
	for (int y = 1; y <= N; y++) {
		int kevinBacon = 0;
		
		for (int x = 1; x <= N; x++) {
			kevinBacon += edges[y][x];
		}

		answer = minimumKevinBacon <= kevinBacon ? answer : y;
		minimumKevinBacon = minimumKevinBacon <= kevinBacon ? minimumKevinBacon : kevinBacon;
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

void clear() {
	for (int y = 0; y < 101; y++) {
		for (int x = 0; x < 101; x++) {
			if (x == y) edges[y][x] = 0;
			else edges[y][x] = INFINITE;
		}
	}
}