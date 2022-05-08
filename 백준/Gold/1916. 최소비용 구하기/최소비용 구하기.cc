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

int N, M;
int start_city, end_city;
int min_dist[1001];
vector<pair<int, int>> v[1001];

void Solve()
{
	min_dist[start_city] = 0;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	pq.push({ min_dist[start_city], start_city });

	while (pq.empty() == false)
	{
		int current_node = pq.top().second;
		int current_dist = pq.top().first;
		pq.pop();

		if (min_dist[current_node] < current_dist) continue;

		for (int i = 0; i < v[current_node].size(); i++)
		{
			int next_node = v[current_node][i].second;
			int next_dist = v[current_node][i].first;

			if (min_dist[next_node] > current_dist + next_dist)
			{
				min_dist[next_node] = current_dist + next_dist;
				pq.push({ min_dist[next_node], next_node });
			}
		}
	}

	cout << min_dist[end_city];
}

void Input()
{
	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		int A, B, C;
		cin >> A >> B >> C;
		
		v[A].push_back({ C, B });
	}

	cin >> start_city >> end_city;

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