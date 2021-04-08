#include <iostream>

#define endl "\n"

typedef unsigned long long int64;

using namespace std;

pair<int64, int64> list[41];

void calculateList();

int main(int argc, char* argv[]) {
	int T; cin >> T;
	calculateList();

	while (T--) {
		int N;  cin >> N;
		cout << list[N].first << " " << list[N].second << endl;
	}

	return 0;
}

void calculateList() {
	list[0] = make_pair(1, 0);
	list[1] = make_pair(0, 1);
	for (int loop1 = 2; loop1 < 41; loop1++)
		list[loop1] = make_pair((list[loop1 - 2].first + list[loop1 - 1].first), (list[loop1 - 2].second + list[loop1 - 1].second));
}