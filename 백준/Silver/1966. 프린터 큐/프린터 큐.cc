#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>
#include <deque>

using namespace std;
queue<pair<int, int>> q;
priority_queue<int> pq;

void Solve(int p)
{
	int count = 0;

	while (1)
	{
		int idx = q.front().first;
		int v = q.front().second;

		q.pop();

		if (pq.top() == v)
		{
			pq.pop();
			count++;
		
			if (idx == p)
			{
				cout << count << endl;
				return;
			}
		}

		else
		{
			q.push({ idx, v });
		}
	}
}

int main()
{
	int t, n, p;
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		cin >> n >> p;

		for (int j = 0; j < n; j++)
		{
			int x;
			cin >> x;

			q.push({j, x});
			pq.push(x);
		}

		Solve(p);

		int size = q.size();

		for (int i = 0; i < size; i++)
		{
			q.pop();
			pq.pop();
		}
	}

	return 0;
}