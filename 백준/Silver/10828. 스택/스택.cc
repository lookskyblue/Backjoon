#include <iostream>
#include <deque>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;


void Solve()
{
	stack<int> s;
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		string order;
		cin >> order;

		if (order == "push")
		{
			int x;
			cin >> x;
			s.push(x);
		}

		else if (order == "pop")
		{
			if (s.empty() == true) cout << -1 << "\n";
			else
			{
				cout << s.top() << "\n";
				s.pop();
			}
		}

		else if (order == "size")
		{
			cout << s.size() << '\n';
		}

		else if (order == "empty")
		{
			cout << s.empty() << '\n';
		}

		else if (order == "top")
		{
			if (s.empty() == true) cout << -1 << '\n';
			else cout << s.top() << '\n';
		}
	}
}

int main()
{
	Solve();

	return 0;
}