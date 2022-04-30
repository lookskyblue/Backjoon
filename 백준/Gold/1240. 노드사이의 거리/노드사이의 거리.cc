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

vector<pair<int, int>> v[1001];
bool visit[1001];

void DFS(int a, int b, int len)
{
	if (a == b)
	{
		cout << len << '\n';
		return;
	}

	for (int i = 0; i < v[a].size(); i++)
	{
		if (visit[v[a][i].first] == false)
		{
			visit[v[a][i].first] = true;
			DFS(v[a][i].first, b, len + v[a][i].second);
			visit[v[a][i].first] = false;
		}
	}
}

void Input()
{
	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N - 1; i++)
	{
		int a, b, len;
		cin >> a >> b >> len;

		v[a].push_back({b, len});
		v[b].push_back({a, len});
	}

	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;

		visit[a] = true;
		DFS(a, b, 0);
		memset(visit, false, sizeof(visit));
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