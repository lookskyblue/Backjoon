#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;
int const MAX = 10000;
int q[MAX];
int front = 0;
int rear = 0;

void Solve()
{
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		string order;
		cin >> order;

		if (order == "push")
		{
			int x;

			cin >> x;
			q[(++rear) % MAX] = x;
		}

		else if (order == "pop")
		{
			if (front == rear) cout << "-1" << '\n';
			else
			{
				cout << q[(++front) % MAX] << '\n';
			}
		}

		else if (order == "size")
		{
			if (front == rear) cout << 0 << '\n';

			else
			{
				int size = 0;
				int maxi = front < rear ? rear : rear + MAX;

				for (int j = front + 1; j <= maxi; j++) size++;

				cout << size << '\n';
			}
		}

		else if (order == "empty")
		{
			cout << (front == rear) << '\n';
		}

		else if (order == "front")
		{
			if (front == rear) cout << "-1" << '\n';
			else cout << q[front + 1] << '\n';
		}

		else if (order == "back")
		{
			if (front == rear) cout << "-1" << '\n';
			else cout << q[rear] << '\n';
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