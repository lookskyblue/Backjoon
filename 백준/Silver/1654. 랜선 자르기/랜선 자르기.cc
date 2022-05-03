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

int K;
long long N;
vector<long long> kv;
long long max_len = 1;

bool IsMoreN(long long value) // 여기도 이분탐색
{
	long long wire_cnt = 0;

	for (int i = 0; i < kv.size(); i++)
		wire_cnt += (kv[i] / value);

	return wire_cnt >= N;
}

void Solve()
{
	long long start = 1;
	//long long end = kv.back();
	long long end = max_len;
	long long mid = 0;

	max_len = 0;

	//if (kv.front() == end)
	//	cout << kv.front();

	//else
	{
		while (start <= end)
		{
			mid = (start + end) / 2;

			int cnt = 0;
			for (int i = 0; i < kv.size(); i++)
				cnt += kv[i] / mid;

			if (cnt >= N)
			{
				max_len = max(max_len, mid);
				start = mid + 1;
			}
			else
				end = mid - 1;
		}

		//if (IsMoreN(end) == true)
		//	max_len = max(max_len, end);

		cout << max_len;
	}
}

void Input()
{
	cin >> K >> N;

	for (int i = 0; i < K; i++)
	{
		long long x;
		cin >> x;

		kv.push_back(x);

		max_len = max(max_len, x);
	}

	//sort(kv.begin(), kv.end());
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