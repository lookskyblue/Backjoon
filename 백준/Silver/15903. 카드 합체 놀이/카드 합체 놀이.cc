#include <iostream>
#include <queue>

using namespace std;

priority_queue<long, vector<long>, greater<long>> pq;

void Input()
{
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;

		pq.push(x);
	}

	for (int i = 0; i < m; i++)
	{
		long less_one, less_two;

		less_one = pq.top();
		pq.pop();
		less_two = pq.top();
		pq.pop();

		pq.push(less_one + less_two);
		pq.push(less_one + less_two);
	}

	long sum = 0;

	while (pq.empty() == false)
	{
		sum += pq.top();
		pq.pop();
	}

	cout << sum;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	Input();

	return 0;
}
