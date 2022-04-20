#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <deque>
#include <stack>
#include <map>

using namespace std;

void Input()
{
	priority_queue<int, vector<int>, greater<int>> pq;

	int N;
	cin >> N;

	for (int i = 0; i < N * N; i++)
	{
		int x;
		cin >> x;

		if (pq.size() < N)
			pq.push(x);

		else
		{
			if (pq.top() < x)
			{
				pq.pop();
				pq.push(x);
			}
		}
	}

	cout << pq.top();
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	Input();

	return 0;
}