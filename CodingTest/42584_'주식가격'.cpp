#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

struct Stock {
    int price;
    int time;

    Stock(int p, int t) {
        price = p;
        time = t;
    }
};

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    answer.assign(prices.size(), 0);

    int sec = 0;
    stack<Stock> S;

    S.push(Stock(prices[0], 0));

    for (unsigned int i = 1; i < prices.size(); i++) {
        sec++;

        while (!S.empty() && S.top().price > prices[i]) {
            Stock currentStock = S.top();
            S.pop();

            answer[currentStock.time] = sec - currentStock.time;
        }

        S.push(Stock(prices[i], sec));
    }

    while (!S.empty()) {
        Stock currentStock = S.top();
        S.pop();

        answer[currentStock.time] = sec - currentStock.time;
    }

    return answer;
}

int main() {
    vector<int> v = solution({ 1,2,3,2,3 });
}