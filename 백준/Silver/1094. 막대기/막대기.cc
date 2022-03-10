#include <iostream>

using namespace std;

int GetStickCount(int n)
{
    int count = 0;

    while (n != 0)
    {
        if (n % 2 == 1)
            count++;

        n /= 2;
    }

    return count;
}

int main()
{
    int n;

    cin >> n;

    cout << GetStickCount(n);

    return 0;
}