#include <iostream>
#include <vector>
#include <cstring>

#define endl '\n'
#define MAX_VALUE 1000000007

using namespace std;

enum Building {
	JUNGBO,
	JUNSAN,
	MIRAE,
	SINYANG,
	HANKYUNGJIK,
	JINRI,
	HYUNGNAM,
	HAKSANG
};

class SungsilUniv {
protected:
	vector<vector<int>> Edges = {
		{JUNSAN, MIRAE},
		{JUNGBO, MIRAE, SINYANG},
		{JUNGBO, JUNSAN, SINYANG, HANKYUNGJIK},
		{JUNSAN, MIRAE, HANKYUNGJIK, JINRI },
		{MIRAE, SINYANG, JINRI, HYUNGNAM},
		{SINYANG, HANKYUNGJIK, HAKSANG},
		{HANKYUNGJIK, HAKSANG},
		{JINRI, HYUNGNAM}
	};
	vector<long long> Nodes;
	int time;
	int D;

public:
	SungsilUniv(int d) {
		D = d; time = 0;
		Nodes = { 1,0,0,0,0,0,0,0 };
	}
	void timeFlow() {
		vector<long long> next(8);

		for (int i = 0; i < 8; i++) {
			for (auto e : Edges[i])
				next[i] = (next[i] + Nodes[e]) % MAX_VALUE;
		}

		Nodes = next;
	}
	void solution() {
		while (time < D) {
			time++;
			timeFlow();
		}

		cout << Nodes[JUNGBO] << endl;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int D; cin >> D;

	SungsilUniv* s = new SungsilUniv(D);
	s->solution();

	delete s;

	return 0;
}