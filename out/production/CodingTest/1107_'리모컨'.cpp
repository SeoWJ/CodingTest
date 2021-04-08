#include <iostream>
#include <cstring>
#include <string>

#define endl '\n'
#define difference(a, b) (a > b ? a - b : b - a)

using namespace std;

int N, M;
bool remoteController[10];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	memset(remoteController, true, sizeof(remoteController));

	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int input; cin >> input;
		remoteController[input] = false;
	}

	int noButton = difference(100, N);
	int yesButton = 0x7FFFFFFF;

	for (int i = 0; i <= 999999; i++) {
		string nextChannel = to_string(i);
		bool canMove = true;
		
		for (unsigned int i = 0; i < nextChannel.size(); i++) {
			if (remoteController[nextChannel[i] - '0'] == false) {
				canMove = false;
				break;
			}
		}

		if (canMove == false) continue;
		else {
			int count = nextChannel.size() + difference(atoi(nextChannel.c_str()), N);
			yesButton = yesButton < count ? yesButton : count;
		}
	}

	cout << (noButton < yesButton ? noButton : yesButton) << endl;

	return 0;
}