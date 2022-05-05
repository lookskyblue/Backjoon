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

vector<int> bottom, top;
int N, H;
int lowest = 200001;
int cnt = 0;

void Solve()
{
	sort(bottom.begin(), bottom.end());
	sort(top.begin(), top.end());

	for (int i = 1; i <= H; i++)
	{
		int bottom_idx = lower_bound(bottom.begin(), bottom.end(), i) - bottom.begin();
		int top_idx = lower_bound(top.begin(), top.end(), H - i + 1) - top.begin();
		int cur = N - (bottom_idx + top_idx);

		if (lowest == cur)
			cnt++;

		else if (cur < lowest)
		{
			lowest = cur;
			cnt = 1;
		}
	}

	cout << lowest << " " << cnt;
}

void Input()
{
	cin >> N >> H;

	for (int i = 0; i < N / 2; i++)
	{
		int a, b;
		cin >> a >> b;

		bottom.push_back(a);
		top.push_back(b);
	}

	return;

	while(N)
	{
		N -= 2;

		int x, y;
		cin >> x >> y;

		bottom.push_back(x);
		top.push_back(y);
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