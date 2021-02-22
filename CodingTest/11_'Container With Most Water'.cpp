#include <iostream>
#include <vector>
#include <queue>

#define LOWER_HEIGHT(a,b) (a < b ? a : b)
#define WIDTH(a,b) (a > b ? (a - b) : (b - a))

using namespace std;

typedef pair<int, int> Line;		//height, position

class Solution {
public:
	int max(vector<int> v) {
		int result = 0;
		for (unsigned int i = 0; i < v.size(); i++) {
			result = result > v[i] ? result : v[i];
		}
		return result;
	}
	int maxArea(vector<int>& height) {
		/*priority_queue<Line, vector<Line>, less<Line>> PQ;

		for (unsigned int i = 0; i < height.size(); i++)
			PQ.push({ height[i], i });

		Line left = PQ.top(); PQ.pop();
		Line right = PQ.top(); PQ.pop();
		if (left.second > right.second) {
			Line temp = left;
			left = right;
			right = temp;
		}

		while (!PQ.empty()) {
			Line currentLine = PQ.top();
			PQ.pop();

			int beforeWater = LOWER_HEIGHT(left.first, right.first) * WIDTH(left.second, right.second);
			int newWater;

			if (currentLine.second < left.second) {
				newWater = LOWER_HEIGHT(currentLine.first, right.first) * WIDTH(currentLine.second, right.second);
				
				if (beforeWater < newWater) 
					left = currentLine;
			}
			else if (left.second < currentLine.second && currentLine.second < right.second) {
				int newWaterLeft = LOWER_HEIGHT(left.first, currentLine.first) * WIDTH(left.second, currentLine.second);
				int newWaterRight = LOWER_HEIGHT(currentLine.first, right.first) * WIDTH(currentLine.second, right.second);

				if (beforeWater < newWaterLeft) right = currentLine;
				if (beforeWater < newWaterRight) left = currentLine;
			}
			else {	// right.second < currentLine.second
				newWater = LOWER_HEIGHT(currentLine.first, left.first) * WIDTH(currentLine.second, left.second);

				if (beforeWater < newWater)
					right = currentLine;
			}
		}

		return LOWER_HEIGHT(left.first, right.first) * WIDTH(left.second, right.second);*/

		int left = 0, right = height.size() - 1;
		int answer = 0;

		while (left < right) {
			int water = LOWER_HEIGHT(height[left], height[right]) * WIDTH(left, right);
			answer = answer > water ? answer : water;

			if (height[left] < height[right])
				left++;
			else
				right--;
		}

		return answer;
	}
};

int main() { vector<int> v = { 2,3,10,5,7,8,9 }; cout << Solution().maxArea(v) << endl; }