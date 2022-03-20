#include <iostream>
#include <deque>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

string IsVPS(string ps)
{
	stack<char> s;

	for (int i = 0; i < ps.size(); i++)
	{
		if (ps[i] == '(') s.push(ps[i]);
		else
		{
			if (s.empty() == true) return "NO";
			else s.pop();
		}
	}

	if (s.empty() == false) return "NO";
	return "YES";
}

void Solve()
{
	int T;
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		string ps;
		cin >> ps;

		cout << IsVPS(ps) << '\n';
	}
}

int main()
{
	Solve();

	return 0;
}