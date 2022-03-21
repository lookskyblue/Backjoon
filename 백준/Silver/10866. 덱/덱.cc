#include <iostream>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>

using namespace std;

int N;
deque<int> dq;

void Solve()
{
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		string order;
		cin >> order;

		if (order == "push_back")
		{
			int x;
			cin >> x;
			dq.push_back(x);
		}

		else if (order == "push_front")
		{
			int x;
			cin >> x;
			dq.push_front(x);
		}

		else if (order == "pop_front")
		{
			if (dq.empty() == true) cout << "-1" << '\n';
			else
			{
				cout << dq.front() << '\n';
				dq.pop_front();
			}
		}

		else if (order == "pop_back")
		{
			if (dq.empty() == true) cout << "-1" << '\n';
			else
			{
				cout << dq.back() << '\n';
				dq.pop_back();
			}
		}

		else if (order == "size") cout << dq.size() << '\n';
		else if (order == "empty") cout << dq.empty() << '\n';
		else if (order == "front")
		{
			if (dq.empty() == true) cout << "-1" << '\n';
			else cout << dq.front() << '\n';
		}

		else if (order == "back")
		{
			if (dq.empty() == true) cout << "-1" << '\n';
			else cout << dq.back() << '\n';
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	Solve();

	return 0;
}