#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <cstring>

using namespace std;

int from_factory, to_factory;
int N, M;
int ans;
vector<pair<int, int>> v[10001];
bool visit[10001];

bool DFS(int max_weight)
{
	stack<int> s;
	s.push(from_factory);
	visit[from_factory] = true;

	while (s.empty() == false)
	{
		int pos = s.top();
		s.pop();

		if (pos == to_factory) return true;

		for (int i = 0; i < v[pos].size(); i++)
		{
			if (visit[v[pos][i].first] == false && v[pos][i].second >= max_weight)
			{
				visit[v[pos][i].first] = true;
				s.push(v[pos][i].first);
			}
		}
	}

	return false;
}

void Solve()
{
	int low = 1;
	int high = 1000000000;

	while (low <= high)
	{
		int mid = (low + high) / 2;

		if (DFS(mid) == true)
		{
			low = mid + 1;
			ans = max(ans, mid);
		}

		else
			high = mid - 1;

		memset(visit, false, sizeof(visit));
	}

	cout << ans;
}

void Input()
{
	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;

		v[a].push_back({b, c});
		v[b].push_back({a, c});
	}

	cin >> from_factory >> to_factory;
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
