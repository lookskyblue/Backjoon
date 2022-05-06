#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <cstring>
#include <queue>

#define INF 3000000

using namespace std;

int N, M, K, X;

vector<pair<int, int>> edge[300001];
int min_dist[300001];

void Solve()
{
	min_dist[X] = 0;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ min_dist[X], X });

	while (pq.empty() == false)
	{
		int current_node = pq.top().second;
		int current_dist = pq.top().first;

		pq.pop();

		for (int i = 0; i < edge[current_node].size(); i++)
		{
			int next_node = edge[current_node][i].second;
			int next_dist = edge[current_node][i].first;

			if (min_dist[next_node] > current_dist + next_dist)
			{
				min_dist[next_node] = current_dist + next_dist;
				pq.push({ min_dist[next_node], next_node });
			}
		}
	}

	int ans_cnt = 0;

	for (int i = 1; i <= N; i++)
	{
		if (min_dist[i] == K)
		{
			cout << i << '\n';
			ans_cnt++;
		}
	}

	if (ans_cnt == 0)
		cout << -1;
}

void Input()
{
	cin >> N >> M >> K >> X;

	for (int i = 0; i < M; i++)
	{
		int A, B;
		cin >> A >> B;

		edge[A].push_back({ 1, B });
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
