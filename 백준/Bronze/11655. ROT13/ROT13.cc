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
	getline(cin, str);

	for (int i = 0; i < str.length(); i++)
	{
		if ('a' <= str[i] && str[i] <= 'z')
		{
			int alpha = str[i] + 13;
			cout << char((alpha > 'z') ? (97 + alpha % 123) : alpha);
		}

		else if ('A' <= str[i] && str[i] <= 'Z')
		{
			int alpha = str[i] + 13;
			cout << char((alpha > 'Z') ? (65 + alpha % 91) : alpha);
		}

		else
			cout << str[i];
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