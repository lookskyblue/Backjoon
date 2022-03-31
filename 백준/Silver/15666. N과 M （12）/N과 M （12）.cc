#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <deque>
#include <stack>
#include <map>

using namespace std;

int N, M;
vector<int> v;
int selected[8];

void DFS(int idx, int cnt)
{
	if (cnt == M)
	{
		for (int i = 0; i < cnt; i++)
			cout << selected[i] << " ";

		cout << "\n";

		return;
	}

	int before = 0;

	for (int i = idx; i < N; i++)
	{
		if (before == v[i]) continue;

		selected[cnt] = v[i];
		before = selected[cnt];

		DFS(i, cnt + 1);
	}
}

void Solve()
{
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		int x;
		cin >> x;
		v.push_back(x);
	}

	sort(v.begin(), v.end());

	DFS(0, 0);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	Solve();

	return 0;
}