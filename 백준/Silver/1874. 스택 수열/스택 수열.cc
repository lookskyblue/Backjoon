#include <iostream>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>

using namespace std;

void Solve()
{
	int n;
	cin >> n;

	string ans = "";
	stack<int> s;

	int num = 0;
	s.push(num);

	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;

		while (s.top() < x)
		{
			s.push(++num);
			ans += "+";
		}

		if (s.top() == x)
		{
			s.pop();
			ans += "-";
		}

		else if (s.top() > x)
		{
			cout << "NO";
			return;
		}
	}

	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << '\n';
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	Solve();

	return 0;
}
