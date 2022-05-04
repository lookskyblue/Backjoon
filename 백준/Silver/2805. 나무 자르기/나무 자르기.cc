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

long long N, M;
vector<int> v;
int max_tree_height;
int ans;

void Solve()
{
	int start = 0;
	int mid = 0;
	int end = max_tree_height - 1;

	while (start <= end)
	{
		mid = (start + end) / 2;

		long long earned_tree_height = 0;

		for (int i = 0; i < v.size(); i++)
		{
			if (v[i] > mid)
				earned_tree_height += (v[i] - mid);
		}

		if (earned_tree_height >= M)
		{
			start = mid + 1;
			ans = max(ans, mid);
		}

		else
			end = mid - 1;
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
		max_tree_height = max(max_tree_height, x);
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