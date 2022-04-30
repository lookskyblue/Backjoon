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

void BFS(int a, int b)
{
	queue<pair<int, int>> q;
	
	visit[a] = true;

	q.push({ a, 0 });

	while (q.empty() == false)
	{
		pair<int, int> pai = q.front();
		q.pop();

		if (b == pai.first)
		{
			cout << pai.second << '\n';
			return;
		}

		for (int i = 0; i < v[pai.first].size(); i++)
		{
			if (visit[v[pai.first][i].first] == false)
			{
				visit[v[pai.first][i].first] = true;
				pair<int, int> new_pair = { v[pai.first][i].first, v[pai.first][i].second + pai.second };
				q.push(new_pair);
			}
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

		BFS(a, b);
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