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

using namespace std;

void Solve()
{
	string str;
	cin >> str;

	stack<int> bin;

	for (int i = str.size() - 1; i >= 0; i--)
	{
		int digit = str[i] - '0';
		int push_cnt = 0;

		while (digit != 0)
		{
			bin.push(digit % 2);
			digit /= 2;
			push_cnt++;
		}

		for (; push_cnt < 3; push_cnt++) bin.push(0);
	}

	while (bin.size() != 1 && bin.empty() == false && bin.top() == 0) bin.pop();
	while (bin.empty() == false)
	{
		cout << bin.top();
		bin.pop();
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	Solve();

	return 0;
}