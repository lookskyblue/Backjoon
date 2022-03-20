#include <iostream>
#include <deque>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

int N[100000];

int BinarySearch(int left, int right, int value)
{
	if (N[left] == value) return 1;
	if (N[right] == value) return 1;

	int mid = (left + right) / 2;
	
	if (N[mid] == value) return 1;

	if (left == right) return 0;

	int is_any = 0;

	if (value < N[mid])		 is_any += BinarySearch(left, mid, value);
	else if (N[mid] < value) is_any += BinarySearch(mid + 1, right, value);

	return is_any;
}

void Solve()
{
	int n, m;
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> N[i];

	sort(N, N + n);
	cin >> m;

	for (int i = 0; i < m; i++)
	{
		int x;
		cin >> x;

		cout << BinarySearch(0, n - 1, x) << '\n';
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	Solve();

	return 0;
}