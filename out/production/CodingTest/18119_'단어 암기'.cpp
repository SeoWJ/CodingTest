#include <iostream>
#include <unordered_map>
#include <vector>
#include <cstring>

#define endl '\n'

using namespace std;

int N, M;
vector<int> words;
int alphabet;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	alphabet = 0b00000011111111111111111111111111;

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		string word; cin >> word;

		int wordBit = 0x00000000;

		for (unsigned int x = 0; x < word.size(); x++) {
			int mask = 0x00000001 << (word[x] - 'a');

			wordBit |= mask;
		}

		words.push_back(wordBit);
	}

	for (int i = 0; i < M; i++) {
		int O; char X;
		cin >> O >> X;

		if (O == 1)
			alphabet &= ~(0x00000001 << (X - 'a'));
		else
			alphabet |= (0x00000001 << (X - 'a'));

		int know = 0;
		for (unsigned int x = 0; x < words.size(); x++) {
			if ((words[x] & alphabet) == words[x])
				know++;
		}
		cout << know << endl;
	}

	return 0;
}