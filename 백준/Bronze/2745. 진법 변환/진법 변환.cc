#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <vector>
#include <map>
#include <string>
#include <cstring>

using namespace std;

void Solve()
{
	string N;
	int B;
	cin >> N >> B;

	int sum = 0;

	for (int i = N.size() - 1; i >= 0; i--)
	{
		// B를 승해줘야함.
		int q = 1;
		for (int j = 0; j < (N.size() - 1) - i; j++)
		{
			q *= B;
		}

		int notation = 0;

		if ('A' <= N[i]) notation = 10 + (N[i] - 'A');
		else notation = N[i] - '0';

		sum += notation * q;
	}

	cout << sum;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	Solve();

	return 0;
}