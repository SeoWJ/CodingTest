#include <string>
#include <vector>
#include <iostream>

using namespace std;

struct Node {
	int count = 0;
	Node* next[26] = { NULL };
};

Node* tree;
void insert(string word, Node* n);
int find(string query, Node * n);

vector<int> solution(vector<string> words, vector<string> queries) {
	vector<int> answer;
	tree = new Node;

	for (unsigned int i = 0; i < queries.size(); i++)
		insert(words[i], tree);

	for (unsigned int i = 0; i < words.size(); i++) {
		int result = find(words[i], tree);
		answer.push_back(result);
	}

	return answer;
}

void insert(string word, Node* n) {
	if (word.empty()) {
		n->count++;
		return;
	}
	char c = word[0];
	word.erase(word.begin());

	if (n->next[c - 'a'] == NULL)
		n->next[c - 'a'] = new Node;

	insert(word, n->next[c - 'a']);
}

int find(string query, Node* n) {
	if (query.empty()) {
		return n->count;
	}

	char c = query[0];
	query.erase(query.begin());

	if (c == '?') {
		int result = 0;
		for (char alphabet = 0; alphabet < 26; alphabet++) {
			if(n->next[alphabet] != NULL)
				result += find(query, n->next[alphabet]);
		}
		return result;
	}
	else {
		if (n->next[c - 'a'] == NULL) return 0;
		else return find(query, n->next[c - 'a']);
	}
}

int main() {
	solution({ "frodo", "front", "frost", "frozen", "frame", "kakao" },
		{ "fro??", "????o", "fr???", "fro???", "pro?" });
}