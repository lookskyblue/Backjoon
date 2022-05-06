#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <cstring>
#include <queue>

#define INF 3000000

using namespace std;

int V, E, K;
vector<pair<int, int>> edge[20001];
int min_dist[20001];

void Solve()
{
	min_dist[K] = 0;
	priority_queue<pair<int, int>> pq;

	pq.push({ min_dist[K], K });

	while (pq.empty() == false)
	{
		int current_dist = -pq.top().first;
		int current_node = pq.top().second;
		pq.pop();

		if (min_dist[current_node] < current_dist) continue;

		for (int i = 0; i < edge[current_node].size(); i++)
		{
			int next_node = edge[current_node][i].second;
			int next_dist = edge[current_node][i].first;

			if (min_dist[next_node] > next_dist + current_dist)
			{
				min_dist[next_node] = next_dist + current_dist;
				pq.push({ -min_dist[next_node], next_node });
			}
		}
	}

	for (int i = 1; i <= V; i++)
	{
		if (min_dist[i] == INF)
			cout << "INF" << '\n';
		else
			cout << min_dist[i] << '\n';
	}
}

void Input()
{
	cin >> V >> E >> K;

	for (int i = 0; i < E; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;

		edge[u].push_back({ w, v });
	}

	for (int i = 1; i <= V; i++)
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
