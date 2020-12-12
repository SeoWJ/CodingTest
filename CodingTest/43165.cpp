#include <string>
#include <vector>
#include <iostream>

using namespace std;

int answer = 0;

void DFS(vector<int> numbers, int now, int position, int target);

int solution(vector<int> numbers, int target) {
    DFS(numbers, 0, 0, target);

    return answer;
}

void DFS(vector<int> numbers, int now, int position, int target) {
    if (position == numbers.size()) {
        if (now == target) {
            answer++;
            return;
        }
        else
            return;
    }

    DFS(numbers, now + numbers[position], position + 1, target);
    DFS(numbers, now - numbers[position], position + 1, target);
}

int main() {
    vector<int> numbers;

    numbers.push_back(1);
    numbers.push_back(1);
    numbers.push_back(1);
    numbers.push_back(1);
    numbers.push_back(1);

    cout << solution(numbers, 3) << endl;
}