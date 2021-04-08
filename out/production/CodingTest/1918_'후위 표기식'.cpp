#include <iostream>
#include <string>
#include <queue>
#include <stack>

#define endl '\n'
#define isAlphabet(a) ('A' <= a && a <= 'Z')

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string formula; cin >> formula;

	stack<char> S;
	string result = "";

	for (unsigned int i = 0; i < formula.size(); i++) {
		if (isAlphabet(formula[i])) result += formula[i];
		else {
			if (formula[i] == '(') S.push(formula[i]);
			else if (formula[i] == '*' || formula[i] == '/') {
				while (!S.empty() && (S.top() == '*' || S.top() == '/')) {
					result += S.top(); 
					S.pop();
				}
				S.push(formula[i]);
			}
			else if (formula[i] == '+' || formula[i] == '-') {
				while (!S.empty() && S.top() != '(') {
					result += S.top();
					S.pop();
				}
				S.push(formula[i]);
			}
			else { // formula[i] == ')'
				while (!S.empty() && S.top() != '(') {
					result += S.top();
					S.pop();
				}
				S.pop();
			}
		}
	}

	while (!S.empty()) {
		result += S.top(); 
		S.pop();
	}

	cout << result << endl;

	return 0;
}