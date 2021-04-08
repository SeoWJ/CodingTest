#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> permutation[9];

int solution(int N, int number) {
	int NN = 0;

	if (N == number) return 1;
	
	for (int i = 1; i <= 8; i++) {
		NN *= 10; NN += N;
		permutation[i].push_back(NN);
		if (NN == number) return i;
	}

	for (int i = 2; i <= 8; i++) {
		for (int j = 1; j < i; j++) {
			int k = i - j;

			for (unsigned int x = 0; x < permutation[j].size(); x++) {
				for (unsigned int y = 0; y < permutation[k].size(); y++) {
					permutation[i].push_back(permutation[j][x] + permutation[k][y]);
					if (permutation[j][x] + permutation[k][y] == number) return i;

					permutation[i].push_back(permutation[j][x] - permutation[k][y]);
					if (permutation[j][x] - permutation[k][y] == number) return i;

					permutation[i].push_back(permutation[j][x] * permutation[k][y]);
					if (permutation[j][x] * permutation[k][y] == number) return i;
					
					if (permutation[k][y] != 0) { 
						permutation[i].push_back(permutation[j][x] / permutation[k][y]);
						if (permutation[j][x] / permutation[k][y] == number) return i;
					}
				}
			}
		}
	}

	return -1;
}

int main() { cout << solution(5, 55); }