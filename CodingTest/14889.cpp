#include <iostream>
#include <vector>

#define endl '\n'

using namespace std;

int N;
vector<vector<bool>> start_list;
vector<vector<bool>> link_list;

void startAndLink();
void createTeam(vector<bool> start, int true_cnt);

int main(int argc, char* argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	startAndLink();

	return 0;
}

void startAndLink() {
	cin >> N;

	int map[20][20] = { 0 };

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cin >> map[y][x];
		}
	}
	
	vector<bool> b_temp;
	createTeam(b_temp, 0);
	
	vector<int> gap;

	for (unsigned int idx = 0; idx < start_list.size(); idx++) {
		int start_sum = 0;
		int link_sum = 0;
		
		for (unsigned int i = 0; i < start_list[idx].size(); i++) {
			if (start_list[idx][i] == false) continue;
			for (unsigned int j = 0; j < start_list[idx].size(); j++) {
				if (i == j) continue;
				if (start_list[idx][j] == false) continue;
				start_sum += map[i][j];
			}
		}
		
		for (unsigned int i = 0; i < link_list[idx].size(); i++) {
			if (link_list[idx][i] == false) continue;
			for (unsigned int j = 0; j < link_list[idx].size(); j++) {
				if (i == j) continue;
				if (link_list[idx][j] == false) continue;
				link_sum += map[i][j];
			}
		}

		gap.push_back(start_sum > link_sum ? start_sum - link_sum : link_sum - start_sum);
	}

	int min_gap = 0x7FFFFFFF;	// int의 최대값.
	for (unsigned int i = 0; i < gap.size(); i++)
		min_gap = min_gap > gap[i] ? gap[i] : min_gap;

	cout << min_gap << endl;
}

void createTeam(vector<bool> start, int true_cnt) {
	if (start.size() == N) {
		if (true_cnt == N / 2) {
			vector<bool> link;
			for (int i = 0; i < N; i++)
				link.push_back(!start[i]);

			start_list.push_back(start);
			link_list.push_back(link);
		}

		return;
	}
	
	start.push_back(true);
	createTeam(start, true_cnt + 1);
	start.pop_back();

	start.push_back(false);
	createTeam(start, true_cnt);
	start.pop_back();
}