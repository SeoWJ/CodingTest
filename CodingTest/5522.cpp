#include <iostream>

#define endl "\n"

using namespace std;

int main(int argc, char* argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int score[5], total = 0;

	for (int loop1 = 0; loop1 < 5; loop1++) {
		cin >> score[loop1];
		total += score[loop1];
	}

	cout << total << endl;

	return 0;
}