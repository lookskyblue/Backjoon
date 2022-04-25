#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <vector>

using namespace std;

int N, M;
int m[201][201];
set<int> plain;

bool visit[201];

void Solve()
{
	stack<int> s;
	s.push(*plain.begin());

	while(s.empty() == false)
	{
		int now_city = s.top();
		s.pop();

		if (plain.find(now_city) != plain.end())
		{
			plain.erase(now_city);

			if (plain.empty()== true)
			{
				cout << "YES";
				return;
			}
		}

		for (int i = 1; i <= N; i++)
		{
			if (m[now_city][i] == 1 && visit[i] == false)
			{
				s.push(i);
				visit[i] = true;
			}
		}
	}

	cout << "NO";
}

void Input()
{
	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			int x;
			cin >> x;
			
			m[i][j] = x;
			m[j][i] = x;
		}
	}

	for (int i = 0; i < M; i++)
	{
		int x;
		cin >> x;
		plain.insert(x);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	Input();
	Solve();

	return 0;
}