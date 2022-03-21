#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

int N, K;
int arr[100000];
queue<string> op;

void Solve()
{
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) cin >> arr[i];

	int x = 1;
	int idx = 0;
	stack<int> s;
	
	s.push(x);
	op.push("+");

	while (1)
	{
		if (s.top() == arr[idx])
		{
			op.push("-");
			s.pop();

			if (++idx == N) break;
		}

		if (s.empty() == true)
		{
			op.push("+");
			s.push(++x);
		}

		if (s.top() < arr[idx])
		{
			s.push(++x);
			op.push("+");
		}

		if (s.top() > arr[idx])
		{
			cout << "NO";
			return;
		}
	}

	int size = op.size();

	for (int i = 0; i < size; i++, op.pop())
		cout << op.front() << '\n';
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	Solve();

	return 0;
}