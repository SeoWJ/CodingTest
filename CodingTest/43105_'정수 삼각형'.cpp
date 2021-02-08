#include <string>
#include <vector>

#define max(a, b) a > b ? a : b

using namespace std;

int solution(vector<vector<int>> triangle) {
    if (triangle.size() == 1) return triangle[0][0];

    for (int height = triangle.size() - 2; height >= 0; height--) {
        for (unsigned int i = 0; i < triangle[height].size(); i++) {
            int left = triangle[height][i] + triangle[height + 1][i];
            int right = triangle[height][i] + triangle[height + 1][i + 1];

            triangle[height][i] = max(left, right);
        }
    }

    return triangle[0][0];
}