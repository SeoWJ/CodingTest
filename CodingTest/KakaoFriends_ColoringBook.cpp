#include <vector>
#include <queue>
#include <iostream>

using namespace std;

vector<vector<int>> expand_picture;
vector<vector<bool>> visit;
int number_of_area = 0;
int max_size_of_one_area = 0;

void BFS(int x, int y) {
	int area = 0;

	if (expand_picture[y][x] == 0)
		return;
	if (visit[y][x] == true)
		return;

	queue<pair<int, int>> Q;
	Q.push(make_pair(x, y));
	visit[y][x] = true;
	area++;
	number_of_area++;

	while (!Q.empty()) {
		if (expand_picture[Q.front().second + 1][Q.front().first] == expand_picture[Q.front().second][Q.front().first] && visit[Q.front().second + 1][Q.front().first] == false) {
			area++;
			Q.push(make_pair(Q.front().first, Q.front().second + 1));
			visit[Q.front().second + 1][Q.front().first] = true;
		}
		if (expand_picture[Q.front().second - 1][Q.front().first] == expand_picture[Q.front().second][Q.front().first] && visit[Q.front().second - 1][Q.front().first] == false) {
			area++;
			Q.push(make_pair(Q.front().first, Q.front().second - 1));
			visit[Q.front().second - 1][Q.front().first] = true;
		}
		if (expand_picture[Q.front().second][Q.front().first + 1] == expand_picture[Q.front().second][Q.front().first] && visit[Q.front().second][Q.front().first + 1] == false) {
			area++;
			Q.push(make_pair(Q.front().first + 1, Q.front().second));
			visit[Q.front().second][Q.front().first + 1] = true;
		}
		if (expand_picture[Q.front().second][Q.front().first - 1] == expand_picture[Q.front().second][Q.front().first] && visit[Q.front().second][Q.front().first - 1] == false) {
			area++;
			Q.push(make_pair(Q.front().first - 1, Q.front().second));
			visit[Q.front().second][Q.front().first - 1] = true;
		}
		Q.pop();
	}

	max_size_of_one_area = max_size_of_one_area > area ? max_size_of_one_area : area;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {	
	number_of_area = 0;
	max_size_of_one_area = 0;
	expand_picture.clear();
	visit.clear();
	vector<int> temp1;
	temp1.assign(n + 2, 0);
	vector<bool> temp2;
	temp2.assign(n + 2, false);
	for (int y = 0; y < m + 2; y++) {
		expand_picture.push_back(temp1);
		visit.push_back(temp2);
	}

	for (int y = 0; y < m; y++) {
		for (int x = 0; x < n; x++) {
			expand_picture[y + 1][x + 1] = picture[y][x];
		}
	}

	for (int y = 1; y <= m; y++) {
		for (int x = 1; x <= n; x++) {
			BFS(x, y);
		}
	}

	vector<int> answer(2);
	answer[0] = number_of_area;
	answer[1] = max_size_of_one_area;
	return answer;
}

int main() {
	int m = 6, n = 4;
	vector<vector<int>> picture = {
		{1, 1, 1, 0}, {1, 1, 1, 0}, {0, 0, 0, 1}, {0, 0, 0, 1}, {0, 0, 0, 1}, {0, 0, 0, 1}
	};

	vector<int> answer = solution(m, n, picture);

	cout << answer[0] << " " << answer[1] << endl;
}