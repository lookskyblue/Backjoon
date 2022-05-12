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

	stack<int> oct;

	for (int i = str.size() - 1; i >= 0; i--)
	{
		int digit = str[i] - '0';

		int push_cnt = 0;

		while (digit != 0)
		{
			oct.push(digit % 2);
			digit /= 2;
			push_cnt++;
		}

		for (; push_cnt < 3; push_cnt++)
			oct.push(0);
	}

	bool is_first_zero = true;

	while (oct.empty() == false)
	{
		if (oct.size() != 1 && oct.top() == 1) is_first_zero = false;
		if (oct.size() != 1 && oct.top() == 0 && is_first_zero == true)
		{
			oct.pop();
			continue;
		}

		cout << oct.top();
		oct.pop();
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