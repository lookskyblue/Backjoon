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
#define INF 987654321
#define MAX 100001

using namespace std;

int N, M;
int min_dist[50001];
vector<pair<int, int>> edge[50001];

void Solve()
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0, 1 });
	min_dist[1] = 0;

	while (pq.empty() == false)
	{
		int cur_dist = pq.top().first;
		int cur_node = pq.top().second;
		pq.pop();

		if (min_dist[cur_node] < cur_dist) continue;

		for (int i = 0; i < edge[cur_node].size(); i++)
		{
			int next_dist = edge[cur_node][i].first;
			int next_node = edge[cur_node][i].second;

			if (min_dist[next_node] > cur_dist + next_dist)
			{
				min_dist[next_node] = cur_dist + next_dist;
				pq.push({ min_dist[next_node], next_node });
			}
		}
	}

	cout << min_dist[N];
}

void Input()
{
	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;

		edge[a].push_back({ c, b });
		edge[b].push_back({ c, a });
	}

	for (int i = 1; i <= N; i++)
		min_dist[i] = INF;
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