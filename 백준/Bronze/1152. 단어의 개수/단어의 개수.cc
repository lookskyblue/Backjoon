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

int cnt;

void Solve()
{
	string str;
	getline(cin, str);

	char ch[1000000];
	strcpy(ch, str.c_str());

	char* tmp = strtok(ch, " ");

	int cnt = 0;

	while (tmp != NULL)
	{
		tmp = strtok(NULL, " ");
		cnt++;
	}

	cout << cnt;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	Solve();

	return 0;
}