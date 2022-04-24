#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <vector>

using namespace std;

stack<pair<int, int>> s;

void Input()
{
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int x;
		cin >> x;

		if (s.empty() == true)
		{
			s.push({ x, i + 1 });
			cout << 0 << ' ';
		}

		else
		{
			if (s.top().first > x)
			{
				cout << s.top().second << ' ';
				s.push({ x, i + 1 });
			}

			else
			{
				bool is_find = false;

				while (s.empty() == false)
				{
					if (s.top().first <= x)
						s.pop();

					else
					{
						is_find = true;
						cout << s.top().second << ' ';
						s.push({ x, i + 1 });
						break;
					}
				}

				if (is_find == false)
				{
					cout << 0 << ' ';
					s.push({ x, i + 1 });
				}
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	Input();

	return 0;
}