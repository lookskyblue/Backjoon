#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>

using namespace std;

int dp[5001];

int Sugar2(int n)
{
    dp[3] = dp[5] = 1;

    for (int i = 6; i <= n; i++)
    {
        if (dp[i - 3]) dp[i] = dp[i - 3] + 1;
        if (dp[i - 5]) dp[i] = dp[i] ? min(dp[i], dp[i - 5] + 1) : dp[i - 5] + 1;
    }

    return dp[n] == 0 ? -1 : dp[n];
}

int main()
{
    int n;

    cin >> n;
    cout << Sugar2(n);

    return 0;
}