#include <iostream>
#include <queue>
#include <algorithm>

#define endl '\n'

using namespace std;

struct Conference {
	int start;
	int end;
};

int N;
deque<Conference> conferences;

bool compare(Conference c1, Conference c2);

int main(int argc, char* argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++) {
		int start, end;
		cin >> start >> end;

		Conference c = { start, end };
		conferences.push_back(c);
	}

	sort(conferences.begin(), conferences.end(), compare);

	int count = 0;
	int final_end = -1;

	while (!conferences.empty()) {
		Conference c = conferences.front();
		conferences.pop_front();

		if (final_end <= c.start) {
			count++;
			final_end = c.end;
		}
	}

	cout << count << endl;

	return 0;
}

bool compare(Conference c1, Conference c2) {
	if (c1.end != c2.end) return c1.end < c2.end;
	else return c1.start < c2.start;
}