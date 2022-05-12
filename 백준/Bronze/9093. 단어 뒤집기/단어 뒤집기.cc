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

void ReversePrint(string str)
{
	char str_c[1001];
	strcpy(str_c, str.c_str());
	
	char* tmp = strtok(str_c, " ");
	while (tmp != NULL)
	{
		for (int i = strlen(tmp) - 1; i >= 0; i--)
			cout << tmp[i];

		cout << " ";

		tmp = strtok(NULL, " ");
	}

	cout << '\n';
}

void Solve()
{
	string T;
	getline(cin, T);
	int t = stoi(T);

	while (t--)
	{
		string str;
		getline(cin, str);

		ReversePrint(str);
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