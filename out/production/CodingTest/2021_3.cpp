#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(vector<int> v1, vector<int> v2);

vector<int> solution(vector<string> info, vector<string> query) {
	vector<int> answer;
	vector<vector<vector<int>>> p_info;
	vector<vector<int>> p_query;

	for (int a = 1; a <= 3; a++) {
		for (int b = 1; b <= 2; b++) {
			for (int c = 1; c <= 2; c++) {
				for (int d = 1; d <= 2; d++) {
					vector<int> temp = { a,b,c,d, -1 };
					vector<vector<int>> v;
					v.push_back(temp);
					p_info.push_back(v);
				}
			}
		}
	}

	for (unsigned int y = 0; y < info.size(); y++) {
		vector<int> p_info_element;
		int x = 0;

		if (info[y][0] == 'c') p_info_element.push_back(1);
		else if (info[y][0] == 'j') p_info_element.push_back(2);
		else p_info_element.push_back(3);

		while (1) {
			if (info[y][x] == ' ') {
				x++;
				break;
			}
			x++;
		}

		if (info[y][x] == 'b') p_info_element.push_back(1);
		else p_info_element.push_back(2);

		while (1) {
			if (info[y][x] == ' ') {
				x++;
				break;
			}
			x++;
		}

		if (info[y][x] == 'j') p_info_element.push_back(1);
		else p_info_element.push_back(2);

		while (1) {
			if (info[y][x] == ' ') {
				x++;
				break;
			}
			x++;
		}

		if (info[y][x] == 'c') p_info_element.push_back(1);
		else p_info_element.push_back(2);

		while (1) {
			if (info[y][x] == ' ') {
				x++;
				break;
			}
			x++;
		}

		int score = 0;
		while (1) {
			score *= 10;
			score += info[y][x] - '0';
			if (x == info[y].size() - 1)
				break;
			x++;
		}
		p_info_element.push_back(score);

		for (unsigned int z = 0; z < p_info.size(); z++) {
			if (p_info[z][0][0] == p_info_element[0] &&
				p_info[z][0][1] == p_info_element[1] &&
				p_info[z][0][2] == p_info_element[2] &&
				p_info[z][0][3] == p_info_element[3]) {
				p_info[z].push_back(p_info_element);
			}
		}
	}

	for (unsigned int y = 0; y < query.size(); y++) {
		vector<int> p_query_element;
		int x = 0;

		if (query[y][0] == '-') p_query_element.push_back(0);
		else if (query[y][0] == 'c') p_query_element.push_back(1);
		else if (query[y][0] == 'j') p_query_element.push_back(2);
		else p_query_element.push_back(3);

		for (int i = 0; i < 2; i++) {
			while (1) {
				if (query[y][x] == ' ') {
					x++;
					break;
				}
				x++;
			}
		}

		if (query[y][x] == '-') p_query_element.push_back(0);
		else if (query[y][x] == 'b') p_query_element.push_back(1);
		else p_query_element.push_back(2);

		for (int i = 0; i < 2; i++) {
			while (1) {
				if (query[y][x] == ' ') {
					x++;
					break;
				}
				x++;
			}
		}

		if (query[y][x] == '-') p_query_element.push_back(0);
		else if (query[y][x] == 'j') p_query_element.push_back(1);
		else p_query_element.push_back(2);

		for (int i = 0; i < 2; i++) {
			while (1) {
				if (query[y][x] == ' ') {
					x++;
					break;
				}
				x++;
			}
		}

		if (query[y][x] == '-') p_query_element.push_back(0);
		else if (query[y][x] == 'c') p_query_element.push_back(1);
		else p_query_element.push_back(2);

		while (1) {
			if (query[y][x] == ' ') {
				x++;
				break;
			}
			x++;
		}

		int score = 0;
		while (1) {
			score *= 10;
			score += query[y][x] - '0';
			if (x == query[y].size() - 1)
				break;
			x++;
		}
		p_query_element.push_back(score);

		p_query.push_back(p_query_element);
	}

	for (unsigned int z = 0; z < p_info.size(); z++) {
		sort(p_info[z].begin(), p_info[z].end(), compare);
	}

	for (unsigned int y = 0; y < p_query.size(); y++) {
		int cnt = 0;

		for (unsigned int z = 0; z < p_info.size(); z++) {
			if ((p_info[z][0][0] == p_query[y][0] || p_query[y][0] == 0) &&
				(p_info[z][0][1] == p_query[y][1] || p_query[y][1] == 0) &&
				(p_info[z][0][2] == p_query[y][2] || p_query[y][2] == 0) &&
				(p_info[z][0][3] == p_query[y][3] || p_query[y][3] == 0)) {

				if (p_info[z].size() <= 3) {
					for (unsigned int x = 0; x < p_info[z].size(); x++) {
						if (p_info[z][x][4] >= p_query[y][4]) cnt++;
						if (p_info[z][x][4] < p_query[y][4]) break;
					}
				}
				else {
					int top= 0, bottom = p_info[z].size() - 1, mid = (top + bottom) / 2;
					while (1) {
						if (p_info[z][mid][4] == p_query[y][4]) {
							while (p_info[z][mid][4] == p_query[y][4]) {
								mid++;
							}
							cnt += mid;
							break;
						}
						else if (p_info[z][mid][4] > p_query[y][4]) {
							top = mid + 1;
							mid = (top + bottom) / 2;
							if (bottom <= top) {
								if (p_info[z][mid][4] > p_query[y][4]) {
									cnt += mid + 1;
									break;
								}
								else if(p_info[z][mid][4] < p_query[y][4]) {
									cnt += mid;
									break;
								}
								else {
									while (p_info[z][mid][4] == p_query[y][4]) {
										mid++;
									}
									cnt += mid;
									break;
								}
							}
						}
						else if (p_info[z][mid][4] < p_query[y][4]) {
							bottom = mid - 1;
							mid = (top + bottom) / 2;
							if (bottom <= top) {
								if (p_info[z][mid][4] > p_query[y][4]) {
									cnt += mid + 1;
									break;
								}
								else if (p_info[z][mid][4] < p_query[y][4]) {
									cnt += mid;
									break;
								}
								else {
									while (p_info[z][mid][4] == p_query[y][4]) {
										mid++;
									}
									cnt += mid;
									break;
								}
							}
						}
					}
				}
			}
		}

		answer.push_back(cnt);
	}

	return answer;
}

bool compare(vector<int> v1, vector<int> v2) {
	return v1[4] > v2[4];
}

int main() {
	vector<string> info = { "java backend junior pizza 150",
		"python frontend senior chicken 210",
		"python frontend senior chicken 150",
		"cpp backend senior pizza 260",
		"java backend junior chicken 80",
		"python backend senior chicken 50"
	};
	vector<string> query = { "java and backend and junior and pizza 100",
		"python and frontend and senior and chicken 200",
		"cpp and - and senior and pizza 250",
		"- and backend and senior and - 150",
		"- and - and - and chicken 100",
		"- and - and - and - 150"
	};

	solution(info, query);
}