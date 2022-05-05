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

int N, M;
vector<int> v;
int ans = 1000000001;

int loop_cnt;

bool CheckMoney(int money)
{
	//cout << "look cnt: " << ++loop_cnt << ", money: " << money << '\n';
	//if (money == 500) cout << "Money: " << 500 << '\n';

	int withdraw_cnt = 1;
	int now_money = money;
	int i = 0;

	for (; i < v.size(); i++)
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

		bool check_state = CheckMoney(mid);

		if (check_state == true) // 더 올려
		{
			start = mid + 1;
		}

		else
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