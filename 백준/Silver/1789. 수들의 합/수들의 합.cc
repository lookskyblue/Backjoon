#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>
#include <deque>
#include <string>
#include <cstdlib>

using namespace std;

void Solve(long long n)
{
	int count = 0;
	long long sum = 0;

	for (long long i = 1; i <= n; i++)
	{
		sum += i;
		count++;

		if (sum == n)
			break;

		else if (sum > n)
		{
			count--;
			break;
		}
	}

	cout << count;
}

int main()
{
	long long n;
	cin >> n;

	Solve(n);

	return 0;
}