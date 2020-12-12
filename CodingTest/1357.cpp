#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int Rev(int num)

{

    vector<int> v;

    while (num)

    {

        v.push_back(num % 10);

        num /= 10;

    }



    int result = 0;

    for (int i = 0; i < v.size(); i++)

        result += v[i] * pow(10, (v.size() - 1 - i));

    return result;

}


int main(void)

{

    int X, Y;

    cin >> X >> Y;



    cout << Rev(Rev(X) + Rev(Y)) << "\n";

    return 0;

}