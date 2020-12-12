#include <iostream>
#include <string>

#define endl "\n"

using namespace std;

void operation();

int main(int argc, char* argv[]) {
	ios::sync_with_stdio(false);
	cin.tie();

	operation();

	return 0;
}

void operation() {
	char input[100002] = { NULL };
	cin >> input;

	int current_stick = 0;
	int sliced_stick = 0;

	for (int loop1 = 0; input[loop1] != NULL; loop1++) {
		if (input[loop1] == '(') {
			if (input[loop1 + 1] == ')') {
				sliced_stick += current_stick;
				loop1++;
			}
			else
				current_stick++;
		}
		else {
			sliced_stick++;
			current_stick--;
		}
	}

	cout << sliced_stick << endl;
}