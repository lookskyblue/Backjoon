#include <iostream>
#include <deque>
#include <queue>
#include <algorithm>

using namespace std;

int const MAX_SIZE = 10000;
int stack[MAX_SIZE];
int point = -1;

void Solve()
{
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

			stack[++point] = x;
		}

		else if (order == "pop")
		{
			if (point == -1) cout << -1 << '\n';
			else
			{
				int top_value = stack[point--];
				cout << top_value << '\n';
			}
		}

		else if (order == "size")
		{
			cout << point + 1 << '\n';
		}

		else if (order == "empty")
		{
			if (point == -1) cout << 1 << '\n';
			else cout << 0 << '\n';
		}

		else if (order == "top")
		{
			if (point == -1) cout << -1 << '\n';
			else cout << stack[point] << '\n';
		}
	}
}

int main()
{
	Solve();

	return 0;
}