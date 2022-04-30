#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <vector>
#include <map>
#include <cstring>

using namespace std;

int n, ans;
int num[3] = { 1, 2, 3 };

void DFS(int sum)
{
	if (sum > n) return;
	if (sum == n)
	{
		ans++;
		return;
	}

	for (int i = 0; i < 3; i++)
		DFS(sum + num[i]);
}

void Input()
{
	int T;
	cin >> T;

	while (T--)
	{
		cin >> n;

		DFS(0);
		
		cout << ans << '\n';
		ans = 0;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	Input();

	return 0;
}