#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <cmath>

#define endl '\n'

using namespace std;

class Constellation {
protected:
	int N;
	vector<pair<double, double>> stars;
	priority_queue<tuple<double, int, int>, vector<tuple<double, int, int>>, greater<tuple<double, int, int>>> PQ;
	int unionHead[101];

public:
	Constellation() {
		cin >> N;

		for (int i = 0; i < 101; i++) unionHead[i] = i;

		for (int i = 0; i < N; i++) {
			double x, y;
			cin >> x >> y;

			stars.push_back({ x, y });
		}

		for (unsigned int i = 0; i < stars.size(); i++) {
			for (unsigned int j = i + 1; j < stars.size(); j++) {
				PQ.push({ getDistance(stars[i], stars[j]), i, j });
			}
		}
	}
	double getDistance(pair<int, int> s1, pair<int, int> s2) {
		double diffX = s1.first > s2.first ? s1.first - s2.first : s2.first - s1.first;
		double diffY = s1.second > s2.second ? s1.second - s2.second : s2.second - s1.second;

		double result = sqrt(pow(diffX, 2) + pow(diffY, 2));

		return result;
	}
	int getUnionHead(int star) {
		if (unionHead[star] == star) return unionHead[star];
		else return getUnionHead(unionHead[star]);
	}
	void setUnionHead(int star, int setValue) {
		int prevUnionHead = getUnionHead(star);

		unionHead[prevUnionHead] = setValue;
	}
	double kruskal() {
		double totalDistance = 0;

		while (!PQ.empty()) {
			double dist = get<0>(PQ.top());
			int node1 = get<1>(PQ.top());
			int node2 = get<2>(PQ.top());

			PQ.pop();

			int unionHead1 = getUnionHead(node1);
			int unionHead2 = getUnionHead(node2);

			if (unionHead1 == unionHead2)
				continue;
			else {
				totalDistance += dist;

				if (unionHead1 < unionHead2)
					setUnionHead(unionHead2, unionHead1);
				else
					setUnionHead(unionHead1, unionHead2);
			}
		}

		return totalDistance;
	}
	void solution() {
		cout << kruskal() << endl;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cout << fixed;
	cout.precision(2);

	Constellation* c = new Constellation();
	c->solution();

	delete c;

	return 0;
}