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

char file_name[51];

void Solve()
{
	string str;
	cin >> str;

	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] != str[str.length() - 1 - i])
		{
			cout << "0";
			return;
		}
	}

	cout << "1";
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	Solve();

	return 0;
}