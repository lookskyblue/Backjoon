#include <iostream>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>

using namespace std;

int arr[20000000];

void Solve()
{
	int N, M;
	cin >> N;
	
	for (int i = 0; i < N; i++)
	{
		int x;
		cin >> x;

		arr[x + 10000000]++;
	}

	cin >> M;

	for (int i = 0; i < M; i++)
	{
		int x;
		cin >> x;

		cout << arr[x + 10000000] << " ";
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	Solve();

	return 0;
}