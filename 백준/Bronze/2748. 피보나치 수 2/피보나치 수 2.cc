#include <iostream>

using namespace std;

long long arr[90] = {0};

long long Fibo(int n)
{
    if(n == 0) return 0;
    if(n == 1) return 1;
    if(arr[n] != 0) return arr[n];
    return arr[n] = Fibo(n-2) + Fibo(n-1);
}

int main()
{
    int n;
    
    cin >> n;
    cout << Fibo(n);

    return 0;
}