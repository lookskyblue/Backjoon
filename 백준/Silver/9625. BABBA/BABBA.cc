#include <iostream>

using namespace std;

int dp_a[46];
int dp_b[46];

void BABBA(int n)
{
    dp_b[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        dp_a[i] = dp_b[i - 1];
        dp_b[i] = dp_a[i - 1] + dp_b[i - 1];
    }

    cout << dp_a[n] << " " << dp_b[n];
}

int main()
{
    int n;

    cin >> n;

    BABBA(n);

    return 0;
}