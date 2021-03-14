#include <iostream>
#include <cstring>
#include <vector>

#define endl '\n'
#define LIMIT 100000000000

using namespace std;

typedef vector<vector<int>> Matrix;

Matrix A;
int N;
long long B;
vector<long long> squareNumber;
vector<Matrix> matrixSquare;

Matrix matrixMultiple(Matrix m1, Matrix m2);
Matrix makeStandardMatrix(int size);
void printMatrix(Matrix m);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> B;

	vector<int> temp;
	temp.assign(N, 0);
	A.assign(N, temp);	

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++)
			cin >> A[y][x];
	}

	Matrix m = A;
	for (long long i = 1; i <= LIMIT; i *= 2) {
		squareNumber.push_back(i);

		if (i == 1) matrixSquare.push_back(m);
		else {
			m = matrixMultiple(m, m);
			matrixSquare.push_back(m);
		}
	}

	int idx = squareNumber.size() - 1;
	Matrix result = makeStandardMatrix(N);

	while (idx >= 0 && B > 0) {
		if (B >= squareNumber[idx]) {
			B -= squareNumber[idx];
			result = matrixMultiple(result, matrixSquare[idx]);
		}
		else idx--;
	}

	printMatrix(result);

	return 0;
}

Matrix matrixMultiple(Matrix m1, Matrix m2) {
	Matrix result;

	for (int y1 = 0; y1 < N; y1++) {
		vector<int> row;
		
		for (int x2 = 0; x2 < N; x2++) {
			int element = 0;
		
			for (int x1 = 0, y2 = 0; x1 < N && y2 < N; x1++, y2++) {
				element = (element + (m1[y1][x1] * m2[y2][x2])) % 1000;
			}

			row.push_back(element);
		}

		result.push_back(row);
	}

	return result;
}

Matrix makeStandardMatrix(int size) {
	Matrix result;
	vector<int> row;
	row.assign(size, 0);
	result.assign(size, row);

	for (unsigned int y = 0; y < size; y++) {
		for (unsigned int x = 0; x < size; x++) {
			if (x == y) result[y][x] = 1;
		}
	}

	return result;
}

void printMatrix(Matrix m) {
	for (auto v : m) {
		for (auto e : v)
			cout << e << " ";
		cout << endl;
	}
}