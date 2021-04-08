#include <iostream>
#include <string>
#include <vector>

using namespace std;

int answer = 0;

pair<vector<string>, bool> remove(int m, int n, vector<string> board) {
	vector<string> newBoard = board;
	bool changed = false;

	for (unsigned int y = 0; y < m - 1; y++) {
		for (unsigned int x = 0; x < n - 1; x++) {
			if (board[y][x] != 0 && board[y][x] == board[y][x + 1] && board[y][x] == board[y + 1][x] && board[y][x] == board[y + 1][x + 1]) {
				newBoard[y][x] = newBoard[y][x + 1] = newBoard[y + 1][x] = newBoard[y + 1][x + 1] = -1;
				changed = true;
			}
		}
	}

	for (unsigned int y = 0; y < m; y++) {
		for (unsigned int x = 0; x < n; x++) {
			if (newBoard[y][x] == -1) answer++;
		}
	}

	for (int x = 0; x < n; x++) {
		for (int y = m - 1; y >= 0; y--) {
			if (newBoard[y][x] == -1 || newBoard[y][x] == 0) {
				bool find = false;
				
				for (int yy = y; yy >= 0; yy--) {
					if (newBoard[yy][x] != 0 && newBoard[yy][x] != -1) {
						newBoard[y][x] = newBoard[yy][x];
						newBoard[yy][x] = 0;
						find = true;
						break;
					}
				}

				if (!find) newBoard[y][x] = 0;
			}
		}
	}

	return { newBoard, changed };
}

int solution(int m, int n, vector<string> board) {
	while (1) {
		pair<vector<string>, bool> result = remove(m, n, board);

		board = result.first;
		if (result.second == false) break;
	}

	return answer;
}