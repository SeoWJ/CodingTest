#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool visit[1001][1001];

vector<int> solution(vector<int> enter, vector<int> leave) {
    vector<int> answer;

    for (int y = 0; y < 1001; y++) {
        for (int x = 0; x < 1001; x++) visit[y][x] = false;
    }

    vector<int> peopleEnter(enter.size() + 1);
    vector<int> peopleLeave(leave.size() + 1);

    for (int i = 0; i < enter.size(); i++) {
        peopleEnter[enter[i]] = i + 1;
        peopleLeave[leave[i]] = i + 1;
    }

    for (int i = 1; i < peopleEnter.size(); i++) {
        for (int j = 1; j < peopleEnter.size(); j++) {
            if (i == j) continue;
            if (peopleEnter[i] < peopleEnter[j] && peopleLeave[j] < peopleLeave[i])
                visit[i][j] = visit[j][i] = true;
        }
    }

    for (int mid = 1; mid < peopleEnter.size(); mid++) {
        for (int start = 1; start < peopleEnter.size(); start++) {
            for (int destination = 1; destination < peopleEnter.size(); destination++) {
                if (peopleEnter[start] < peopleEnter[mid] && peopleEnter[mid] < peopleEnter[destination] && peopleLeave[destination] < peopleLeave[mid])
                    visit[start][mid] = visit[mid][start] = true;
            }
        }
    }

    for (int y = 1; y < peopleEnter.size(); y++) {
        int meet = 0;
        for (int x = 1; x < peopleEnter.size(); x++) {
            if (y == x) continue;
            if (visit[y][x] == true) meet++;
        }
        answer.push_back(meet);
    }

    return answer;
}

int main() {
    solution({ 1,3,2 }, { 1,2,3 });
}