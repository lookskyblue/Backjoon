#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
#include<cmath>
using namespace std;

bool selfNumArr[10001];

void SetSelfNum(int num)
{
	int sum = num;

	while (num != 0)
	{
		sum += num % 10;
		num = num / 10;
	}
	
	if (sum > 10000) return;
	if (selfNumArr[sum] == true) return;

	selfNumArr[sum] = true;
	SetSelfNum(sum);
}

void Solve()
{
	for (int i = 1; i <= 10000; i++)
	{
		SetSelfNum(i);
	}


	for (int i = 1; i <= 10000; i++)
	{
		if (selfNumArr[i] == false)
		{
			cout << i << '\n';
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	Solve();
}