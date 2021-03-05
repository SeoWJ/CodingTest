#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

#define endl '\n'

using namespace std;

int N, M;

void solution();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	solution();

	return 0;
}

void solution() {
	cin >> N >> M;

	bool people[51];
	bool canLie[51];
	vector<vector<int>> party;
	unordered_map<int, vector<int>> um;
	queue<int> knowTrueQueue;

	party.assign(M, {});
	for (int i = 0; i < 51; i++) {
		people[i] = false; canLie[i] = true;
	}

	int knowTrue;
	cin >> knowTrue;
	for (int i = 0; i < knowTrue; i++) {
		int input; cin >> input;
		people[input] = true;
		knowTrueQueue.push(input);
	}

	for (int i = 0; i < M; i++) {
		int partyPeople; cin >> partyPeople;
		for (int j = 0; j < partyPeople; j++) {
			int input; cin >> input;
			party[i].push_back(input);
			um[input].push_back(i);
		}
	}

	while (!knowTrueQueue.empty()) {
		int currentPerson = knowTrueQueue.front();

		knowTrueQueue.pop();

		for (unsigned int i = 0; i < um[currentPerson].size(); i++) {
			canLie[um[currentPerson][i]] = false;

			for (unsigned int j = 0; j < party[um[currentPerson][i]].size(); j++) {
				if (people[party[um[currentPerson][i]][j]] == false) {
					people[party[um[currentPerson][i]][j]] = true;
					knowTrueQueue.push(party[um[currentPerson][i]][j]);
				}					
			}
		}
	}

	int answer = 0;
	for (int i = 0; i < M; i++) {
		if (canLie[i] == true)
			answer++;
	}

	cout << answer << endl;
}