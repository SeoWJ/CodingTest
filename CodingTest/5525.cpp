#include <iostream>

#define endl '\n'

using namespace std;

void IOIOI();

int main(int argc, char* argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	IOIOI();

	return 0;
}

void IOIOI() {
	int N, M; cin >> N >> M;
	string S; cin >> S;
	string IOI = "I";
	int count = 0;

	for (unsigned int x = 0; x < S.size(); x++) {
		if (S[x] == 'I') {
			int O = 0;
			while (1) {
				if (S[x + 1] == 'O' && S[x + 2] == 'I') {
					O++;
					x += 2;
				}
				else break;
			}
			if(O >= N) count += O - N + 1;
		}
	}

	cout << count << endl;
}