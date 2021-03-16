#include <iostream>
#include <vector>

#define endl '\n'

using namespace std;

int N;
vector<int> T;
vector<int> P;
int answer;

void bruteForce(int day, int totalCost);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	answer = 0;
	T = P = { 0 };

	cin >> N;

	for (int i = 0; i < N; i++) {
		int t, p; cin >> t >> p;
		T.push_back(t);
		P.push_back(p);
	}

	bruteForce(1, 0);

	cout << answer << endl;

	return 0;
}

void bruteForce(int day, int totalCost) {
	if (day >= N + 1) {
		answer = answer > totalCost ? answer : totalCost;
		return;
	}

	if(day + T[day] <= N + 1)
		bruteForce(day + T[day], totalCost + P[day]);
	bruteForce(day + 1, totalCost);
}