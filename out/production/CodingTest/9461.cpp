#include <iostream>

#define endl '\n'

using namespace std;

long long triangle[101] = { 0,1,1,1,2,2,3 };

void calculateTriangle();
void operation();

int main(int argc, char* argv[]) {
	ios::sync_with_stdio(false);
	int T; cin >> T;
	calculateTriangle();

	while (T--)
		operation();

	return 0;
}

void calculateTriangle() {
	for (int loop1 = 7; loop1 < 101; loop1++)
		triangle[loop1] = triangle[loop1 - 1] + triangle[loop1 - 5];
}

void operation() {
	int N; cin >> N;

	cout << triangle[N] << endl;
}