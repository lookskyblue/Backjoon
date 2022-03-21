#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

int N;
queue<int> q;

void Input()
{
	cin >> N;

	for (int i = 1; i <= N; i++)
		q.push(i);
}

void Solve()
{
	while (q.size() != 1)
	{
		q.pop();
		q.push(q.front());
		q.pop();
	}

	cout << q.front();
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	Input();
	Solve();

	return 0;
}