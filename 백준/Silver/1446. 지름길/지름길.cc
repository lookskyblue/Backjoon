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
#define INF 987654321;

using namespace std;

int N, D;
int min_dist[10001];
vector<pair<int, int>> edge[10001];
bool visit[10001];

void Solve()
{
	min_dist[0] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ min_dist[0], 0 });

	while (pq.empty() == false)
	{
		int current_node = pq.top().second;
		int current_dist = pq.top().first;

		pq.pop();
		visit[current_node] = true;

		if (min_dist[current_node] < current_dist) continue;

		for (int i = 0; i < edge[current_node].size(); i++)
		{
			int next_node = edge[current_node][i].second;
			int next_dist = edge[current_node][i].first;

			//cout << "NEXT NODE: " << next_node << ", DIST: " << next_dist << '\n';

			if (visit[next_node] == false && min_dist[next_node] > current_dist + next_dist)
			{
				min_dist[next_node] = current_dist + next_dist;
				pq.push({ min_dist[next_node], next_node });
				//visit[next_node] = true;

				//cout << "NEXT NODE: " << next_node << ", DIST: " << current_dist + next_dist << '\n';
			}
		}
	}

	cout << min_dist[D];
}

void Input()
{
	cin >> N >> D;

	for (int i = 0; i < N; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;

		if (b > D) continue;
		if (b - a <= c) continue;

		edge[a].push_back({ c, b });

		if (b <= D)
		{
			int dist = D - b;
			edge[b].push_back({ dist, D });
		}

		if (a <= D)
		{
			for (int j = 0; j < 10001; j++)
			{
				if (a - j > 0)
				{
					int dist = a - j;
					edge[j].push_back({ dist, a });
				}

				else if (a - j < 0)
				{
					int dist = j - a;
					edge[a].push_back({ dist, j });
				}
			}

			int dist = D - a;
			edge[a].push_back({ dist, D });
		}
	}

	for (int i = 0; i < 10001; i++)
		//min_dist[i] = i;
		min_dist[i] = INF;

	min_dist[D] = D;
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