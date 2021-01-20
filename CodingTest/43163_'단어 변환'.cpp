// Sol 1.

/*#include <string>
#include <vector>
#include <iostream>

using namespace std;

int answer = 0x7FFFFFFF;
string targetWord;
vector<string> wordsArr;

void DFS(int count, string currentWord, bool visit[]);
vector<int> canChangeList(string currentWord, bool visit[]);

int solution(string begin, string target, vector<string> words) {
	targetWord = target;
	wordsArr = words;

	bool exist = false;
	for (unsigned int i = 0; i < words.size(); i++) {
		if (words[i] == target)
			exist = true;
	}

	if (!exist) return 0;

	bool visit[50] = { false };

	DFS(0, begin, visit);

	return answer;
}

void DFS(int count, string currentWord, bool visit[]) {
	if (currentWord == targetWord) {
		answer = answer < count ? answer : count;
		return;
	}

	vector<int> canChangeWordIdx = canChangeList(currentWord, visit);

	for (unsigned int i = 0; i < canChangeWordIdx.size(); i++) {
		visit[canChangeWordIdx[i]] = true;
		DFS(count + 1, wordsArr[canChangeWordIdx[i]], visit);
		visit[canChangeWordIdx[i]] = false;
	}
}

vector<int> canChangeList(string currentWord, bool visit[]) {
	vector<int> result;

	for (unsigned int i = 0; i < wordsArr.size(); i++) {
		if (visit[i] == false) {
			int difference = 0;

			for (unsigned int j = 0; j < currentWord.size(); j++) {
				if (currentWord[j] != wordsArr[i][j])
					difference++;
			}

			if (difference <= 1) result.push_back(i);
		}
	}

	return result;
}

int main() {
	cout << solution("hit", "cog", { "hot", "dot", "dog", "lot", "log", "cog" }) << endl;
}*/

// Sol 2.

/*#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

struct Node {
	string word;
	vector<bool> visit;
	int count;
};

int solution(string begin, string target, vector<string> words) {
	bool exist = false;
	for (unsigned int i = 0; i < words.size(); i++) {
		if (target == words[i]) exist = true;
	}

	if (!exist) return 0;
	
	queue<Node> Q;
	int answer = 0x7FFFFFFF;

	vector<bool> temp;
	temp.assign(words.size(), false);
	Node n = { begin, temp, 0 };
	Q.push(n);

	while (!Q.empty()) {
		string currentWord = Q.front().word;
		vector<bool> visit = Q.front().visit;
		int currentCount = Q.front().count;

		Q.pop();

		if (currentWord == target) {
			answer = answer < currentCount ? answer : currentCount;
			continue;
		}
		else {
			for (unsigned int i = 0; i < words.size(); i++) {
				if (visit[i] == false) {
					int difference = 0;

					for (unsigned int j = 0; j < words[i].size(); j++) {
						if (currentWord[j] != words[i][j])
							difference++;
					}

					if (difference <= 1) {
						visit[i] = true;
						Q.push({ words[i], visit, currentCount + 1 });
						visit[i] = false;
					}
				}
			}
		}
	}

	return answer;
}

int main() {
	cout << solution("hit", "cog", { "hot", "dot", "dog", "lot", "log", "cog" }) << endl;
}*/