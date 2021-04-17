#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int answer = 1;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == answer)
                answer++;
        }

        return answer;
    }
};