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
			int cnt = 1;
			int ans_cnt = ans.length() - 2;

			for (int j = expl.length() - 2; j >= 0; j--)
			{
				if (ans_cnt >= 0 && expl[j] == ans[ans_cnt])
				{
					cnt++;
					ans_cnt--;
				}

				else
					break;
			}

			if (cnt == expl.length())
			{
				for (int j = 0; j < expl.length(); j++)
					ans.pop_back();
			}
		}
	}


	int expl_len = expl.length();
	size_t pos = ans.find(expl);

	while (pos != string::npos)
	{
		ans.erase(pos, expl_len);
		pos = ans.find(expl);
	}

	cout << (ans.size() == 0 ? "FRULA" : ans);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	Solve();

	return 0;
}