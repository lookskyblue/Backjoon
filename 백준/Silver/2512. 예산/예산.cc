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

vector<int> v;
int my_money;
int total_need_money;
int max_need_money;
int ans;

bool CheckPossibleMoney(int limit_money)
{
	int copy_my_money = my_money;

	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] < limit_money)
			copy_my_money -= v[i];
		else
			copy_my_money -= limit_money;
	}

	return copy_my_money >= 0;
}

void Solve()
{
	int start = 1;
	int mid = 0;
	int end = max_need_money;

	while (start <= end)
	{
		mid = (start + end) / 2;

		bool is_possible_money = CheckPossibleMoney(mid);

		if (is_possible_money)
		{
			ans = max(ans, mid);
			start = mid + 1;
		}
		else
			end = mid - 1;
	}

	cout << ans;
}

void Input()
{
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int x;
		cin >> x;

		v.push_back(x);

		total_need_money += x;
		max_need_money = max(max_need_money, x);
	}

	cin >> my_money;

	Solve();
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	Input();

	return 0;
}