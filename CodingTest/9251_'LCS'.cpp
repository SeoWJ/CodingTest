#include <iostream>
#include <vector>
#include <queue>

#define endl '\n'

using namespace std;

string seq1_original, seq2_original;
vector<string> answer;

class CS_info {
public:
	string sequence;
	int start1;
	int start2;

	CS_info(string seq, int start1, int start2) {
		sequence = seq;
		this->start1 = start1;
		this->start2 = start2;
	}
};

void solution();

int main(int argc, char* argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> seq1_original >> seq2_original;

	solution();

	return 0;
}

void solution() {
	deque<CS_info> LCS;

	int longer_length = seq1_original.size() > seq2_original.size() ? seq1_original.size() : seq2_original.size();
	int shorter_length = seq1_original.size() > seq2_original.size() ? seq2_original.size() : seq1_original.size();

	string seq1 = "", seq2 = "";

	seq1 += seq1_original[0];
	seq2 += seq2_original[0];

	if (seq1_original[0] == seq2_original[0])
		LCS.push_back(CS_info("" + seq1_original[0], 0, 0));
	else
		LCS.push_back(CS_info("", -1, -1));

	for (int i = 1; i < shorter_length; i++) {
		seq1 += seq1_original[i];
		seq2 += seq2_original[i];

		deque<CS_info> LCS_cpy = LCS;
		LCS.clear();

		while (!LCS_cpy.empty()) {
			bool updated = false;

			for (int j = LCS_cpy[0].start2 + 1; j < seq2.size(); j++) {
				if (seq2[j] == seq1[i]) {
					LCS.push_back(CS_info(LCS_cpy[0].sequence + seq1[i], i, j));
					updated = true;
					break;
				}
			}

			for (int j = LCS_cpy[0].start1 + 1; j < seq1.size(); j++) {
				if (seq1[j] == seq2[i]) {
					LCS.push_back(CS_info(LCS_cpy[0].sequence + seq2[i], j, i));
					updated = true;
					break;
				}
			}

			if (updated == false)
				LCS.push_back(LCS_cpy[0]);

			LCS_cpy.pop_front();
		}
	}

	int maximum = 0;
	for (unsigned int i = 0; i < LCS.size(); i++) {
		maximum = LCS[i].sequence.size() > maximum ? LCS[i].sequence.size() : maximum;
	}

	cout << maximum << endl;
}