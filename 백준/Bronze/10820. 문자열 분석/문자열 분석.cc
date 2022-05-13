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
	while (getline(cin, str))
	{
		int cnt[4] = { 0, };

		for (int i = 0; i < str.length(); i++)
		{
			if ('a' <= str[i] && str[i] <= 'z') cnt[0]++;
			else if ('A' <= str[i] && str[i] <= 'Z') cnt[1]++;
			else if ('0' <= str[i] && str[i] <= '9') cnt[2]++;
			else cnt[3]++;
		}

		for (int i = 0; i < 4; i++)
			cout << cnt[i] << ' ';

		cout << '\n';
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