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
	char str[1000];
	cin >> str;

	for (int i = 0; i < strlen(str); i++)
	{
		if (str[i] - 3 < 'A') str[i] = ('Z' - ('A' - (str[i] - 3) - 1));
		else str[i] = str[i] - 3;

	}

	cout << str;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	Solve();

	return 0;
}