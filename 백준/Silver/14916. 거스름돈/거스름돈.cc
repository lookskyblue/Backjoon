#include <iostream>

using namespace std;

int dp[100001];

int GetLeftMoney(int n)
{
    dp[5] = dp[2] = 1;
    dp[4] = 2;

    for (int i = 6; i <= n; i++)
    {
        if (dp[i - 5]) dp[i] = dp[i - 5] + 1;
        if (dp[i - 2]) dp[i] = (dp[i - 5] == 0 ? dp[i - 2] : min(dp[i - 5], dp[i - 2])) + 1;
    }

    return dp[n] == 0 ? -1 : dp[n];
}

int main()
{
    int n;

    cin >> n;
    cout << GetLeftMoney(n);
    
    return 0;
}