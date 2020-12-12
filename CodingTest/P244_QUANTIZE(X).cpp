#include <iostream>

#define endl '\n'

using namespace std;

int sequence[101];

void Quantization();
void clear();

int main(int argc, char* argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int C; cin >> C;

	while (C--)
		Quantization();

	return 0;
}

void Quantization() {
	clear();

	int N, S; cin >> N >> S;

	for (int x = 1; x <= N; x++) cin >> sequence[x];


}

void clear() { for (int x = 0; x < 101; x++) sequence[x] = 0; }