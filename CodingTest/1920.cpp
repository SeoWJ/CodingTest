#include <iostream>
#include <algorithm>
#include <vector>

#define endl "\n"

using namespace std;

vector<int> N;
int M[100000] = { 0 };
int N_size, M_size;

bool binarySearch(int);

int main(int argc, char* argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N_size;
	for (int loop1 = 0; loop1 < N_size; loop1++) {
		int num; cin >> num;
		N.push_back(num);
	}

	sort(N.begin(), N.end());

	cin >> M_size;
	for (int loop1 = 0; loop1 < M_size; loop1++)
		cin >> M[loop1];

	for (int loop1 = 0; loop1 < M_size; loop1++) {
		cout << binarySearch(M[loop1]) << endl;
	}

	return 0;
}

bool binarySearch(int input) {
	int left, mid, right;
	left = 0; right = N_size - 1; mid = (left + right) / 2;

	while (left <= right) {
		if (input == N[mid])
			return true;

		else {// input != mid
			if (input < N[mid]) {
				right = mid - 1;
				mid = (left + right) / 2;
			}

			else {
				left = mid + 1;
				mid = (left + right) / 2;
			}
		}
	}

	return false;
}