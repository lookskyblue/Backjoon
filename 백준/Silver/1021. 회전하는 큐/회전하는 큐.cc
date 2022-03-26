#include <iostream>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

void Solve()
{
	int N, M;
	cin >> N >> M;
	vector<int> q, pos;

	for (int i = 0; i < N; i++)
		q.push_back(i + 1);

	for (int i = 0; i < M; i++)
	{
		int x;
		cin >> x;
		pos.push_back(x);
	}

	int count_two_or_three_order = 0;

	for (int i = 0; i < pos.size(); i++)
	{
		int x = pos[i];

		if (q[0] == x)
			q.erase(q.begin());

		else
		{
			int idx = 0;

			for (int j = 0; j < q.size(); j++)
			{
				if (x == q[j])
				{
					idx = j;
					break;
				}
			}

			if (idx <= q.size() / 2)
			{
				while (q[0] != x)
				{
					q.push_back(q[0]);
					q.erase(q.begin());

					count_two_or_three_order++;
				}
				q.erase(q.begin());
			}

			else
			{
				while (q[0] != x)
				{
					q.insert(q.begin(), q[q.size() - 1]);
					//q.erase(q.end());
					q.erase(q.begin() + q.size() - 1);

					count_two_or_three_order++;
				}
				q.erase(q.begin());
			}
		}
	}

	cout << count_two_or_three_order;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	Solve();

	return 0;
}