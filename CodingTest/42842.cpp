#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;

    if (yellow == 1) {
        answer.push_back(3);
        answer.push_back(3);
        return answer;
    }

    for (int height = 1; height <= sqrt(yellow); height++) {
        if (yellow % height == 0) {
            int width = yellow / height;
            
            if (((width + 2) * 2) + (height * 2) == brown) {
                answer.push_back(width + 2);
                answer.push_back(height + 2);
                break;
            }
        }
    }

    return answer;
}