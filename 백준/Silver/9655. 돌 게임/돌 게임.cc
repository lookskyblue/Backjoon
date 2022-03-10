#include <iostream>

using namespace std;

string GameResult(int n)
{
    return n % 2 == 0 ? "CY" : "SK";
}

int main()
{
    int n;

    cin >> n;
    cout << GameResult(n);

    return 0;
}