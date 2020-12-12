#include <iostream>
#include <vector>

#define endl "\n"

using namespace std;

struct computer {
	bool infected = false;
	vector<int> connect;
};

computer* arr[101] = { NULL };

void operation();
void dfs(computer* c);

int main(int argc, char* argv[]) {
	ios::sync_with_stdio(false);

	operation();

	return 0;
}

void operation() {
	int n, m; cin >> n >> m;

	for (int loop1 = 1; loop1 <= n; loop1++)
		arr[loop1] = new computer;

	for (int loop1 = 0; loop1 < m; loop1++) {
		int input1, input2; cin >> input1 >> input2;
		arr[input1]->connect.push_back(input2);
		arr[input2]->connect.push_back(input1);
	}

	arr[1]->infected = true;

	dfs(arr[1]);

	int count = 0;
	for (int loop1 = 1; loop1 <= n; loop1++) {
		if (arr[loop1]->infected == true)
			count++;
	}

	cout << count - 1 << endl;
}

void dfs(computer* c) {
	for (unsigned int loop1 = 0; loop1 < c->connect.size(); loop1++) {
		if (arr[c->connect[loop1]]->infected == false) {
			arr[c->connect[loop1]]->infected = true;
			dfs(arr[c->connect[loop1]]);
		}
	}
}