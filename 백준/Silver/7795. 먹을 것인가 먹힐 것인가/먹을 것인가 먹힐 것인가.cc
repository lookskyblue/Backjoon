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
vector<int> nv, mv;

void Solve()
{
	sort(mv.begin(), mv.end());

	int ans = 0;

	for (int i = 0; i < nv.size(); i++)
	{
		int start = 0;
		int mid = 0;
		int end = mv.size();

		while (start < end)
		{
			mid = (start + end) / 2;

			if (mv[mid] < nv[i])
				start = mid + 1;
			else
				end = mid;
		}

		ans += start;
	}

	cout << ans << '\n';
}

void Input()
{
	int T;
	cin >> T;

	while (T--)
	{
		cin >> N >> M;

		for (int i = 0; i < N; i++)
		{
			int x;
			cin >> x;

			nv.push_back(x);
		}

		for (int i = 0; i < M; i++)
		{
			int x;
			cin >> x;

			mv.push_back(x);
		}

		Solve();

		nv.clear();
		mv.clear();
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