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
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		string str;
		cin >> str;

		for (int i = 0; i < str.length(); i++)
		{
			if (file_name[i] == 0) file_name[i] = str[i];
			if (file_name[i] != str[i]) file_name[i] = '?';
		}
	}

	cout << file_name;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	Solve();

	return 0;
}