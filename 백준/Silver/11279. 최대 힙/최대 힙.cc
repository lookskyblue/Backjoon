#include <iostream>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <string>
#include <set>

using namespace std;

void Solve()
{
	priority_queue<int> pq;
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int x;
		cin >> x;

		if (x != 0)
		{
			pq.push(x);
		}

		else
		{
			if (pq.empty() == true) cout << "0" << '\n';
			else
			{
				cout << pq.top() << "\n";
				pq.pop();
			}
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