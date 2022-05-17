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

bool IsPalen(string str)
{
	string tmp = str;
	reverse(str.begin(), str.end());

	return (tmp == str);
}

void Solve()
{
	string str;
	cin >> str;

	for (int i = 0; i < str.length(); i++)
	{
		if (IsPalen(str.substr(i, str.length() - i)) == true)
		{
			cout << str.length() + i;
			return;
		}
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