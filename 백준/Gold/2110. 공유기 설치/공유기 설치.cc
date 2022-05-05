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

int N, C, max_len_home;
vector<int> v;
int ans;

bool CanAllWifi(int mid)
{
	int wifi_cnt = 1;
	int before_home = v[0];

	for (int i = 1; i < v.size(); i++)
	{
		if (v[i] - before_home >= mid)
		{
			wifi_cnt++;
			before_home = v[i];
		}
	}

	return wifi_cnt >= C;
}

void Solve()
{
	sort(v.begin(), v.end());

	int low = 1;
	int mid = 0;
	int high = max_len_home - 1;

	while (low <= high)
	{
		mid = (low + high) / 2;
		//cout << "MID: " << mid << '\n';

		if (CanAllWifi(mid) == true)
		{
			//cout << " Can!" << '\n';
			low = mid + 1;
			ans = mid;
		}

		else
		{
			//cout << " Can Not!" << '\n';
			high = mid - 1;
		}
	}

	cout << ans;
}

void Input()
{
	cin >> N >> C;

	for (int i = 0; i < N; i++)
	{
		int x;
		cin >> x;

		v.push_back(x);

		max_len_home = max(max_len_home, x);
	}

}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	Input();
	Solve();

	return 0;
}