#include <iostream>

using namespace std;

int dp[31][31];

int GetMaxBridge(int n, int m)
{
    if (dp[n][m] != 0) return dp[n][m];
    if (n == 1) return dp[n][m] = m;
    if (n == m) return dp[n][m] = 1;

    return dp[n][m] = GetMaxBridge(n, m - 1) + GetMaxBridge(n - 1, m - 1);
}

int main()
{
    int t, n, m;

    cin >> t;

    for (int i = 0; i < t; i++)
    {
        cin >> n;
        cin >> m;

        cout << GetMaxBridge(n, m) << endl;
    }

    return 0;
}