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
	bool is_white = true;
	int ans = 0;

	for (int i = 0; i < 8; i++)
	{
		string str;
		cin >> str;

		for (int i = 0; i < str.length(); i++)
		{
			if (is_white == true && str[i] == 'F') ans++;
			is_white = !is_white;
		}
		
		is_white = !is_white;
	}

	cout << ans;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	Solve();

	return 0;
}