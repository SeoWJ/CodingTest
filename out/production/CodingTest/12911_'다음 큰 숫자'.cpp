#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;

    int check = n;
    int oneAmount = 0;
    while (check) {
        if (check % 2 == 1) oneAmount++;
        check /= 2;
    }

    for (int i = n + 1; i <= 1000000; i++) {
        int newCheck = i;
        int newOneAmount = 0;
        
        while (newCheck) {
            if (newCheck % 2 == 1) newOneAmount++;
            newCheck /= 2;
        }

        if (oneAmount == newOneAmount) {
            answer = i;
            break;
        }
    }

    return answer;
}