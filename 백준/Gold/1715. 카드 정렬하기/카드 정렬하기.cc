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

priority_queue<int, vector<int>, greater<int>> pq;

void Solve()
{
	int ans = 0;

	while (pq.size() != 1)
	{
		int a = pq.top();
		pq.pop();
		int b = pq.top();
		pq.pop();

		pq.push(a + b);

		ans += a + b;
	}

	cout << ans;
}

void Input()
{
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int x;
		cin >> x;

		pq.push(x);
	}

	Solve();
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	Input();

	return 0;
}