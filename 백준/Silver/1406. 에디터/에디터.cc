#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <list>
#include <stack>

using namespace std;

void Solve()
{
	stack<char> left, right;
	string str;
	int M;

	cin >> str >> M;

	for (int i = 0; i < str.size(); i++)
		left.push(str[i]);

	for (int i = 0; i < M; i++)
	{
		char order;
		cin >> order;

		if (order == 'L')
		{
			if (left.empty() == false)
			{
				right.push(left.top());
				left.pop();
			}
		}

		else if (order == 'D')
		{
			if (right.empty() == false)
			{
				left.push(right.top());
				right.pop();
			}
		}

		else if (order == 'B')
		{
			if (left.empty() == false)
				left.pop();
		}

		else if (order == 'P')
		{
			char alpha;
			cin >> alpha;

			left.push(alpha);
		}
	}

	while (left.empty() == false)
	{
		right.push(left.top());
		left.pop();
	}

	while (right.empty() == false)
	{
		cout << right.top();
		right.pop();
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	Solve();

	return 0;
}