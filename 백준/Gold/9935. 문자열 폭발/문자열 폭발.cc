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
	string str, expl;
	cin >> str >> expl;

	int expl_idx = 0;
	string ans = "";

	for (int i = 0; i < str.length(); i++)
	{
		ans += str[i];

		if (ans[ans.length()-1] == expl[expl.length() - 1])
		{
			if (ans.length() < expl.length()) continue;

			int cnt = 1;

			for (int j = expl.length() - 2; j >= 0; j--)
			{
				if (expl[j] == ans[ans.length() - (expl.length()-j)]) cnt++;
				else break;
			}

			if (cnt == expl.length())
			{
				for (int j = 0; j < expl.length(); j++)
					ans.pop_back();
			}
		}
	}

	cout << (ans.size() == 0 ? "FRULA" : ans);
	return;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	Solve();

	return 0;
}