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

char alpha[5][15];

void Solve()
{
	for (int j = 0; j < 15; j++)
	{
		for (int i = 0; i < 5; i++)
		{
			if (alpha[i][j] != 0)
				cout << alpha[i][j];
		}
	}
}

void Input()
{
	for (int i = 0; i < 5; i++)
	{
		string str;
		cin >> str;

		strcpy(alpha[i], str.c_str());
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	Input();
	Solve();

	return 0;
}