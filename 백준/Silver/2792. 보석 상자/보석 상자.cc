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
int ans;
int max_jewelry;

bool CanShare(int jealousy)
{
	int shared_child_cnt = 0;

	for(int i = 0; i < v.size(); i++)
	{
		int jeal = v[i];

		int q = jeal / jealousy;
		int r = jeal % jealousy;

		shared_child_cnt += q;
		
		if (r != 0)
			shared_child_cnt++;
	}

	return shared_child_cnt <= N;
}

void Solve()
{
	int low = 1;
	int mid = 0;
	int high = max_jewelry;

	while (low <= high)
	{
		mid = (low + high) / 2;

		if (CanShare(mid) == true)
		{
			high = mid - 1;
			ans = mid;
		}
		else
			low = mid + 1;
	}

	cout << ans;
}

void Input()
{
	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		int x;
		cin >> x;

		v.push_back(x);
		max_jewelry = max(max_jewelry, x);
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