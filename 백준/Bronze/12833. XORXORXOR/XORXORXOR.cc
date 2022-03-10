#include <iostream>

using namespace std;

int main()
{
    int a, b, c;

    cin >> a >> b >> c;

    int tmp = a ^ b;

    int count = c % 2 == 0 ? 2 : 1;

    for (int i = 0; i < count - 1; i++)
    {
        tmp ^= b;
    }

    cout << tmp;

    return 0;
}