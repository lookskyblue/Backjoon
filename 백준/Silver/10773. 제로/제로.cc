#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

void Solve()
{
	stack<int> s;

	int K;
	cin >> K;

	for (int i = 0; i < K; i++)
	{
		int val;
		cin >> val;

		if (val == 0) s.pop();
		else s.push(val);
	}

	int sum = 0;

	while (s.empty() == false)
	{
		sum += s.top();
		s.pop();
	}

	cout << sum;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	Solve();

	return 0;
}