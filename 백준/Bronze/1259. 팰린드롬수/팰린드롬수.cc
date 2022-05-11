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

void Solve()
{
	while (true)
	{
		string str;
		cin >> str;

		if (str == "0") break;

		string str_rev = str;
		reverse(str_rev.begin(), str_rev.end());

		if (str_rev == str)
			cout << "yes" << '\n';
		else
			cout << "no" << '\n';
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