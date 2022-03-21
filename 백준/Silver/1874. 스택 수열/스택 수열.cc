#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

int N, K;
int arr[100000];
string ans;

void Solve()
{
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	int x = 1;
	int idx = 0;
	stack<int> s;
	
	s.push(x);
	ans += "+";

	while (1)
	{
		if (s.top() == arr[idx])
		{
			ans += "-";
			s.pop();

			if (++idx == N) break;
		}

		if (s.empty() == true)
		{
			ans += "+";
			s.push(++x);
		}

		if (s.top() < arr[idx])
		{
			s.push(++x);
			ans += "+";
		}

		else if (s.top() > arr[idx])
		{
			cout << "NO";
			return;
		}
	}

	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << '\n';
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	Solve();

	return 0;
}