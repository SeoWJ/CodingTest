#include <string>
#include <vector>

using namespace std;

string DFS(string p);
bool isCorrect(string p);

string solution(string p) {
    string answer = "";

    answer = DFS(p);

    return answer;
}

string DFS(string p) {
    if (p.empty()) return p;

    int open = 0, close = 0;
    string u, v;

    for (unsigned int i = 0; i < p.size(); i++) {
        if (p[i] == '(') open++;
        else close++;

        u += p[i];

        p.erase(p.begin() + i--);

        if (open > 0 && close > 0 && open == close)
            break;
    }
    v = p;

    if (isCorrect(u) == true) return u + DFS(v);
    else {
        string result = "(";
        result += DFS(v);
        result += ")";
        u.erase(u.begin());
        u.erase(u.begin() + u.size() - 1);
        for (unsigned int i = 0; i < u.size(); i++) {
            if (u[i] == '(') u[i] = ')';
            else u[i] = '(';
        }
        result += u;

        return result;
    }
}

bool isCorrect(string p) {
    int open = 0, close = 0;

    for (unsigned int i = 0; i < p.size(); i++) {
        if (p[i] == '(') open++;
        else close++;

        if (open < close) return false;
    }

    return true;
}