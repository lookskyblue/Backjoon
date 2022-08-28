#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
#include<cmath>
using namespace std;

set<string> strSet;

void Solve()
{
	string str;
	cin >> str;

	for (int i = 0; i < str.length() ; i++)
	{
		for (int j = 0; j < str.length() && (j+i) < str.length(); j++)
		{
			strSet.insert(str.substr(j, i + 1));
		}
	}

	cout << strSet.size();
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	Solve();
}