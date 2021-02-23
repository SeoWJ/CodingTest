#include <iostream>
#include <stack>
#include <queue>

#define endl '\n'

using namespace std;

int main(int argc, char* argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string original, explosive;
	cin >> original >> explosive;

	deque<char> bomb;
	for (unsigned int i = 0; i < explosive.size(); i++)
		bomb.push_back(explosive[i]);

	stack<char> S;

	for (unsigned int i = 0; i < original.size(); i++) {
		if (original[i] == explosive[explosive.size() - 1]) {
			deque<char> str;
			str.push_front(original[i]);

			for (unsigned int i = 0; i < bomb.size() - 1; i++) {
				if (!S.empty()) {
					str.push_front(S.top());
					S.pop();
				}
				else
					break;
			}

			if (str == bomb)
				continue;
			else {
				for (unsigned int i = 0; i < str.size(); i++)
					S.push(str[i]);
			}
		}
		else
			S.push(original[i]);
	}

	deque<char> result;
	unsigned int limit = S.size();
	for (unsigned int i = 0; i < limit; i++) {
		result.push_front(S.top());
		S.pop();
	}

	if (result.empty())
		cout << "FRULA" << endl;
	else {
		for (unsigned int i = 0; i < result.size(); i++)
			cout << result[i];
		cout << endl;
	}

	return 0;
}