#include <iostream>

using namespace std;

double dp[10001];
double largest;

int main()
{
    int n;

    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> dp[i];

    largest = dp[1];

    for (int i = 2; i <= n; i++)
    {
        if (dp[i - 1] * dp[i] >= dp[i])
        {
            dp[i] = dp[i - 1] * dp[i];
        }

        largest = max(largest, dp[i]);
    }

    printf("%.3lf", largest);

    return 0;
}