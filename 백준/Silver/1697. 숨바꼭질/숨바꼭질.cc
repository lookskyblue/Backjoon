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

int N, K;
int dist[MAX];

int min_time = INF;
int min_time_count;

void Solve()
{
	dist[N] = 0;
	queue<int> s;
	s.push(N);

	while (s.empty() == false)
	{
		int cur_x = s.front();
		s.pop();

		int one_step_back = cur_x - 1;
		int one_step_forward = cur_x + 1;
		int	teleport = cur_x * 2;

		if (0 <= one_step_back && (dist[one_step_back] > dist[cur_x] + 1))
		{
			dist[one_step_back] = dist[cur_x] + 1;
			s.push(one_step_back);
		}

		if (one_step_forward < MAX && (dist[one_step_forward] > dist[cur_x] + 1))
		{
			dist[one_step_forward] = dist[cur_x] + 1;
			s.push(one_step_forward);
		}

		if (teleport < MAX && (dist[teleport] > dist[cur_x] + 1))
		{
			dist[teleport] = dist[cur_x] + 1;
			s.push(teleport);
		}
	}

	cout << dist[K];
}

void Input()
{
	cin >> N >> K;

	for (int i = 0; i < MAX; i++)
		dist[i] = INF;
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