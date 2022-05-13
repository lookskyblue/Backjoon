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
	string str;
	cin >> str;

	char before = str[0];
	int cnt = 0;

	for (int i = 1; i < str.length(); i++)
	{
		if (before != str[i])
		{
			cnt++;
			int now = str[i];
			while (i < str.length() && now == str[i])
				i++;
		}
	}

	cout << cnt;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	Solve();

	return 0;
}