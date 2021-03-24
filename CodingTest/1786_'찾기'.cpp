#include <iostream>
#include <string>
#include <cstring>
#include <vector>

#define endl '\n'

using namespace std;

class WordProcessor {
protected:
	string P;
	string T;
	vector<int> restartPosition;

public:
	WordProcessor(string t, string p) { P = p; T = t; }
	void preProcessing() {
		restartPosition.push_back(0);

		for (unsigned int i = 1; i < P.size(); i++) {
			string subString = P.substr(0, i);

			int longest = 0;
			int idxFront = 0, idxBack = subString.size() - 1;

			while (idxFront < idxBack) {
				string prefix = subString.substr(0, idxFront + 1);
				string suffix = subString.substr(idxBack, idxFront + 1);

				if (prefix == suffix) longest = idxFront + 1;

				idxFront++; idxBack--;
			}

			restartPosition.push_back(longest);
		}
	}
	pair<int, vector<int>> solution() {
		int count = 0;
		vector<int> P_Pos;
		preProcessing();
		
		int patternIndex = 0;

		for (unsigned int i = 0; i < T.size(); i++) {
			if (T[i] == P[patternIndex]) {
				if (patternIndex == P.size() - 1) {
					count++;
					patternIndex = 0;
					P_Pos.push_back(i - (P.size() - 1) + 1);
					i -= (P.size() - 1);
				}
				else {
					patternIndex++;
				}
			}
			else {
				patternIndex = restartPosition[patternIndex];
				if (patternIndex > 0) i--;
			}
		}

		return { count, P_Pos };
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string T, P;
	getline(cin, T);
	getline(cin, P);

	WordProcessor wp(T, P);

	pair<int, vector<int>> result = wp.solution();

	cout << result.first << endl;

	for (unsigned int i = 0; i < result.second.size(); i++) {
		cout << result.second[i] << " ";
	}
	cout << endl;

	return 0;
}