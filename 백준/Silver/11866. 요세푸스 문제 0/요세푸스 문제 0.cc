#include <iostream>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>

using namespace std;

void Solve()
{
	int N, K;
	cin >> N >> K;

	queue<int> q;

	for (int i = 1; i <= N; i++)
		q.push(i);

	cout << "<";

	while (q.empty() == false)
	{
		for (int i = 0; i < K - 1; i++)
		{
			q.push(q.front());
			q.pop();
		}

		cout << q.front();
		
		if (q.size() != 1)
			cout << ", ";
		
		q.pop();
	}

	cout << ">";
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	Solve();

	return 0;
}