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

int n;
bool is_possible = false;

void DFS(int cnt, int sum)
{
	if (is_possible == true) return;
	if (sum > n) return;
	if (cnt == 3)
	{
		if (sum == n) is_possible = true;
		return;
	}

	for (int i = 1; i <= 44; i++)
	{
		int tn = (i * (i + 1)) * 0.5;
		DFS(cnt + 1, sum + tn);
	}
}

void Input()
{
	int T;
	cin >> T;

	while (T--)
	{
		cin >> n;
		DFS(0, 0);
		cout << (is_possible == true ? 1 : 0) << '\n';
		is_possible = false;
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