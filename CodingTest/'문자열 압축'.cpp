#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(string s) {
    int answer = 0x7FFFFFFF;

    if (s.size() == 1)
        return 1;

    queue<string> Q;

    for (int length = s.size() / 2; length > 0; length--) {
        string str = "";
        string newString = "";
        for (unsigned int i = 0; i < s.size(); i++) {
            str += s[i];

            if (str.size() == length) {
                Q.push(str);
                str.clear();
            }
        }
        if (!str.empty()) Q.push(str);

        int loopCount = 1;
        string pattern = Q.front();
        Q.pop();

        while (!Q.empty()) {
            string current = Q.front();
            Q.pop();

            if (current == pattern)
                loopCount++;
            else {
                if (loopCount >= 2)
                    newString += to_string(loopCount);
                newString += pattern;

                loopCount = 1;
                pattern = current;
            }
        }
        if (loopCount >= 2)
            newString += to_string(loopCount);
        newString += pattern;

        answer = answer < newString.size() ? answer : newString.size();
    }

    return answer;
}