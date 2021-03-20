#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

string Word;

struct Node {
	int id;
	string name;
	int parentId;
	
	vector<Node*> child;
	Node* parent = NULL;

	Node(int _id, string _name, int _parentId) { id = _id; name = _name; parentId = _parentId; }
};

void insert(Node* p, Node* n) {
	if (n->parentId == p->id) {
		n->parent = p;
		p->child.push_back(n);
		return;
	}
	else {
		for (unsigned int i = 0; i < p->child.size(); i++)
			insert(p->child[i], n);
	}
}

vector<Node*> search(string word, vector<Node*>& list) {
	vector<Node*> result;
	for (unsigned int i = 0; i < list.size(); i++) {
		if (!list[i]->child.empty()) continue;
		else {
			string name = list[i]->name;

			for (unsigned int j = 0; j <= name.size() - word.size(); j++) {
				string sub = name.substr(j, word.size());
				if (sub == word) {
					result.push_back(list[i]);
					break;
				}
			}
		}
	}
	return result;
}

deque<string> showResult(Node* n, deque<string> result) {
	if (n->id == 0) return result;
	else {
		result.push_front(n->name);
		return showResult(n->parent, result);
	}
}

bool compare(Node* n1, Node* n2) {
	if(n1->name == Word && n2->name == Word) return n1->id < n2->id;
	else if (n1->name == Word && n2->name != Word)
		return true;
	else if (n1->name != Word && n2->name == Word)
		return false;

	int wordCount1=0, wordCount2=0;

	for (unsigned int i = 0; i <= n1->name.size() - Word.size(); i++) {
		string sub = n1->name.substr(i, Word.size());
		if (sub == Word) {
			wordCount1++;
			i += Word.size() - 1;
		}
	}
	for (unsigned int i = 0; i <= n2->name.size() - Word.size(); i++) {
		string sub = n2->name.substr(i, Word.size());
		if (sub == Word) {
			wordCount2++;
			i += Word.size() - 1;
		}
	}

	if (wordCount1 != wordCount2) return wordCount1 > wordCount2;

	int limit = n1->name.size() < n2->name.size() ? n1->name.size() : n2->name.size();

	for (unsigned int i = 0; i <= limit - Word.size(); i++) {
		string sub1 = n1->name.substr(i, Word.size());
		string sub2 = n2->name.substr(i, Word.size());

		if (sub1 == Word && sub2 == Word) i += Word.size() - 1;
		else if (sub1 == Word && sub2 != Word) return true;
		else if (sub1 != Word && sub2 == Word) return false;
		else continue;
	}

	return n1->id < n2->id;
}

vector<string> solution(vector<string> data, string word) {
	Word = word;
	vector<string> answer;
	vector<Node*> list;

	Node* root = new Node(0, "", -1);

	for (unsigned int i = 0; i < data.size(); i++) {
		int idx = 0;
		string str;
		int id; string name; int parentId;

		while (data[i][idx] != ' ')
			str += data[i][idx++];
		id = atoi(str.c_str());
		idx++;

		str.clear();

		while (data[i][idx] != ' ')
			str += data[i][idx++];
		name = str;
		idx++;

		str.clear();

		while(idx < data[i].size())
			str += data[i][idx++];
		parentId = atoi(str.c_str());

		Node* n = new Node(id, name, parentId);
		insert(root, n);
		list.push_back(n);
	}

	vector<Node*> searchTarget = search(word, list);
	sort(searchTarget.begin(), searchTarget.end(), compare);

	for (unsigned int i = 0; i < searchTarget.size(); i++) {
		deque<string> temp = showResult(searchTarget[i], {});
		string str;

		for (unsigned int j = 0; j < temp.size(); j++) {
			str += temp[j];

			if (j != temp.size() - 1) str += '/';
		}
		answer.push_back(str);
	}

	if (answer.empty()) {
		string str = "Your search for (" + word + ") didn't return any results";
		answer.push_back(str);
	}

	return answer;
}

int main() {
	solution({ "1 ROOTA 0" ,"4 AABAA 1", "6 AAAA 1", }, "AA");
}