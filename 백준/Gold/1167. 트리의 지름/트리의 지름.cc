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
	if (visit[start] == true) return;
	visit[start] = true;

	if (max_len < len)
	{
		max_len = len;
		long_node_idx = start;
	}

	for (int i = 0; i < v[start].size(); i++)
			DFS(v[start][i].first, len + v[start][i].second);
}

void Input()
{
	int V;
	cin >> V;

	for (int i = 0; i < V; i++)
	{
		int a, b, c;
		cin >> a >> b;

		while (b != -1)
		{
			cin >> c;

			v[a].push_back({ b, c });
			v[b].push_back({ a, c });

			cin >> b;
		}
	}
}

void Solve()
{
	DFS(1, 0);

	memset(visit, false, sizeof(visit));
	max_len = 0;

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