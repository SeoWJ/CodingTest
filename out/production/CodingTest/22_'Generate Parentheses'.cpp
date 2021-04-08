#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> answer;

    void DFS(string str, int open, int close, int n) {
        if (open == close && open == n) {
            answer.push_back(str);
            return;
        }

        if (open < n) {
            str += "(";
            DFS(str, open + 1, close, n);
            str.pop_back();
        }
        if (close < open) {
            str += ")";
            DFS(str, open, close + 1, n);
            str.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        DFS("(", 1, 0, n);

        return answer;
    }
};