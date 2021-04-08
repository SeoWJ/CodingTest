#include <iostream>
#include <queue>
#include <string>
#include <cstring>

#define endl '\n'

using namespace std;

bool visit[10001];

void solution();

int D(int num);
int S(int num);
int L(int num);
int R(int num);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T; cin >> T;

	while (T--)
		solution();

	return 0;
}

void solution() {
	memset(visit, false, sizeof(visit));

	int A, B; cin >> A >> B;

	queue<pair<string, int>> Q;

	Q.push({ "", A });
	visit[A] = true;

	while (!Q.empty()) {
		int number = Q.front().second;
		string operation = Q.front().first;

		Q.pop();

		if (number == B) {
			cout << operation << endl;
			return;
		}
		else {
			int nextNumber;

			nextNumber = D(number);
			if (!visit[nextNumber]) {
				Q.push({ operation + 'D', nextNumber });
				visit[nextNumber] = true;
			}
			nextNumber = S(number);
			if (!visit[nextNumber]) {
				Q.push({ operation + 'S', nextNumber });
				visit[nextNumber] = true;
			}
			nextNumber = L(number);
			if (!visit[nextNumber]) {
				Q.push({ operation + 'L', nextNumber });
				visit[nextNumber] = true;
			}
			nextNumber = R(number);
			if (!visit[nextNumber]) {
				Q.push({ operation + 'R', nextNumber });
				visit[nextNumber] = true;
			}
		}
	}
}

int D(int num) {
	return (num * 2) % 10000;
}

int S(int num) {
	if (num == 0) return 9999;
	else return num - 1;
}

int L(int num) {
	if (num == 0) return 0;
	else return (num % 1000) * 10 + num / 1000;
}

int R(int num) {
	if (num == 0) return 0;
	else return (num / 10) + (num % 10) * 1000;
}