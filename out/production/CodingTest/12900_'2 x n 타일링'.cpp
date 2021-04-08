#include <string>
#include <vector>

#define MOD 1000000007

using namespace std;

int dp[60001];

int solution(int n) {
    int answer = 0;

    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    dp[4] = 5;
    
    for (int i = 5; i <= n; i++) {
        dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
    }

    answer = dp[n];

    return answer;
}