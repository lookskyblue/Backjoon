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

int N, M, ans;
vector<int> v;

bool CheckMoney(int money)
{
	int withdraw_cnt = 1;
	int now_money = money;

	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] <= now_money)
			now_money -= v[i];

		else
		{
			withdraw_cnt++;
			now_money = money;
			i--;

			if (withdraw_cnt > M)
				break;
		}
	}

	return withdraw_cnt > M;
}

void Solve()
{
	int start = 1;
	int mid = 0;
	int end = 1000000000;

	while (start <= end)
	{
		mid = (start + end) / 2;

		if (CheckMoney(mid) == true) // 더 올려
			start = mid + 1;

		else // 더 내려
		{
			ans = mid;
			end = mid - 1;
		}
	}

	cout << ans;
}

void Input()
{
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		int x;
		cin >> x;

		v.push_back(x);
	}

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