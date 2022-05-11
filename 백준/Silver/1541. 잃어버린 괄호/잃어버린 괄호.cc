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
	string str;
	cin >> str;

	int result = 0;
	string num;
	bool is_minus = false;

	for (int i = 0; i <= str.length(); i++)
	{
		if (str[i] == '+' || str[i] == '-' || i == str.length())
		{
			if (is_minus == true) result -= stoi(num);
			else result += stoi(num);

			num = "";
		}
		else num += str[i];
		if (str[i] == '-') is_minus = true;
	}

	cout << result;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	Solve();

	return 0;
}