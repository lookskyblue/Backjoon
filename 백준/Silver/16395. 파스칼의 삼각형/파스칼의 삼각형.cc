#include <iostream>

using namespace std;

int dp[31][31];

int Pascal(int n, int k)
{
    if (dp[n][k] != 0) return dp[n][k];
    return dp[n][k] = Pascal(n - 1, k - 1) + Pascal(n - 1, k);
}

int main()
{
    int n, k;

    cin >> n >> k;

    for (int i = 1; i <= n; i++)
    {
        dp[i][1] = dp[i][i] = 1;
    }

    cout << Pascal(n, k);

    return 0;
}