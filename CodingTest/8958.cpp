#include <iostream>
#include <cstring>

#define endl '\n'

using namespace std;

void oxQuiz();

int main(int argc, char* argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T; cin >> T;

	while (T--)
		oxQuiz();

	return 0;
}

void oxQuiz() {
	string ox; cin >> ox;
	int score = 0;
	int combo = 1;

	for (unsigned int loop1 = 0; loop1 < ox.size(); loop1++) {
		if (ox[loop1] == 'O') {
			score += combo;
			combo++;
		}
		else
			combo = 1;
	}

	cout << score << endl;
}