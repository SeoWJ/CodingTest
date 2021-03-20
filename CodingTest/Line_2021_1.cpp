#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool compare(pair<int, string> p1, pair<int, string> p2) {
    if (p1.first != p2.first) return p1.first > p2.first;
    else
        return p1.second < p2.second;
}

string solution(vector<string> table, vector<string> languages, vector<int> preference) {
    string answer = "";
    vector<pair<int, string>> answerTable;
    vector<vector<string>> Table;

    for (unsigned int y = 0; y < table.size(); y++) {
        vector<string> row;
        string str = "";
        for (unsigned int x = 0; x < table[y].size(); x++) {
            if (table[y][x] == ' ') {
                row.push_back(str);
                str.clear();
            }
            else if (x == table[y].size() - 1) {
                str.push_back(table[y][x]);
                row.push_back(str);
            }
            else
                str.push_back(table[y][x]);
        }
        Table.push_back(row);
    }

    for (unsigned int y = 0; y < Table.size(); y++) {
        pair<int, string> jobScore;
        int totalScore = 0;

        for (unsigned int x = 1; x < Table[y].size(); x++) {
            int score = 6 - x;

            for (unsigned int i = 0; i < preference.size(); i++) {
                if (languages[i] == Table[y][x])
                    totalScore += (score * preference[i]);
            }
        }

        jobScore = { totalScore, Table[y][0] };
        answerTable.push_back(jobScore);
    }

    sort(answerTable.begin(), answerTable.end(), compare);

    answer = answerTable[0].second;

    return answer;
}

int main() {
    solution({ "SI JAVA JAVASCRIPT SQL PYTHON C#", "CONTENTS JAVASCRIPT JAVA PYTHON SQL C++", "HARDWARE C C++ PYTHON JAVA JAVASCRIPT", "PORTAL JAVA JAVASCRIPT PYTHON KOTLIN PHP", "GAME C++ C# JAVASCRIPT C JAVA" },
        { "JAVA", "JAVASCRIPT" },
        { 7, 5 });
}