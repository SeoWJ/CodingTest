#include <iostream>
#include <vector>

#define endl '\n'
#define max(a, b) a > b ? a : b

using namespace std;

void integerTriangle();

int main(int argc, char* argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	integerTriangle();

	return 0;
}

void integerTriangle() {
	vector<vector<int>> triangle;

	int n; cin >> n;

	for (int y = 0; y < n; y++) {
		vector<int> temp;

		for (int x = 0; x < y + 1; x++) {
			int input; cin >> input;
			temp.push_back(input);
		}

		triangle.push_back(temp);
	}

	for (int y = n - 2; y >= 0; y--) {
		for (int x = 0; x < triangle[y].size(); x++) {
			triangle[y][x] = max(triangle[y][x] + triangle[y + 1][x], triangle[y][x] + triangle[y + 1][x + 1]);
		}
	}

	cout << triangle[0][0] << endl;
}