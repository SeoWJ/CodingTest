#include <string>
#include <vector>
#include <queue>

using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;

    priority_queue<int, vector<int>, less<int>> PQ;

    for (unsigned int i = 0; i < works.size(); i++)
        PQ.push(works[i]);

    while (1) {
        if (PQ.top() == 0) return 0;
        if (n == 0) break;

        int max = PQ.top();
        PQ.pop();
        max--;
        PQ.push(max);
        n--;
    }

    while (!PQ.empty()) {
        int temp = PQ.top();
        answer += temp * temp;
        PQ.pop();
    }

    return answer;
}