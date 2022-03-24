#include <iostream>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <string>

using namespace std;

string IsBalanceStr(string str)
{
	stack<char> s;

	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == '.') return s.empty() == true ? "yes" : "no";

		else if (str[i] == '(' || str[i] == '[') s.push(str[i]);

		else if (str[i] == ')')
		{
			if (s.empty() == true || s.top() == '[') return "no";
			else s.pop();
		}

		else if (str[i] == ']')
		{
			if (s.empty() == true || s.top() == '(') return "no";
			else s.pop();
		}
	}
}

void Solve()
{
	while (1)
	{
		string str;
		getline(cin, str);

		if (str.size() == 1) break;

		cout << IsBalanceStr(str) << "\n";
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	Solve();

	return 0;
}