#include <iostream>
#include <vector>
#include <algorithm>

#define endl "\n"

using namespace std;

void operation();

int main(int argc, char* argv[]) {
	operation();

	return 0;
}

void operation() {
	int N; cin >> N;
	vector<int> arr;

	for (int loop1 = 0; loop1 < N; loop1++) {
		int input; cin >> input;
		arr.push_back(input);
	}

	sort(arr.begin(), arr.end());

	for (int loop1 = 0; loop1 < N; loop1++)
		cout << arr[loop1] << endl;
}