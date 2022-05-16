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
	string str, finder;
	getline(cin, str);
	getline(cin, finder);

	int cnt = 0;

	for (int i = 0; i < str.length(); i++)
	{
		bool flag = true;

		for (int j = 0; j < finder.length(); j++)
		{
			if (i + j >= str.length() || str[i + j] != finder[j])
				flag = false;
		}

		if (flag == true)
		{
			cnt++;
			i += finder.length() - 1;
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