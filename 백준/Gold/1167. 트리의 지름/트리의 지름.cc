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

vector<pair<int, int>> v[100001];
bool visit[100001];

int long_node_idx;
int max_len;

void DFS(int start, int len)
{
	if (max_len < len)
	{
		max_len = len;
		long_node_idx = start;
	}

	for (int i = 0; i < v[start].size(); i++)
	{
		if (visit[v[start][i].first] == false)
		{
			visit[v[start][i].first] = true;
			DFS(v[start][i].first, len + v[start][i].second);
			visit[v[start][i].first] = false;
		}
	}
}

void Input()
{
	map<int, set<int>> m;
	int V;
	cin >> V;

	for (int i = 0; i < V; i++)
	{
		int a, b, c;
		cin >> a >> b;

		while (b != -1)
		{
			cin >> c;

			if (m.find(a) == m.end())
			{
				set<int> bs, as;
				bs.insert(b);
				as.insert(a);

				m.insert({ a, bs });
				m.insert({ b, as });

				v[a].push_back({ b, c });
				v[b].push_back({ a, c });
			}

			else if (m[a].find(b) == m[a].end())
			{
				m[a].insert(b);
				m[b].insert(a);

				v[a].push_back({ b, c });
				v[b].push_back({ a, c });
			}

			cin >> b;
		}
	}
}

void Solve()
{
	visit[1] = true;
	DFS(1, 0);

	memset(visit, false, sizeof(visit));
	max_len = 0;

	visit[long_node_idx] = true;
	DFS(long_node_idx, 0);

	cout << max_len;
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