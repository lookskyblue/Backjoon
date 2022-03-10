#include <iostream>

using namespace std;

long long dp[81];

long long PrintRound(int tile_count)
{
    if (tile_count == 1) return 4;

    dp[1] = dp[2] = 1;

    for (int i = 3; i <= tile_count; i++)
        dp[i] = dp[i - 2] + dp[i - 1];

    return ((dp[tile_count] + dp[tile_count - 1]) * 2) + dp[tile_count] * 2;
}

int main()
{
    int n;
    cin >> n;
    cout << PrintRound(n);

    return 0;
}