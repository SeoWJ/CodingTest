#include <iostream>
#include <vector>
#include <queue>

#define endl '\n'

using namespace std;

int N;

vector<vector<int>> map;
deque<vector<vector<int>>> Q;
vector<vector<vector<int>>> answer_white;
vector<vector<vector<int>>> answer_blue;

int main(int argc, char* argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	vector<int> temp;
	temp.assign(N, 0);
	map.assign(N, temp);

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++)
			cin >> map[y][x];
	}

	Q.push_back(map);

	while (!Q.empty()) {
		vector<vector<int>> paper = Q.front();
		Q.pop_front();

		bool blue = false;
		bool white = false;

		for (unsigned int y = 0; y < paper.size(); y++) {
			for (unsigned int x = 0; x < paper[y].size(); x++) {
				if (paper[y][x] == 1) blue = true;
				else white = true;

				if (blue && white)
					break;
			}
			if (blue && white)
				break;
		}

		if (blue && !white)
			answer_blue.push_back(paper);
		else if (!blue && white)
			answer_white.push_back(paper);
		else {
			vector<vector<int>> div1, div2, div3, div4;
			vector<int> temp;

			for (unsigned int y = 0; y < paper.size() / 2; y++) {
				for (unsigned int x = 0; x < paper[0].size() / 2; x++) {
					temp.push_back(paper[y][x]);
				}
				div1.push_back(temp);
				temp.clear();
				for (unsigned int x = paper[0].size() / 2; x < paper[0].size(); x++) {
					temp.push_back(paper[y][x]);
				}
				div2.push_back(temp);
				temp.clear();
			}

			for (unsigned int y = paper.size() / 2; y < paper.size(); y++) {
				for (unsigned int x = 0; x < paper[0].size() / 2; x++) {
					temp.push_back(paper[y][x]);
				}
				div3.push_back(temp);
				temp.clear();
				for (unsigned int x = paper[0].size() / 2; x < paper[0].size(); x++) {
					temp.push_back(paper[y][x]);
				}
				div4.push_back(temp);
				temp.clear();
			}

			Q.push_back(div1);
			Q.push_back(div2);
			Q.push_back(div3);
			Q.push_back(div4);
		}
	}

	cout << answer_white.size() << endl;
	cout << answer_blue.size() << endl;

	return 0;
}