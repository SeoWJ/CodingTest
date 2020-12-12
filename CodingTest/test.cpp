#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void solution(int sizeOfMatrix, int** matrix) {
	// TODO: 이곳에 코드를 작성하세요.
	int answer_size = 0;
	vector<int> answer_list;

	vector<vector<int>> map;
	vector<int> empty;
	empty.assign(sizeOfMatrix + 2, 0);
	map.push_back(empty);
	for (unsigned int i = 0; i < sizeOfMatrix; i++) {
		vector<int> temp;
		temp.push_back(0);
		for (unsigned int j = 0; j < sizeOfMatrix; j++)
			temp.push_back(matrix[i][j]);
		temp.push_back(0);
		map.push_back(temp);
	}
	map.push_back(empty);

	vector<vector<bool>> visit;
	vector<bool> init;
	init.assign(sizeOfMatrix + 2, false);
	visit.assign(sizeOfMatrix + 2, init);

	queue<pair<int, int>> Q;
	for (int y = 1; y <= sizeOfMatrix; y++) {
		for (int x = 1; x <= sizeOfMatrix; x++) {
			if (map[y][x] == 1 && visit[y][x] == false) {
				int area = 1;
				Q.push(make_pair(y, x));
				visit[y][x] = true;

				while (!Q.empty()) {
					if (map[Q.front().first + 1][Q.front().second] == 1 && visit[Q.front().first + 1][Q.front().second] == false) {
						Q.push(make_pair(Q.front().first + 1, Q.front().second));
						visit[Q.front().first + 1][Q.front().second] = true;
						area++;
					}
					if (map[Q.front().first - 1][Q.front().second] == 1 && visit[Q.front().first - 1][Q.front().second] == false) {
						Q.push(make_pair(Q.front().first - 1, Q.front().second));
						visit[Q.front().first - 1][Q.front().second] = true;
						area++;
					}
					if (map[Q.front().first][Q.front().second + 1] == 1 && visit[Q.front().first][Q.front().second + 1] == false) {
						Q.push(make_pair(Q.front().first, Q.front().second + 1));
						visit[Q.front().first][Q.front().second + 1] = true;
						area++;
					}
					if (map[Q.front().first][Q.front().second - 1] == 1 && visit[Q.front().first][Q.front().second - 1] == false) {
						Q.push(make_pair(Q.front().first, Q.front().second - 1));
						visit[Q.front().first][Q.front().second - 1] = true;
						area++;
					}
					Q.pop();
				}

				answer_size++;
				answer_list.push_back(area);
			}
		}
	}

	sort(answer_list.begin(), answer_list.end());

	cout << answer_size << endl;
	if (answer_size == 0)
		return;
	else {
		for (unsigned int i = 0; i < answer_list.size(); i++) {
			if (i == answer_list.size() - 1)
				cout << answer_list[i] << endl;
			else
				cout << answer_list[i] << " ";
		}
	}
}

struct input_data {
	int sizeOfMatrix;
	int** matrix;
};

void process_stdin(struct input_data& inputData) {
	string line;
	istringstream iss;

	getline(cin, line);
	iss.str(line);
	iss >> inputData.sizeOfMatrix;

	inputData.matrix = new int* [inputData.sizeOfMatrix];
	for (int i = 0; i < inputData.sizeOfMatrix; i++) {
		getline(cin, line);
		iss.clear();
		iss.str(line);
		inputData.matrix[i] = new int[inputData.sizeOfMatrix];
		for (int j = 0; j < inputData.sizeOfMatrix; j++) {
			iss >> inputData.matrix[i][j];
		}
	}
}

int main() {
	struct input_data inputData;
	process_stdin(inputData);

	solution(inputData.sizeOfMatrix, inputData.matrix);
	return 0;
}