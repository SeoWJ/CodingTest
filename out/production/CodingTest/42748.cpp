#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;

    for (unsigned int t = 0; t < commands.size(); t++) {
        vector<int> temp;
        for (int x = commands[t][0] - 1; x <= commands[t][1] - 1; x++) {
            temp.push_back(array[x]);
        }

        sort(temp.begin(), temp.end());

        answer.push_back(temp[commands[t][2] - 1]);
    }

    return answer;
}