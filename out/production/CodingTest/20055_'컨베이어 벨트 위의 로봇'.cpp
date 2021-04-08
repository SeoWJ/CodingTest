#include <iostream>
#include <vector>
#include <queue>

#define endl '\n'

using namespace std;

class Conveyor {
protected:
	int N, K;
	deque<int> belt;
	deque<int> robotPosition;
	int breakPoint;
	int count;

public:
	Conveyor(int n, int k) {
		N = n; K = k;
		breakPoint = 0;
		count = 0;

		belt.assign(2 * N, 0);
		robotPosition.assign(2 * N, 0);


		for (int i = 0; i < 2 * N; i++) cin >> belt[i];
	}
	void shift(deque<int>& target) {
		target.push_front(target[2 * N - 1]);
		target.pop_back();
	}
	void robotMove() {
		if (robotPosition[N - 1] == 1)
			robotPosition[N - 1] = 0;

		for (int i = 2 * N - 1; i >= 1; i--) {
			if (belt[i] > 0 && robotPosition[i] == 0 && robotPosition[i - 1] == 1) {
				robotPosition[i] = 1;
				robotPosition[i - 1] = 0;
				belt[i]--;
			}
		}

		if (robotPosition[N - 1] == 1)
			robotPosition[N - 1] = 0;
	}
	void putRobot() {
		if (robotPosition[0] == 0 && belt[0] > 0) {
			belt[0]--;
			robotPosition[0] = 1;
		}
	}
	bool checkEnd() {
		int destroyed = 0;

		for (int i = 0; i < 2 * N; i++) {
			if (belt[i] == 0) destroyed++;
		}

		if (destroyed >= K) return true;
		else return false;
	}
	void showConveyor() {
		for (int i = 0; i < N; i++) {
			if (robotPosition[i] == 1) cout << "R" << '\t';
			else cout << " " << '\t';
		}
		cout << endl;

		for (int i = 0; i < 2 * N; i++) {
			cout << belt[i] << '\t';
		}
		cout << endl << endl;
	}
	void solution() {
		while (1) {
			count++;

			shift(belt);
			shift(robotPosition);

			robotMove();

			putRobot();
			
			if (checkEnd()) break;
		}

		cout << count << endl;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, K; cin >> N >> K;
	
	Conveyor c(N, K);
	c.solution();

	return 0;
}