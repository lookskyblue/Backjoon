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

int arr[26];

void Solve()
{
	for (int i = 0; i < 26; i++)
		arr[i] = -1;

	string str;
	cin >> str;

	for (int i = 0; i < str.length(); i++)
	{
		if (arr[str[i] - 'a'] == -1)
			arr[str[i] - 'a'] = i;
	}

	for (int i = 0; i < 26; i++)
		cout << arr[i] << ' ';
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	Solve();

	return 0;
}