#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

#define PRIME_MAX 1000001
int N;
int arr[PRIME_MAX];
vector<int> prime;

void Solve(long long x)
{
	int ans = true;

	for (int i = 0; i < prime.size(); i++)
	{
		if (x % prime[i] == 0)
		{
			ans = false;
			break;
		}
	}

	if (ans == true) cout << "YES\n";
	else cout << "NO\n";
}

void Input()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		long long x;
		cin >> x;
		Solve(x);
	}
}

void Era()
{
	for (int i = 2; i < PRIME_MAX; i++)
		arr[i] = 1;

	for (int i = 2; i < PRIME_MAX / 2; i++)
	{
		for (int j = 2; j * i < PRIME_MAX; j++)
		{
			if (arr[i * j] == 1)
				arr[i * j] = 0;
		}
	}

	for (int i = 2; i < PRIME_MAX; i++)
		if (arr[i] == 1)
			prime.push_back(i);
}

int main()
{
	ios_base::sync_with_stdio(0); 
	cin.tie(0);

	Era();
	Input();

	return 0;
}