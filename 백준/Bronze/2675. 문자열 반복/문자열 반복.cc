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

int T;

void Solve()
{
	cin >> T;

	while (T--)
	{
		int R;
		string S;

		cin >> R >> S;

		for (int i = 0; i < S.length(); i++)
		{
			for (int j = 0; j < R; j++)
			{
				cout << S[i];
			}
		}

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