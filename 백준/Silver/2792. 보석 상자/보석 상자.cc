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
priority_queue<int> pq;
int ans;

bool CanShare(int jealousy)
{
	priority_queue<int> copy_pq = pq;
	int shared_child_cnt = 0;

	while (copy_pq.empty() == false)
	{
		int jeal = copy_pq.top();
		copy_pq.pop();

		int q = jeal / jealousy;
		int r = jeal % jealousy;

		shared_child_cnt += q;
		
		if (r != 0)
			shared_child_cnt++;

		if (shared_child_cnt > N)
			return false;
	}

	return true;
}

void Solve()
{
	int low = 1;
	int mid = 0;
	int high = pq.top();

	while (low <= high)
	{
		mid = (low + high) / 2;
		//cout << "MID: " << mid << '\n';

		if (CanShare(mid) == true)
		{
			//cout << "Can Share!" << '\n';
			high = mid - 1;
			ans = mid;
		}
		else
		{
			//cout << "Can Not Share!" << '\n';
			low = mid + 1;
		}
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

		pq.push(x);
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