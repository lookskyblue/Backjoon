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
	int N;
	string str;
	cin >> N >> str;

	int holer_cnt = 1;
	int l_cnt = 0;

	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == 'S')
			holer_cnt++;
		else
		{
			l_cnt++;
			if (l_cnt == 2)
			{
				holer_cnt++;
				l_cnt = 0;
			}
		}
	}

	cout << (min(holer_cnt, (int)str.length()));
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	Solve();

	return 0;
}