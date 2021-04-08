#include <iostream>
#include <cstring>
#include <list>
#include <algorithm>

#define endl '\n'

using namespace std;

void operation();
bool compare(string s1, string s2);

int main(int argc, char* argv[]) {
	operation();

	return 0;
}

void operation() {
	int N; cin >> N;
	list<string> word;

	for (int loop1 = 0; loop1 < N; loop1++) {
		string input;
		cin >> input;

		word.push_back(input);
	}

	word.sort(compare);

	list<string>::iterator iter = word.begin();

	while (iter != word.end()) {
		if (iter != word.begin()) {
			list<string>::iterator temp_iter = iter;
			temp_iter--;

			if (*temp_iter == *iter)
				iter++;
			else {
				cout << *iter << endl;
				iter++;
			}
		}
		else {
			cout << *iter << endl;
			iter++;
		}
	}
}

bool compare(string s1, string s2) {
	if (s1 == s2)
		return false;

	if (strlen(s1.c_str()) < strlen(s2.c_str()))
		return true;

	else if (strlen(s1.c_str()) > strlen(s2.c_str()))
		return false;

	else { // 길이 동일
		char c1, c2;
		for (unsigned int loop1 = 0; loop1 < strlen(s1.c_str()); loop1++) {
			c1 = s1[loop1];
			c2 = s2[loop1];

			if (c1 == c2)
				continue;
			else if (c1 < c2)
				return true;
			else
				return false;
		}
	}
}