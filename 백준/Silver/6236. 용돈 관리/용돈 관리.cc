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

int low, high;

bool CheckMoney(int mid)
{
	int now_money = mid;
	int cnt = 1;

	for (int i = 0; i < v.size(); i++)
	{
		if (now_money < v[i])
		{
			now_money = mid;
			cnt++;
		}

		now_money -= v[i];
	}

	return cnt > M;
}

void Solve()
{
	int mid = 0;

	while (low <= high)
	{
		mid = (low + high) / 2;

		bool need_more_money = CheckMoney(mid);

		if (need_more_money == true) // 더 올려
		{
			low = mid + 1;
			ans = mid;
		}

		else
			high = mid - 1;
	}

	cout << mid;
}

void Input()
{
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		int x;
		cin >> x;

		v.push_back(x);

		low = max(low, x);
		high += x;
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