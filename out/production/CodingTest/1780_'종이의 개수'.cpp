#include <iostream>
#include <vector>

#define endl '\n'

using namespace std;

int N;
vector<vector<int>> paper;

int onePaper = 0;
int zeroPaper = 0;
int minusOnePaper = 0;

int checkPaper(int startX, int endX, int startY, int endY) {
	bool allOne = true;
	bool allZero = true;
	bool allMinusOne = true;

	for (int y = startY; y <= endY; y++) {
		if (!allOne && !allZero && allMinusOne)
			break;

		for (int x = startX; x <= endX; x++) {
			if (!allOne && !allZero && !allMinusOne)
				break;

			if (paper[y][x] == 1)
				allZero = allMinusOne = false;
			else if (paper[y][x] == 0)
				allOne = allMinusOne = false;
			else
				allOne = allZero = false;
		}
	}

	if (allOne && !allZero && !allMinusOne)
		return 1;
	else if (!allOne && allZero && !allMinusOne)
		return 0;
	else if (!allOne && !allZero && allMinusOne)
		return -1;
	else
		return 2;
}

void DFS(int startX, int endX, int startY, int endY) {
	int check = checkPaper(startX, endX, startY, endY);

	switch (check) {
	case 1:
		onePaper++;
		return;
		
	case 0:
		zeroPaper++;
		return;

	case -1:
		minusOnePaper++;
		return;

	case 2:
		int term = (endX - startX) / 3;
		
		int startX1 = startX;
		int startX2 = startX1 + term + 1;
		int startX3 = startX2 + term + 1;

		int startY1 = startY;
		int startY2 = startY1 + term + 1;
		int startY3 = startY2 + term + 1;

		DFS(startX1, startX1 + term, startY1, startY1 + term);
		DFS(startX2, startX2 + term, startY1, startY1 + term);
		DFS(startX3, startX3 + term, startY1, startY1 + term);

		DFS(startX1, startX1 + term, startY2, startY2 + term);
		DFS(startX2, startX2 + term, startY2, startY2 + term);
		DFS(startX3, startX3 + term, startY2, startY2 + term);

		DFS(startX1, startX1 + term, startY3, startY3 + term);
		DFS(startX2, startX2 + term, startY3, startY3 + term);
		DFS(startX3, startX3 + term, startY3, startY3 + term);

		break;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int y = 0; y < N; y++) {
		vector<int> row;
		
		for (int x = 0; x < N; x++) {
			int input; cin >> input;
			row.push_back(input);
		}
		
		paper.push_back(row);
	}

	DFS(0, N - 1, 0, N - 1);

	cout << minusOnePaper << endl;
	cout << zeroPaper << endl;
	cout << onePaper << endl;

	return 0;
}