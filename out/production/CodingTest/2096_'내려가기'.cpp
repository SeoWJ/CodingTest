#include <iostream>

#define endl '\n'
#define max2(a,b) (a > b ? a : b)
#define max3(a,b,c) (a > b ? (a > c ? a : c) : (b > c ? b : c))
#define min2(a,b) (a < b ? a : b)
#define min3(a,b,c) (a < b ? (a < c ? a : c) : (b < c ? b : c))

using namespace std;

int main(int argc, char* argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N; cin >> N;

	int prevMax[3];
	int prevMin[3];
	int max[3];
	int min[3];
	int input[3];

	for (int i = 0; i < 3; i++) {
		cin >> prevMax[i];
		max[i] = min[i] = prevMin[i] = prevMax[i];
	}

	for (int i = 0; i < N - 1; i++) {
		cin >> input[0] >> input[1] >> input[2];

		max[0] = input[0] + max2(prevMax[0], prevMax[1]);
		max[1] = input[1] + max3(prevMax[0], prevMax[1], prevMax[2]);
		max[2] = input[2] + max2(prevMax[1], prevMax[2]);

		min[0] = input[0] + min2(prevMin[0], prevMin[1]);
		min[1] = input[1] + min3(prevMin[0], prevMin[1], prevMin[2]);
		min[2] = input[2] + min2(prevMin[1], prevMin[2]);

		for (int j = 0; j < 3; j++) {
			prevMax[j] = max[j];
			prevMin[j] = min[j];
		}
	}

	int maximum = max3(max[0], max[1], max[2]);
	int minimum = min3(min[0], min[1], min[2]);

	cout << maximum << " " << minimum << endl;

	return 0;
}