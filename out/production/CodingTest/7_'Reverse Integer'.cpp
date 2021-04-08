#include <iostream>

using namespace std;

class Solution {
public:
	int reverse(int x) {
		const int LOWER_BOUND = 0x80000000;
		const int UPPER_BOUND = 0x7FFFFFFF;
		int result = 0;

		while (1) {
			if (x > 0 && result > UPPER_BOUND / 10) return 0;
			if (x < 0 && result < LOWER_BOUND / 10) return 0;
			result *= 10;
			int pushNum = x % 10;
			x /= 10;

			result += pushNum;

			if (x == 0) break;
		}

		return result;
	}
};